# pragma once
# include <dsn/service_api_cpp.h>
# include <dsn/cpp/serialization.h>


# include "thrift/rrdb_types.h" 


namespace dsn { namespace apps { 
    GENERATED_TYPE_SERIALIZATION(put_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(put_resp, THRIFT)
    GENERATED_TYPE_SERIALIZATION(get_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(get_resp, THRIFT)
    GENERATED_TYPE_SERIALIZATION(remove_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(remove_resp, THRIFT)
    GENERATED_TYPE_SERIALIZATION(batch_put_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(batch_put_resp, THRIFT)
    GENERATED_TYPE_SERIALIZATION(batch_get_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(batch_get_resp, THRIFT)
    GENERATED_TYPE_SERIALIZATION(batch_remove_req, THRIFT)
    GENERATED_TYPE_SERIALIZATION(batch_remove_resp, THRIFT)

} } 