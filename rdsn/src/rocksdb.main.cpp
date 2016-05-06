// apps
# include "rocksdb.app.example.h"

void dsn_app_registration_rocksdb()
{
    // register all possible service apps
    dsn::register_app< ::dsn::apps::rocksdb_server_app>("server");
    dsn::register_app< ::dsn::apps::rocksdb_client_app>("client");
    dsn::register_app< ::dsn::apps::leveldb_perf_test_client_app>("client.perf.leveldb");
}

# ifndef DSN_RUN_USE_SVCHOST

int main(int argc, char** argv)
{
    dsn_app_registration_rocksdb();
    
    // specify what services and tools will run in config file, then run
    dsn_run(argc, argv, true);
    return 0;
}

# else

# include <dsn/internal/module_init.cpp.h>

MODULE_INIT_BEGIN(rocksdb)
    dsn_app_registration_rocksdb();
MODULE_INIT_END

# endif
