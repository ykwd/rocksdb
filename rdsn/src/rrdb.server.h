# pragma once
# include "rrdb.code.definition.h"
# include <iostream>

namespace dsn { namespace apps { 
class rrdb_service 
    : public ::dsn::serverlet< rrdb_service>
{
public:
    rrdb_service() : ::dsn::serverlet< rrdb_service>("rrdb") {}
    virtual ~rrdb_service() {}

protected:
    // all service handlers to be implemented further
    // RPC_RRDB_RRDB_PUT 
    virtual void on_put(const put_req& args, ::dsn::rpc_replier< put_resp>& reply)
    {
        std::cout << "... exec RPC_RRDB_RRDB_PUT ... (not implemented) " << std::endl;
        put_resp resp;
        reply(resp);
    }
    // RPC_RRDB_RRDB_GET 
    virtual void on_get(const get_req& args, ::dsn::rpc_replier< get_resp>& reply)
    {
        std::cout << "... exec RPC_RRDB_RRDB_GET ... (not implemented) " << std::endl;
        get_resp resp;
        reply(resp);
    }
    // RPC_RRDB_RRDB_REMOVE 
    virtual void on_remove(const remove_req& args, ::dsn::rpc_replier< remove_resp>& reply)
    {
        std::cout << "... exec RPC_RRDB_RRDB_REMOVE ... (not implemented) " << std::endl;
        remove_resp resp;
        reply(resp);
    }
    // RPC_RRDB_RRDB_BATCH_PUT 
    virtual void on_batch_put(const batch_put_req& args, ::dsn::rpc_replier< batch_put_resp>& reply)
    {
        std::cout << "... exec RPC_RRDB_RRDB_BATCH_PUT ... (not implemented) " << std::endl;
        batch_put_resp resp;
        reply(resp);
    }
    // RPC_RRDB_RRDB_BATCH_GET 
    virtual void on_batch_get(const batch_get_req& args, ::dsn::rpc_replier< batch_get_resp>& reply)
    {
        std::cout << "... exec RPC_RRDB_RRDB_BATCH_GET ... (not implemented) " << std::endl;
        batch_get_resp resp;
        reply(resp);
    }
    // RPC_RRDB_RRDB_BATCH_REMOVE 
    virtual void on_batch_remove(const batch_remove_req& args, ::dsn::rpc_replier< batch_remove_resp>& reply)
    {
        std::cout << "... exec RPC_RRDB_RRDB_BATCH_REMOVE ... (not implemented) " << std::endl;
        batch_remove_resp resp;
        reply(resp);
    }
    
public:
    void open_service(dsn_gpid gpid)
    {
        this->register_async_rpc_handler(RPC_RRDB_RRDB_PUT, "put", &rrdb_service::on_put, gpid);
        this->register_async_rpc_handler(RPC_RRDB_RRDB_GET, "get", &rrdb_service::on_get, gpid);
        this->register_async_rpc_handler(RPC_RRDB_RRDB_REMOVE, "remove", &rrdb_service::on_remove, gpid);
        this->register_async_rpc_handler(RPC_RRDB_RRDB_BATCH_PUT, "batch_put", &rrdb_service::on_batch_put, gpid);
        this->register_async_rpc_handler(RPC_RRDB_RRDB_BATCH_GET, "batch_get", &rrdb_service::on_batch_get, gpid);
        this->register_async_rpc_handler(RPC_RRDB_RRDB_BATCH_REMOVE, "batch_remove", &rrdb_service::on_batch_remove, gpid);
    }

    void close_service(dsn_gpid gpid)
    {
        this->unregister_rpc_handler(RPC_RRDB_RRDB_PUT, gpid);
        this->unregister_rpc_handler(RPC_RRDB_RRDB_GET, gpid);
        this->unregister_rpc_handler(RPC_RRDB_RRDB_REMOVE, gpid);
        this->unregister_rpc_handler(RPC_RRDB_RRDB_BATCH_PUT, gpid);
        this->unregister_rpc_handler(RPC_RRDB_RRDB_BATCH_GET, gpid);
        this->unregister_rpc_handler(RPC_RRDB_RRDB_BATCH_REMOVE, gpid);
    }
};

} } 