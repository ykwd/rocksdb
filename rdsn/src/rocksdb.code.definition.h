# pragma once
# include <dsn/service_api_cpp.h>
# include "rocksdb.types.h"

namespace dsn { namespace apps { 
    // define your own thread pool using DEFINE_THREAD_POOL_CODE(xxx)
    // define RPC task code for service 'leveldb'
    DEFINE_TASK_CODE_RPC(RPC_ROCKSDB_LEVELDB_PUT, TASK_PRIORITY_COMMON, ::dsn::THREAD_POOL_DEFAULT)
    DEFINE_TASK_CODE_RPC(RPC_ROCKSDB_LEVELDB_GET, TASK_PRIORITY_COMMON, ::dsn::THREAD_POOL_DEFAULT)
    // test timer task code
    DEFINE_TASK_CODE(LPC_ROCKSDB_TEST_TIMER, TASK_PRIORITY_COMMON, ::dsn::THREAD_POOL_DEFAULT)
} } 
