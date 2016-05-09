/**
 * Autogenerated by Thrift Compiler (@PACKAGE_VERSION@)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef rrdb_TYPES_H
#define rrdb_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>


namespace dsn { namespace apps {

class put_req;

class put_resp;

class get_req;

class get_resp;

class remove_req;

class remove_resp;

class batch_put_req;

class batch_put_resp;

class batch_get_req;

class batch_get_resp;

class batch_remove_req;

class batch_remove_resp;

typedef struct _put_req__isset {
  _put_req__isset() : key(false), value(false) {}
  bool key :1;
  bool value :1;
} _put_req__isset;

class put_req {
 public:

  put_req(const put_req&);
  put_req& operator=(const put_req&);
  put_req() : key(), value() {
  }

  virtual ~put_req() throw();
  std::string key;
  std::string value;

  _put_req__isset __isset;

  void __set_key(const std::string& val);

  void __set_value(const std::string& val);

  bool operator == (const put_req & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const put_req &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const put_req & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(put_req &a, put_req &b);

inline std::ostream& operator<<(std::ostream& out, const put_req& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _put_resp__isset {
  _put_resp__isset() : err(false) {}
  bool err :1;
} _put_resp__isset;

class put_resp {
 public:

  put_resp(const put_resp&);
  put_resp& operator=(const put_resp&);
  put_resp() : err(0) {
  }

  virtual ~put_resp() throw();
  int32_t err;

  _put_resp__isset __isset;

  void __set_err(const int32_t val);

  bool operator == (const put_resp & rhs) const
  {
    if (!(err == rhs.err))
      return false;
    return true;
  }
  bool operator != (const put_resp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const put_resp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(put_resp &a, put_resp &b);

inline std::ostream& operator<<(std::ostream& out, const put_resp& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _get_req__isset {
  _get_req__isset() : key(false) {}
  bool key :1;
} _get_req__isset;

class get_req {
 public:

  get_req(const get_req&);
  get_req& operator=(const get_req&);
  get_req() : key() {
  }

  virtual ~get_req() throw();
  std::string key;

  _get_req__isset __isset;

  void __set_key(const std::string& val);

  bool operator == (const get_req & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const get_req &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const get_req & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(get_req &a, get_req &b);

inline std::ostream& operator<<(std::ostream& out, const get_req& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _get_resp__isset {
  _get_resp__isset() : err(false), value(false) {}
  bool err :1;
  bool value :1;
} _get_resp__isset;

class get_resp {
 public:

  get_resp(const get_resp&);
  get_resp& operator=(const get_resp&);
  get_resp() : err(0), value() {
  }

  virtual ~get_resp() throw();
  int32_t err;
  std::string value;

  _get_resp__isset __isset;

  void __set_err(const int32_t val);

  void __set_value(const std::string& val);

  bool operator == (const get_resp & rhs) const
  {
    if (!(err == rhs.err))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const get_resp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const get_resp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(get_resp &a, get_resp &b);

inline std::ostream& operator<<(std::ostream& out, const get_resp& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _remove_req__isset {
  _remove_req__isset() : key(false) {}
  bool key :1;
} _remove_req__isset;

class remove_req {
 public:

  remove_req(const remove_req&);
  remove_req& operator=(const remove_req&);
  remove_req() : key() {
  }

  virtual ~remove_req() throw();
  std::string key;

  _remove_req__isset __isset;

  void __set_key(const std::string& val);

  bool operator == (const remove_req & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const remove_req &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const remove_req & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(remove_req &a, remove_req &b);

inline std::ostream& operator<<(std::ostream& out, const remove_req& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _remove_resp__isset {
  _remove_resp__isset() : err(false) {}
  bool err :1;
} _remove_resp__isset;

class remove_resp {
 public:

  remove_resp(const remove_resp&);
  remove_resp& operator=(const remove_resp&);
  remove_resp() : err(0) {
  }

  virtual ~remove_resp() throw();
  int32_t err;

  _remove_resp__isset __isset;

  void __set_err(const int32_t val);

  bool operator == (const remove_resp & rhs) const
  {
    if (!(err == rhs.err))
      return false;
    return true;
  }
  bool operator != (const remove_resp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const remove_resp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(remove_resp &a, remove_resp &b);

inline std::ostream& operator<<(std::ostream& out, const remove_resp& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _batch_put_req__isset {
  _batch_put_req__isset() : reqs(false) {}
  bool reqs :1;
} _batch_put_req__isset;

class batch_put_req {
 public:

  batch_put_req(const batch_put_req&);
  batch_put_req& operator=(const batch_put_req&);
  batch_put_req() {
  }

  virtual ~batch_put_req() throw();
  std::vector<put_req>  reqs;

  _batch_put_req__isset __isset;

  void __set_reqs(const std::vector<put_req> & val);

  bool operator == (const batch_put_req & rhs) const
  {
    if (!(reqs == rhs.reqs))
      return false;
    return true;
  }
  bool operator != (const batch_put_req &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const batch_put_req & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(batch_put_req &a, batch_put_req &b);

inline std::ostream& operator<<(std::ostream& out, const batch_put_req& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _batch_put_resp__isset {
  _batch_put_resp__isset() : resps(false) {}
  bool resps :1;
} _batch_put_resp__isset;

class batch_put_resp {
 public:

  batch_put_resp(const batch_put_resp&);
  batch_put_resp& operator=(const batch_put_resp&);
  batch_put_resp() {
  }

  virtual ~batch_put_resp() throw();
  std::vector<put_resp>  resps;

  _batch_put_resp__isset __isset;

  void __set_resps(const std::vector<put_resp> & val);

  bool operator == (const batch_put_resp & rhs) const
  {
    if (!(resps == rhs.resps))
      return false;
    return true;
  }
  bool operator != (const batch_put_resp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const batch_put_resp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(batch_put_resp &a, batch_put_resp &b);

inline std::ostream& operator<<(std::ostream& out, const batch_put_resp& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _batch_get_req__isset {
  _batch_get_req__isset() : reqs(false) {}
  bool reqs :1;
} _batch_get_req__isset;

class batch_get_req {
 public:

  batch_get_req(const batch_get_req&);
  batch_get_req& operator=(const batch_get_req&);
  batch_get_req() {
  }

  virtual ~batch_get_req() throw();
  std::vector<get_req>  reqs;

  _batch_get_req__isset __isset;

  void __set_reqs(const std::vector<get_req> & val);

  bool operator == (const batch_get_req & rhs) const
  {
    if (!(reqs == rhs.reqs))
      return false;
    return true;
  }
  bool operator != (const batch_get_req &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const batch_get_req & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(batch_get_req &a, batch_get_req &b);

inline std::ostream& operator<<(std::ostream& out, const batch_get_req& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _batch_get_resp__isset {
  _batch_get_resp__isset() : resps(false) {}
  bool resps :1;
} _batch_get_resp__isset;

class batch_get_resp {
 public:

  batch_get_resp(const batch_get_resp&);
  batch_get_resp& operator=(const batch_get_resp&);
  batch_get_resp() {
  }

  virtual ~batch_get_resp() throw();
  std::vector<get_resp>  resps;

  _batch_get_resp__isset __isset;

  void __set_resps(const std::vector<get_resp> & val);

  bool operator == (const batch_get_resp & rhs) const
  {
    if (!(resps == rhs.resps))
      return false;
    return true;
  }
  bool operator != (const batch_get_resp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const batch_get_resp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(batch_get_resp &a, batch_get_resp &b);

inline std::ostream& operator<<(std::ostream& out, const batch_get_resp& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _batch_remove_req__isset {
  _batch_remove_req__isset() : reqs(false) {}
  bool reqs :1;
} _batch_remove_req__isset;

class batch_remove_req {
 public:

  batch_remove_req(const batch_remove_req&);
  batch_remove_req& operator=(const batch_remove_req&);
  batch_remove_req() {
  }

  virtual ~batch_remove_req() throw();
  std::vector<remove_req>  reqs;

  _batch_remove_req__isset __isset;

  void __set_reqs(const std::vector<remove_req> & val);

  bool operator == (const batch_remove_req & rhs) const
  {
    if (!(reqs == rhs.reqs))
      return false;
    return true;
  }
  bool operator != (const batch_remove_req &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const batch_remove_req & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(batch_remove_req &a, batch_remove_req &b);

inline std::ostream& operator<<(std::ostream& out, const batch_remove_req& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _batch_remove_resp__isset {
  _batch_remove_resp__isset() : resps(false) {}
  bool resps :1;
} _batch_remove_resp__isset;

class batch_remove_resp {
 public:

  batch_remove_resp(const batch_remove_resp&);
  batch_remove_resp& operator=(const batch_remove_resp&);
  batch_remove_resp() {
  }

  virtual ~batch_remove_resp() throw();
  std::vector<remove_resp>  resps;

  _batch_remove_resp__isset __isset;

  void __set_resps(const std::vector<remove_resp> & val);

  bool operator == (const batch_remove_resp & rhs) const
  {
    if (!(resps == rhs.resps))
      return false;
    return true;
  }
  bool operator != (const batch_remove_resp &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const batch_remove_resp & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(batch_remove_resp &a, batch_remove_resp &b);

inline std::ostream& operator<<(std::ostream& out, const batch_remove_resp& obj)
{
  obj.printTo(out);
  return out;
}

}} // namespace

#endif
