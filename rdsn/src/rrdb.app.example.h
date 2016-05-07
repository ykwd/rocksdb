# pragma once
# include "rrdb.client.h"
# include "rrdb.client.perf.h"
# include "rrdb.server.h"
# include "rrdb.server.impl.h"

namespace dsn { namespace apps { 

// client app example
class rrdb_client_app : 
    public ::dsn::service_app, 
    public virtual ::dsn::clientlet
{
public:
    rrdb_client_app() {}
    
    ~rrdb_client_app() 
    {
        stop();
    }

    virtual ::dsn::error_code start(int argc, char** argv) override
    {
        if (argc < 1)
        {
            printf ("Usage: <exe> server-host:server-port or service-url\n");
            return ::dsn::ERR_INVALID_PARAMETERS;
        }

        // argv[1]: e.g., dsn://mycluster/simple-kv.instance0
        _server = ::dsn::url_host_address(argv[1]);
            
        _rrdb_client.reset(new rrdb_client(_server));
        _timer = ::dsn::tasking::enqueue_timer(LPC_RRDB_TEST_TIMER, this, [this]{on_test_timer();}, std::chrono::seconds(1));
        return ::dsn::ERR_OK;
    }

    virtual ::dsn::error_code stop(bool cleanup = false) override
    {
        _timer->cancel(true);
 
        _rrdb_client.reset();
        return ::dsn::ERR_OK;
    }

    void on_test_timer()
    {
        // test for service 'rrdb'
        {
            //sync:
            put_req req;
            req.key = "hello";
            req.value = "world";
            auto result = _rrdb_client->put_sync(req);
            std::cout << "call RPC_RRDB_RRDB_PUT end, return " << result.first.to_string() << std::endl;
            //async: 
            //_rrdb_client->put({});
           
        }
        {
            //sync:
            get_req req;
            req.key = "hello";
            auto result = _rrdb_client->get_sync(req);
            std::cout << "call RPC_RRDB_RRDB_GET end, return " << result.first.to_string() << " "  << result.second.value << std::endl;
            //async: 
            //_rrdb_client->get({});
           
        }
        {
            //sync:
            auto result = _rrdb_client->remove_sync({});
            std::cout << "call RPC_RRDB_RRDB_REMOVE end, return " << result.first.to_string() << std::endl;
            //async: 
            //_rrdb_client->remove({});

        }
    }

private:
    ::dsn::task_ptr _timer;
    ::dsn::url_host_address _server;
    
    std::unique_ptr<rrdb_client> _rrdb_client;
};

class rrdb_perf_test_client_app :
    public ::dsn::service_app, 
    public virtual ::dsn::clientlet
{
public:
    rrdb_perf_test_client_app()
    {
        _rrdb_client = nullptr;
    }

    ~rrdb_perf_test_client_app()
    {
        stop();
    }

    virtual ::dsn::error_code start(int argc, char** argv) override
    {
        if (argc < 1)
            return ::dsn::ERR_INVALID_PARAMETERS;

        // argv[1]: e.g., dsn://mycluster/simple-kv.instance0
        _server = ::dsn::url_host_address(argv[1]);

        _rrdb_client = new rrdb_perf_test_client(_server);
        _rrdb_client->start_test("rrdb.perf-test.case.", 3);
        return ::dsn::ERR_OK;
    }

    virtual ::dsn::error_code stop(bool cleanup = false) override
    {
        if (_rrdb_client != nullptr)
        {
            delete _rrdb_client;
            _rrdb_client = nullptr;
        }
        
        return ::dsn::ERR_OK;
    }
    
private:
    rrdb_perf_test_client *_rrdb_client;
    ::dsn::rpc_address _server;
};

} } 