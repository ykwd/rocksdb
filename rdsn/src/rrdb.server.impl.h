#pragma once

# include "rrdb.server.h"
# include <rocksdb/db.h>
# include <vector>
# include <dsn/cpp/replicated_service_app.h>

namespace dsn
{
    namespace apps
    {
        class rrdb_service_impl :
            public rrdb_service,
            public replicated_service_app_type_1
        {
        public:
            rrdb_service_impl();

            // RPC_RRDB_RRDB_PUT 
            virtual void on_put(const put_req& args, ::dsn::rpc_replier< put_resp>& reply);

            // RPC_RRDB_RRDB_GET 
            virtual void on_get(const get_req& args, ::dsn::rpc_replier< get_resp>& reply);

            // RPC_RRDB_RRDB_REMOVE 
            virtual void on_remove(const remove_req& args, ::dsn::rpc_replier< remove_resp>& reply);

            virtual ::dsn::error_code start(int argc, char** argv) override;

            virtual ::dsn::error_code stop(bool cleanup = false) override;

        private:
            ::dsn::service::zlock _lock;

            const char* data_dir() { return _app_info->data_dir; }

            rocksdb::DB           *_db;

            rocksdb::Options      _db_opts;
            rocksdb::WriteOptions _wt_opts;
            rocksdb::ReadOptions  _rd_opts;

            volatile bool         _is_open;

            dsn_app_info*         _app_info;         // information from layer

                                                     //for layer2
        public:

            virtual ::dsn::error_code checkpoint() override;

            //virtual ::dsn::error_code checkpoint_async() override;

            virtual int prepare_get_checkpoint(void* buffer, int capacity) override { return 0; }

            virtual ::dsn::error_code get_checkpoint(
                int64_t start,
                void*   learn_request,
                int     learn_request_size,
                /* inout */ app_learn_state& state
                ) override;

            virtual ::dsn::error_code apply_checkpoint(const dsn_app_learn_state& state, dsn_chkpt_apply_mode mode) override;

        private:
            int64_t last_committed_decree() { return _app_info->info.type1.last_committed_decree; }
            int64_t last_durable_decree() { return _app_info->info.type1.last_durable_decree; }
            void    set_last_durable_decree(int64_t d) { _app_info->info.type1.last_durable_decree = d; }

            void recover();
            void recover(const std::string& name, int64_t version);
        };
    }
}