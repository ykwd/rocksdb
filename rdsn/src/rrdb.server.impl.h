#pragma once

# include "rrdb.server.h"
# include <rocksdb/db.h>
# include <vector>

namespace dsn
{
    namespace apps
    {
        class rrdb_service_impl :
            public rrdb_service,
            public ::dsn::service_app
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
            rocksdb::WriteBatch   _batch;
            std::vector<rpc_replier<int>> _batch_repliers;

            rocksdb::Options      _db_opts;
            rocksdb::WriteOptions _wt_opts;
            rocksdb::ReadOptions  _rd_opts;

            volatile bool         _is_open;

            dsn_app_info*         _app_info;         // information from layer 
        };
    }
}