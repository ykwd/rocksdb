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

service rrdb
{
    put_resp put(1:put_req req);
    get_resp get(1:get_req req);
}
