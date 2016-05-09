# pragma once

# include "rrdb.client.h"

namespace dsn { namespace apps { 
class rrdb_perf_test_client
    : public rrdb_client,
      public ::dsn::service::perf_client_helper
{
private:
    int _batch_size;

public:
    rrdb_perf_test_client(
        ::dsn::rpc_address server)
        : rrdb_client(server)
    {
        _batch_size = (int)dsn_config_get_value_uint64("apps.client.perf.rrdb", "max_batch_size", 1, "maximum batch size for perf test");
    }
    
    virtual void send_one(int payload_bytes, int key_space_size, const std::vector<double>& ratios) override
    {
        auto prob = (double)dsn_random32(0, 1000) / 1000.0;
        if (0) {}
        else if (prob <= ratios[0])
        {
            if (_batch_size == 1)
            {
                send_one_put(payload_bytes, key_space_size);
            }
            else
            {
                send_one_batch_put(payload_bytes, key_space_size, _batch_size);
            }
        }
        else if (prob <= ratios[1])
        {
            if (_batch_size == 1)
            {
                send_one_get(payload_bytes, key_space_size);
            }
            else
            {
                send_one_batch_get(payload_bytes, key_space_size, _batch_size);
            }
        }
        else if (prob <= ratios[2])
        {
            if (_batch_size == 1)
            {
                send_one_remove(payload_bytes, key_space_size);
            }
            else
            {
                send_one_batch_remove(payload_bytes, key_space_size, _batch_size);
            }
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

    void send_one_batch_put(int payload_bytes, int key_space_size, int batch_size)
    {
        batch_put_req reqs;
        uint64_t hash = 0;
        char buf[10];
        for (int i = 0; i < batch_size; i++)
        {
            put_req req;
            auto key = random64(0, 10000000) % key_space_size;
            itoa(key, buf, 10);
            req.key = std::string(buf);
            req.value = std::string(payload_bytes, 'x');
            reqs.reqs.push_back(req);
            hash += key;
        }

        batch_put(
            reqs,
            [this, context = prepare_send_one()](error_code err, batch_put_resp&& resp)
            {
                end_send_one(context, err);
            },
            _timeout,
            0,
            hash
            );
    }

    void send_one_batch_get(int payload_bytes, int key_space_size, int batch_size)
    {
        batch_get_req reqs;
        uint64_t hash = 0;
        char buf[10];
        for (int i = 0; i < batch_size; i++)
        {
            get_req req;
            auto key = random64(0, 10000000) % key_space_size;
            itoa(key, buf, 10);
            req.key = std::string(buf);
            reqs.reqs.push_back(req);
            hash += key;
        }
        batch_get(
            reqs,
            [this, context = prepare_send_one()](error_code err, batch_get_resp&& resp)
            {
                end_send_one(context, err);
            },
            _timeout,
            0,
            hash
            );
    }

    void send_one_batch_remove(int payload_bytes, int key_space_size, int batch_size)
    {
        batch_remove_req reqs;
        uint64_t hash = 0;
        char buf[10];
        for (int i = 0; i < batch_size; i++)
        {
            remove_req req;
            auto key = random64(0, 10000000) % key_space_size;
            itoa(key, buf, 10);
            req.key = std::string(buf);
            reqs.reqs.push_back(req);
            hash += key;
        }
        batch_remove(
            reqs,
            [this, context = prepare_send_one()](error_code err, batch_remove_resp&& resp)
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