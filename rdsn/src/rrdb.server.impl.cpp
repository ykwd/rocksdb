# include "rrdb.server.impl.h"

# include <fstream>
# include <sstream>

namespace dsn
{
    namespace apps
    {
        rrdb_service_impl::rrdb_service_impl()
            : _lock(true)
        {
            _is_open = false;
            _app_info = nullptr;

            // init db options
            _db_opts.write_buffer_size =
                (size_t)dsn_config_get_value_uint64("replication",
                    "rocksdb_write_buffer_size",
                    (64 << 20),
                    "rocksdb options.write_buffer_size, default 128MB"
                    );
            _db_opts.max_write_buffer_number =
                (int)dsn_config_get_value_uint64("replication",
                    "rocksdb_max_write_buffer_number",
                    3,
                    "rocksdb options.max_write_buffer_number, default 3"
                    );
            _db_opts.max_background_compactions =
                (int)dsn_config_get_value_uint64("replication",
                    "rocksdb_max_background_compactions",
                    20,
                    "rocksdb options.max_background_compactions, default 20"
                    );
            _db_opts.num_levels =
                dsn_config_get_value_uint64("replication",
                    "rocksdb_num_levels",
                    6,
                    "rocksdb options.num_levels, default 6"
                    );
            _db_opts.target_file_size_base =
                dsn_config_get_value_uint64("replication",
                    "rocksdb_target_file_size_base",
                    67108864,
                    "rocksdb options.write_buffer_size, default 64MB"
                    );
            _db_opts.max_bytes_for_level_base =
                dsn_config_get_value_uint64("replication",
                    "rocksdb_max_bytes_for_level_base",
                    10485760,
                    "rocksdb options.max_bytes_for_level_base, default 10MB"
                    );
            _db_opts.max_grandparent_overlap_factor =
                (int)dsn_config_get_value_uint64("replication",
                    "rocksdb_max_grandparent_overlap_factor",
                    10,
                    "rocksdb options.max_grandparent_overlap_factor, default 10"
                    );
            _db_opts.level0_file_num_compaction_trigger =
                (int)dsn_config_get_value_uint64("replication",
                    "rocksdb_level0_file_num_compaction_trigger",
                    4,
                    "rocksdb options.level0_file_num_compaction_trigger, 4"
                    );
            _db_opts.level0_slowdown_writes_trigger =
                (int)dsn_config_get_value_uint64("replication",
                    "rocksdb_level0_slowdown_writes_trigger",
                    8,
                    "rocksdb options.level0_slowdown_writes_trigger, default 8"
                    );
            _db_opts.level0_stop_writes_trigger =
                (int)dsn_config_get_value_uint64("replication",
                    "rocksdb_level0_stop_writes_trigger",
                    12,
                    "rocksdb options.level0_stop_writes_trigger, default 12"
                    );

            // disable write ahead logging as replication handles logging instead now
            _wt_opts.disableWAL = true;

        }

        void rrdb_service_impl::put_internal(const put_req& req, put_resp& resp)
        {
            rocksdb::Slice skey(req.key);
            rocksdb::Slice svalue(req.value);

            auto status = _db->Put(_wt_opts, skey, svalue);
            if (!status.ok())
            {
                derror("%s failed, status = %s", __FUNCTION__, status.ToString().c_str());
            }
            resp.err = status.code();
        }

        void rrdb_service_impl::get_internal(const get_req& req, get_resp& resp)
        {
            rocksdb::Slice skey(req.key);
            rocksdb::Status status = _db->Get(_rd_opts, skey, &resp.value);
            if (!status.ok() && !status.IsNotFound())
            {
                derror("%s failed, status = %s", __FUNCTION__, status.ToString().c_str());
            }
            resp.err = status.code();
        }

        void rrdb_service_impl::remove_internal(const remove_req& req, remove_resp& resp)
        {
            rocksdb::Slice skey(req.key);
            rocksdb::Status status = _db->Delete(_wt_opts, skey);
            if (!status.ok() && !status.IsNotFound())
            {
                derror("%s failed, status = %s", __FUNCTION__, status.ToString().c_str());
            }
            resp.err = status.code();
        }

        void rrdb_service_impl::on_put(const put_req& args, ::dsn::rpc_replier< put_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());
            put_resp resp;
            put_internal(args, resp);
            reply(resp);

        }

        void rrdb_service_impl::on_get(const get_req& args, ::dsn::rpc_replier< get_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());
            get_resp resp;
            get_internal(args, resp);
            reply(resp);
        }

        void rrdb_service_impl::on_remove(const remove_req& args, ::dsn::rpc_replier< remove_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());
            remove_resp resp;
            remove_internal(args, resp);
            reply(resp);
        }

        // RPC_RRDB_RRDB_BATCH_PUT 
        void rrdb_service_impl::on_batch_put(const batch_put_req& args, ::dsn::rpc_replier< batch_put_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());
            batch_put_resp resps;
            for (auto& req : args.reqs)
            {
                put_resp resp;
                put_internal(req, resp);
                resps.resps.push_back(resp);
            }
            reply(resps);
        }

        // RPC_RRDB_RRDB_BATCH_GET 
        void rrdb_service_impl::on_batch_get(const batch_get_req& args, ::dsn::rpc_replier< batch_get_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());
            batch_get_resp resps;
            for (auto& req : args.reqs)
            {
                get_resp resp;
                get_internal(req, resp);
                resps.resps.push_back(resp);
            }
            reply(resps);
        }

        // RPC_RRDB_RRDB_BATCH_REMOVE 
        void rrdb_service_impl::on_batch_remove(const batch_remove_req& args, ::dsn::rpc_replier< batch_remove_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());
            batch_remove_resp resps;
            for (auto& req : args.reqs)
            {
                remove_resp resp;
                remove_internal(req, resp);
                resps.resps.push_back(resp);
            }
            reply(resps);
        }

        ::dsn::error_code rrdb_service_impl::start(int argc, char** argv)
        {
            dassert(!_is_open, "rrdb service %s is already opened", data_dir());

            _app_info = dsn_get_app_info_ptr(gpid());

            rocksdb::Status status;
            {
                ::dsn::service::zauto_lock l(_lock);

                rocksdb::Options opts = _db_opts;
                opts.create_if_missing = true;
                opts.error_if_exists = false;
                auto path = utils::filesystem::path_combine(data_dir(), "rdb");
                status = rocksdb::DB::Open(opts, path, &_db);
            }

            if (status.ok())
            {
                _is_open = true;
                open_service(gpid());

                return ERR_OK;
            }
            else
            {
                derror("open rocksdb failed, status = %s",
                    status.ToString().c_str()
                    );
                return ERR_LOCAL_APP_FAILURE;
            }
        }

        ::dsn::error_code rrdb_service_impl::stop(bool clear_state)
        {
            close_service(gpid());

            {
                ::dsn::service::zauto_lock l(_lock);

                if (!_is_open)
                {
                    dassert(_db == nullptr, "");
                    dassert(!clear_state, "should not be here if do clear");
                    return ERR_OK;

                }

                _is_open = false;
                delete _db;
                _db = nullptr;

                if (clear_state)
                {
                    if (!dsn::utils::filesystem::remove_path(data_dir()))
                    {
                        dassert(false, "Fail to delete directory %s.", data_dir());
                    }
                }
            }
            return ERR_OK;
        }

        void rrdb_service_impl::recover()
        {
            dsn::service::zauto_lock l(_lock);

            int64_t maxVersion = 0;
            std::string name;

            std::vector<std::string> sub_list;
            std::string path = data_dir();
            if (!dsn::utils::filesystem::get_subfiles(path, sub_list, false))
            {
                dassert(false, "Fail to get subfiles in %s.", path.c_str());
            }
            for (auto& fpath : sub_list)
            {
                auto&& s = dsn::utils::filesystem::get_file_name(fpath);
                if (s.substr(0, strlen("checkpoint.")) != std::string("checkpoint."))
                    continue;

                int64_t version = static_cast<int64_t>(atoll(s.substr(strlen("checkpoint.")).c_str()));
                if (version > maxVersion)
                {
                    maxVersion = version;
                    name = std::string(data_dir()) + "/" + s;
                }
            }
            sub_list.clear();

            if (maxVersion > 0)
            {
                recover(name, maxVersion);
                set_last_durable_decree(maxVersion);
            }
        }

        void rrdb_service_impl::recover(const std::string& name, int64_t version)
        {
            dsn::service::zauto_lock l(_lock);

            std::ifstream is(name.c_str(), std::ios::binary);
            if (!is.is_open())
                return;

            int magic;

            is.read((char*)&magic, sizeof(magic));
            dassert(magic == 0xdeadbeef, "invalid checkpoint");

            for (; !is.eof(); )
            {
                std::string key;
                std::string value;

                uint32_t sz;
                is.read((char*)&sz, (uint32_t)sizeof(sz));
                key.resize(sz);

                is.read((char*)&key[0], sz);

                is.read((char*)&sz, (uint32_t)sizeof(sz));
                value.resize(sz);

                is.read((char*)&value[0], sz);

                auto status = _db->Put(_wt_opts, key, value);
                dassert(status.ok(), "fail to insert data to database during recovery");
            }
            is.close();
        }

        ::dsn::error_code rrdb_service_impl::checkpoint()
        {
            ::dsn::service::zauto_lock l(_lock);

            if (last_committed_decree() == last_durable_decree())
            {
                return ERR_OK;
            }

            char name[256];
            sprintf(name, "%s/checkpoint.%" PRId64, data_dir(),
                last_committed_decree()
                );
            std::ofstream os(name, std::ios::binary);

            int magic = 0xdeadbeef;
            os.write((const char*)&magic, (uint32_t)sizeof(magic));

            uint64_t counter = 0;
            rocksdb::Iterator* it = _db->NewIterator(rocksdb::ReadOptions());
            for (it->SeekToFirst(); it->Valid(); it->Next()) {
                std::string key = it->key().ToString();
                std::string value = it->value().ToString();
                uint32_t sz = key.length();
                os.write((const char*)&sz, (uint32_t)sizeof(sz));
                os.write(key.c_str(), sz);
                sz = value.length();
                os.write((const char*)&sz, (uint32_t)sizeof(sz));
                os.write(value.c_str(), sz);
            }
            assert(it->status().ok()); // Check for any errors found during the scan
            delete it;

            os.close();
            std::cout << "add checkpoint to " << std::string(name) << std::endl;
            set_last_durable_decree(last_committed_decree());
            return ERR_OK;
        }

        ::dsn::error_code rrdb_service_impl::get_checkpoint(
            int64_t start,
            void*   learn_request,
            int     learn_request_size,
            /* inout */ app_learn_state& state
            )
        {
            if (last_durable_decree() > 0)
            {
                char name[256];
                sprintf(name, "%s/checkpoint.%" PRId64,
                    data_dir(),
                    last_durable_decree()
                    );

                state.from_decree_excluded = 0;
                state.to_decree_included = last_durable_decree();
                state.files.push_back(std::string(name));

                return ERR_OK;
            }
            else
            {
                state.from_decree_excluded = 0;
                state.to_decree_included = 0;
                return ERR_OBJECT_NOT_FOUND;
            }
        }

        ::dsn::error_code rrdb_service_impl::apply_checkpoint(const dsn_app_learn_state& state, dsn_chkpt_apply_mode mode)
        {
            if (mode == DSN_CHKPT_LEARN)
            {
                recover(state.files[0], state.to_decree_included);
                return ERR_OK;
            }
            else
            {
                dassert(DSN_CHKPT_COPY == mode, "invalid mode %d", (int)mode);
                dassert(state.to_decree_included > last_durable_decree(), "checkpoint's decree is smaller than current");

                char name[256];
                sprintf(name, "%s/checkpoint.%" PRId64,
                    data_dir(),
                    state.to_decree_included
                    );
                std::string lname(name);

                if (!utils::filesystem::rename_path(state.files[0], lname))
                    return ERR_CHECKPOINT_FAILED;
                else
                {
                    set_last_durable_decree(state.to_decree_included);
                    return ERR_OK;
                }
            }
        }
    }
}