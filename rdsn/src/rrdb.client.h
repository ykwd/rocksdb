# pragma once
# include "rrdb.code.definition.h"
# include <iostream>


namespace dsn { namespace apps { 
class rrdb_client 
    : public virtual ::dsn::clientlet
{
public:
    rrdb_client(::dsn::rpc_address server) { _server = server; }
    rrdb_client() { }
    virtual ~rrdb_client() {}
    
 
    // ---------- call RPC_RRDB_RRDB_PUT ------------
    // - synchronous 
    std::pair< ::dsn::error_code, put_resp> put_sync(
        const put_req& args,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0), 
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::wait_and_unwrap< put_resp>(
            ::dsn::rpc::call(
                server_addr.unwrap_or(_server),
                RPC_RRDB_RRDB_PUT,
                args,
                nullptr,
                empty_callback,
                hash,
                timeout,
                0
                )
            );
    }
    
    // - asynchronous with on-stack put_req and put_resp  
    template<typename TCallback>
    ::dsn::task_ptr put(
        const put_req& args,
        TCallback&& callback,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0),
        int reply_hash = 0,
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::call(
                    server_addr.unwrap_or(_server), 
                    RPC_RRDB_RRDB_PUT, 
                    args,
                    this,
                    std::forward<TCallback>(callback),
                    hash, 
                    timeout, 
                    reply_hash
                    );
    }
 
    // ---------- call RPC_RRDB_RRDB_GET ------------
    // - synchronous 
    std::pair< ::dsn::error_code, get_resp> get_sync(
        const get_req& args,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0), 
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::wait_and_unwrap< get_resp>(
            ::dsn::rpc::call(
                server_addr.unwrap_or(_server),
                RPC_RRDB_RRDB_GET,
                args,
                nullptr,
                empty_callback,
                hash,
                timeout,
                0
                )
            );
    }
    
    // - asynchronous with on-stack get_req and get_resp  
    template<typename TCallback>
    ::dsn::task_ptr get(
        const get_req& args,
        TCallback&& callback,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0),
        int reply_hash = 0,
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::call(
                    server_addr.unwrap_or(_server), 
                    RPC_RRDB_RRDB_GET, 
                    args,
                    this,
                    std::forward<TCallback>(callback),
                    hash, 
                    timeout, 
                    reply_hash
                    );
    }
 
    // ---------- call RPC_RRDB_RRDB_REMOVE ------------
    // - synchronous 
    std::pair< ::dsn::error_code, remove_resp> remove_sync(
        const remove_req& args,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0), 
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::wait_and_unwrap< remove_resp>(
            ::dsn::rpc::call(
                server_addr.unwrap_or(_server),
                RPC_RRDB_RRDB_REMOVE,
                args,
                nullptr,
                empty_callback,
                hash,
                timeout,
                0
                )
            );
    }
    
    // - asynchronous with on-stack remove_req and remove_resp  
    template<typename TCallback>
    ::dsn::task_ptr remove(
        const remove_req& args,
        TCallback&& callback,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0),
        int reply_hash = 0,
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::call(
                    server_addr.unwrap_or(_server), 
                    RPC_RRDB_RRDB_REMOVE, 
                    args,
                    this,
                    std::forward<TCallback>(callback),
                    hash, 
                    timeout, 
                    reply_hash
                    );
    }

private:
    ::dsn::rpc_address _server;
};

} } 