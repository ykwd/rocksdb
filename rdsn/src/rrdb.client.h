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
 
    // ---------- call RPC_RRDB_RRDB_BATCH_PUT ------------
    // - synchronous 
    std::pair< ::dsn::error_code, batch_put_resp> batch_put_sync(
        const batch_put_req& args,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0), 
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::wait_and_unwrap< batch_put_resp>(
            ::dsn::rpc::call(
                server_addr.unwrap_or(_server),
                RPC_RRDB_RRDB_BATCH_PUT,
                args,
                nullptr,
                empty_callback,
                hash,
                timeout,
                0
                )
            );
    }
    
    // - asynchronous with on-stack batch_put_req and batch_put_resp  
    template<typename TCallback>
    ::dsn::task_ptr batch_put(
        const batch_put_req& args,
        TCallback&& callback,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0),
        int reply_hash = 0,
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::call(
                    server_addr.unwrap_or(_server), 
                    RPC_RRDB_RRDB_BATCH_PUT, 
                    args,
                    this,
                    std::forward<TCallback>(callback),
                    hash, 
                    timeout, 
                    reply_hash
                    );
    }
 
    // ---------- call RPC_RRDB_RRDB_BATCH_GET ------------
    // - synchronous 
    std::pair< ::dsn::error_code, batch_get_resp> batch_get_sync(
        const batch_get_req& args,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0), 
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::wait_and_unwrap< batch_get_resp>(
            ::dsn::rpc::call(
                server_addr.unwrap_or(_server),
                RPC_RRDB_RRDB_BATCH_GET,
                args,
                nullptr,
                empty_callback,
                hash,
                timeout,
                0
                )
            );
    }
    
    // - asynchronous with on-stack batch_get_req and batch_get_resp  
    template<typename TCallback>
    ::dsn::task_ptr batch_get(
        const batch_get_req& args,
        TCallback&& callback,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0),
        int reply_hash = 0,
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::call(
                    server_addr.unwrap_or(_server), 
                    RPC_RRDB_RRDB_BATCH_GET, 
                    args,
                    this,
                    std::forward<TCallback>(callback),
                    hash, 
                    timeout, 
                    reply_hash
                    );
    }
 
    // ---------- call RPC_RRDB_RRDB_BATCH_REMOVE ------------
    // - synchronous 
    std::pair< ::dsn::error_code, batch_remove_resp> batch_remove_sync(
        const batch_remove_req& args,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0), 
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::wait_and_unwrap< batch_remove_resp>(
            ::dsn::rpc::call(
                server_addr.unwrap_or(_server),
                RPC_RRDB_RRDB_BATCH_REMOVE,
                args,
                nullptr,
                empty_callback,
                hash,
                timeout,
                0
                )
            );
    }
    
    // - asynchronous with on-stack batch_remove_req and batch_remove_resp  
    template<typename TCallback>
    ::dsn::task_ptr batch_remove(
        const batch_remove_req& args,
        TCallback&& callback,
        std::chrono::milliseconds timeout = std::chrono::milliseconds(0),
        int reply_hash = 0,
        uint64_t hash = 0,
        dsn::optional< ::dsn::rpc_address> server_addr = dsn::none
        )
    {
        return ::dsn::rpc::call(
                    server_addr.unwrap_or(_server), 
                    RPC_RRDB_RRDB_BATCH_REMOVE, 
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