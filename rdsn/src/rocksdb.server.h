# pragma once
# include "rocksdb.code.definition.h"
# include <iostream>

namespace dsn { namespace apps { 
class leveldb_service 
    : public ::dsn::serverlet< leveldb_service>
{
public:
    leveldb_service() : ::dsn::serverlet< leveldb_service>("leveldb") {}
    virtual ~leveldb_service() {}

protected:
    // all service handlers to be implemented further
    // RPC_ROCKSDB_LEVELDB_PUT 
    virtual void on_put(const put_req& args, ::dsn::rpc_replier< put_resp>& reply)
    {
        std::cout << "... exec RPC_ROCKSDB_LEVELDB_PUT ... (not implemented) " << std::endl;
        put_resp resp;
        reply(resp);
    }
    // RPC_ROCKSDB_LEVELDB_GET 
    virtual void on_get(const get_req& args, ::dsn::rpc_replier< get_resp>& reply)
    {
        std::cout << "... exec RPC_ROCKSDB_LEVELDB_GET ... (not implemented) " << std::endl;
        get_resp resp;
        reply(resp);
    }
    
public:
    void open_service(dsn_gpid gpid)
    {
        this->register_async_rpc_handler(RPC_ROCKSDB_LEVELDB_PUT, "put", &leveldb_service::on_put, gpid);
        this->register_async_rpc_handler(RPC_ROCKSDB_LEVELDB_GET, "get", &leveldb_service::on_get, gpid);
    }

    void close_service(dsn_gpid gpid)
    {
        this->unregister_rpc_handler(RPC_ROCKSDB_LEVELDB_PUT, gpid);
        this->unregister_rpc_handler(RPC_ROCKSDB_LEVELDB_GET, gpid);
    }
};

} } 