namespace cpp dsn.apps

struct put_req
{
    1:string key;
    2:string value;
}

struct put_resp
{
    1:i32 err;
}

struct get_req
{
    1:string key;
}

struct get_resp
{
    1:i32 err;
    2:string value;
}

struct remove_req
{
    1:string key;
}

struct remove_resp
{
    1:i32 err;
}

struct batch_put_req
{
    1:list<put_req> reqs;
}

struct batch_put_resp
{
    1:list<put_resp> resqs;
}

struct batch_get_req
{
    1:list<get_req> reqs;
}

struct batch_get_resp
{
    1:list<get_resp> resps;
}

struct batch_remove_req
{
    1:list<remove_req> resps;
}

struct batch_remove_resp
{
    1:list<remove_resp> resps;
}
service rrdb
{
    put_resp put(1:put_req req);
    get_resp get(1:get_req req);
    remove_resp remove(1:remove_req req);
    
    batch_put_resp batch_put(1:batch_put_req req);
    batch_get_resp batch_get(1:batch_get_req req);
    batch_remove_resp batch_remove(1:batch_remove_req req);
}
