# pragma once
# include "rocksdb.client.h"
# include "rocksdb.client.perf.h"
# include "rocksdb.server.h"

namespace dsn { namespace apps { 
// server app example
class rocksdb_server_app : 
    public ::dsn::service_app
{
public:
    rocksdb_server_app() {}

    virtual ::dsn::error_code start(int argc, char** argv) override
    {
        _leveldb_svc.open_service(gpid());
        return ::dsn::ERR_OK;
    }

    virtual ::dsn::error_code stop(bool cleanup = false) override
    {
        _leveldb_svc.close_service(gpid());
        return ::dsn::ERR_OK;
    }

private:
    leveldb_service _leveldb_svc;
};

// client app example
class rocksdb_client_app : 
    public ::dsn::service_app, 
    public virtual ::dsn::clientlet
{
public:
    rocksdb_client_app() {}
    
    ~rocksdb_client_app() 
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
            
        _leveldb_client.reset(new leveldb_client(_server));
        _timer = ::dsn::tasking::enqueue_timer(LPC_ROCKSDB_TEST_TIMER, this, [this]{on_test_timer();}, std::chrono::seconds(1));
        return ::dsn::ERR_OK;
    }

    virtual ::dsn::error_code stop(bool cleanup = false) override
    {
        _timer->cancel(true);
 
        _leveldb_client.reset();
        return ::dsn::ERR_OK;
    }

    void on_test_timer()
    {
        // test for service 'leveldb'
        {
            //sync:
            auto result = _leveldb_client->put_sync({});
            std::cout << "call RPC_ROCKSDB_LEVELDB_PUT end, return " << result.first.to_string() << std::endl;
            //async: 
            //_leveldb_client->put({});
           
        }
        {
            //sync:
            auto result = _leveldb_client->get_sync({});
            std::cout << "call RPC_ROCKSDB_LEVELDB_GET end, return " << result.first.to_string() << std::endl;
            //async: 
            //_leveldb_client->get({});
           
        }
    }

private:
    ::dsn::task_ptr _timer;
    ::dsn::url_host_address _server;
    
    std::unique_ptr<leveldb_client> _leveldb_client;
};

class leveldb_perf_test_client_app :
    public ::dsn::service_app, 
    public virtual ::dsn::clientlet
{
public:
    leveldb_perf_test_client_app()
    {
        _leveldb_client = nullptr;
    }

    ~leveldb_perf_test_client_app()
    {
        stop();
    }

    virtual ::dsn::error_code start(int argc, char** argv) override
    {
        if (argc < 1)
            return ::dsn::ERR_INVALID_PARAMETERS;

        // argv[1]: e.g., dsn://mycluster/simple-kv.instance0
        _server = ::dsn::url_host_address(argv[1]);

        _leveldb_client = new leveldb_perf_test_client(_server);
        _leveldb_client->start_test("leveldb.perf-test.case.", 2);
        return ::dsn::ERR_OK;
    }

    virtual ::dsn::error_code stop(bool cleanup = false) override
    {
        if (_leveldb_client != nullptr)
        {
            delete _leveldb_client;
            _leveldb_client = nullptr;
        }
        
        return ::dsn::ERR_OK;
    }
    
private:
    leveldb_perf_test_client *_leveldb_client;
    ::dsn::rpc_address _server;
};

} } 