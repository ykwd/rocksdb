# pragma once

# include "rocksdb.client.h"

namespace dsn { namespace apps { 
class leveldb_perf_test_client
    : public leveldb_client,
      public ::dsn::service::perf_client_helper
{
public:
    leveldb_perf_test_client(
        ::dsn::rpc_address server)
        : leveldb_client(server)
    {
    }
    
    virtual void send_one(int payload_bytes, int key_space_size, const std::vector<double>& ratios) override
    {
        auto prob = (double)dsn_random32(0, 1000) / 1000.0;
        if (0) {}
        else if (prob <= ratios[0])
        {
            send_one_put(payload_bytes, key_space_size);
        }
        else if (prob <= ratios[1])
        {
            send_one_get(payload_bytes, key_space_size);
        }
        else { /* nothing to do */ }
    }
    

    void send_one_put(int payload_bytes, int key_space_size)
    {
        put_req req;
        // TODO: randomize the value of req
        // auto rs = random64(0, 10000000) % key_space_size;
        // std::stringstream ss;
        // ss << "key." << rs;
        // req = ss.str();
        put(
            req,
            [this, context = prepare_send_one()](error_code err, put_resp&& resp)
            {
                end_send_one(context, err);
            },
            _timeout
            );
    }

    void send_one_get(int payload_bytes, int key_space_size)
    {
        get_req req;
        // TODO: randomize the value of req
        // auto rs = random64(0, 10000000) % key_space_size;
        // std::stringstream ss;
        // ss << "key." << rs;
        // req = ss.str();
        get(
            req,
            [this, context = prepare_send_one()](error_code err, get_resp&& resp)
            {
                end_send_one(context, err);
            },
            _timeout
            );
    }
};

} } 