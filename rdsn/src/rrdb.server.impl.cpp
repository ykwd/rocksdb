# include "rrdb.server.impl.h"

namespace dsn
{
    namespace apps
    {
        rrdb_service_impl::rrdb_service_impl()
        {
            _is_open = false;
            // init db options
            _db_opts.write_buffer_size =
                (size_t)dsn_config_get_value_uint64("replication",
                    "rocksdb_write_buffer_size",
                    134217728,
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

        void rrdb_service_impl::on_put(const put_req& args, ::dsn::rpc_replier< put_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());

            rocksdb::Slice skey(args.key);
            rocksdb::Slice svalue(args.value);

            auto status = _db->Put(_wt_opts, skey, svalue);
            if (!status.ok())
            {
                derror("%s failed, status = %s", __FUNCTION__, status.ToString().c_str());
            }
            put_resp resp;
            resp.err = status.code();
            reply(resp);

        }

        void rrdb_service_impl::on_get(const get_req& args, ::dsn::rpc_replier< get_resp>& reply)
        {
            dassert(_is_open, "rrdb service %s is not ready", data_dir());

            get_resp resp;
            rocksdb::Slice skey(args.key);
            rocksdb::Status status = _db->Get(_rd_opts, skey, &resp.value);
            if (!status.ok() && !status.IsNotFound())
            {
                derror("%s failed, status = %s", __FUNCTION__, status.ToString().c_str());
            }
            resp.err = status.code();
            reply(resp);
        }

        ::dsn::error_code rrdb_service_impl::start(int argc, char** argv)
        {
            dassert(!_is_open, "rrdb service %s is already opened", data_dir());

            _app_info = dsn_get_app_info_ptr(gpid());

            rocksdb::Options opts = _db_opts;
            opts.create_if_missing = true;
            opts.error_if_exists = false;
            auto path = utils::filesystem::path_combine(data_dir(), "rdb");
            auto status = rocksdb::DB::Open(opts, path, &_db);

            if (status.ok())
            {
                _is_open = true;
                open_service(gpid());

                return ERR_OK;
            }
            else
            {
                derror("open rocksdb %s failed, status = %s",
                    path.c_str(),
                    status.ToString().c_str()
                    );
                return ERR_LOCAL_APP_FAILURE;
            }
        }

        ::dsn::error_code rrdb_service_impl::stop(bool clear_state)
        {
            if (!_is_open)
            {
                dassert(_db == nullptr, "");
                dassert(!clear_state, "should not be here if do clear");
                return ERR_OK;
            }
            close_service(gpid());
            _is_open = false;
            delete _db;
            _db = nullptr;
            return ERR_OK;
        }
    }
}