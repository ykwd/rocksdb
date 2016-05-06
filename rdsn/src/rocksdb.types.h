# pragma once
# include <dsn/service_api_cpp.h>
# include <dsn/cpp/serialization.h>


# include "thrift/rocksdb_types.h" 


namespace dsn { namespace apps { 
    GENERATED_TYPE_SERIALIZATION(put_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(put_resp, THRIFT)
    GENERATED_TYPE_SERIALIZATION(get_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(get_resp, THRIFT)

} } 