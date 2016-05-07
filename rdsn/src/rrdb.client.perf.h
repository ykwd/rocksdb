# pragma once

# include "rrdb.client.h"

namespace dsn { namespace apps { 
class rrdb_perf_test_client
    : public rrdb_client,
      public ::dsn::service::perf_client_helper
{
public:
    rrdb_perf_test_client(
        ::dsn::rpc_address server)
        : rrdb_client(server)
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
        else if (prob <= ratios[2])
        {
            send_one_remove(payload_bytes, key_space_size);
        }
        else { /* nothing to do */ }
    }
    

    void send_one_put(int payload_bytes, int key_space_size)
    {
        put_req req;
        char buf[10];
        auto key = random64(0, 10000000) % key_space_size;
        itoa(key, buf, 10);
        req.key = std::string(buf);
        req.value = std::string(payload_bytes, 'x');
        auto hash = key;
        put(
            req,
            [this, context = prepare_send_one()](error_code err, put_resp&& resp)
            {
                end_send_one(context, err);
            },
            _timeout,
            0,
            hash
            );
    }

    void send_one_get(int payload_bytes, int key_space_size)
    {
        get_req req;
        char buf[10];
        auto key = random64(0, 10000000) % key_space_size;
        itoa(key, buf, 10);
        req.key = std::string(buf);
        auto hash = key;
        get(
            req,
            [this, context = prepare_send_one()](error_code err, get_resp&& resp)
            {
                end_send_one(context, err);
            },
            _timeout,
            0,
            hash
            );
    }

    void send_one_remove(int payload_bytes, int key_space_size)
    {
        remove_req req;
        char buf[10];
        auto key = random64(0, 10000000) % key_space_size;
        itoa(key, buf, 10);
        req.key = std::string(buf);
        auto hash = key;
        remove(
            req,
            [this, context = prepare_send_one()](error_code err, remove_resp&& resp)
        {
            end_send_one(context, err);
        },
            _timeout,
            0,
            hash
            );
    }
};

} } 