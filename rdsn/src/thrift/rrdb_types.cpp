/**
 * Autogenerated by Thrift Compiler (@PACKAGE_VERSION@)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "rrdb_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace dsn { namespace apps {


put_req::~put_req() throw() {
}


void put_req::__set_key(const std::string& val) {
  this->key = val;
}

void put_req::__set_value(const std::string& val) {
  this->value = val;
}

uint32_t put_req::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t put_req::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("put_req");

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(put_req &a, put_req &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

put_req::put_req(const put_req& other0) {
  key = other0.key;
  value = other0.value;
  __isset = other0.__isset;
}
put_req& put_req::operator=(const put_req& other1) {
  key = other1.key;
  value = other1.value;
  __isset = other1.__isset;
  return *this;
}
void put_req::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "put_req(";
  out << "key=" << to_string(key);
  out << ", " << "value=" << to_string(value);
  out << ")";
}


put_resp::~put_resp() throw() {
}


void put_resp::__set_err(const int32_t val) {
  this->err = val;
}

uint32_t put_resp::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->err);
          this->__isset.err = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t put_resp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("put_resp");

  xfer += oprot->writeFieldBegin("err", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->err);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(put_resp &a, put_resp &b) {
  using ::std::swap;
  swap(a.err, b.err);
  swap(a.__isset, b.__isset);
}

put_resp::put_resp(const put_resp& other2) {
  err = other2.err;
  __isset = other2.__isset;
}
put_resp& put_resp::operator=(const put_resp& other3) {
  err = other3.err;
  __isset = other3.__isset;
  return *this;
}
void put_resp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "put_resp(";
  out << "err=" << to_string(err);
  out << ")";
}


get_req::~get_req() throw() {
}


void get_req::__set_key(const std::string& val) {
  this->key = val;
}

uint32_t get_req::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t get_req::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("get_req");

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(get_req &a, get_req &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.__isset, b.__isset);
}

get_req::get_req(const get_req& other4) {
  key = other4.key;
  __isset = other4.__isset;
}
get_req& get_req::operator=(const get_req& other5) {
  key = other5.key;
  __isset = other5.__isset;
  return *this;
}
void get_req::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "get_req(";
  out << "key=" << to_string(key);
  out << ")";
}


get_resp::~get_resp() throw() {
}


void get_resp::__set_err(const int32_t val) {
  this->err = val;
}

void get_resp::__set_value(const std::string& val) {
  this->value = val;
}

uint32_t get_resp::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->err);
          this->__isset.err = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t get_resp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("get_resp");

  xfer += oprot->writeFieldBegin("err", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->err);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(get_resp &a, get_resp &b) {
  using ::std::swap;
  swap(a.err, b.err);
  swap(a.value, b.value);
  swap(a.__isset, b.__isset);
}

get_resp::get_resp(const get_resp& other6) {
  err = other6.err;
  value = other6.value;
  __isset = other6.__isset;
}
get_resp& get_resp::operator=(const get_resp& other7) {
  err = other7.err;
  value = other7.value;
  __isset = other7.__isset;
  return *this;
}
void get_resp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "get_resp(";
  out << "err=" << to_string(err);
  out << ", " << "value=" << to_string(value);
  out << ")";
}


remove_req::~remove_req() throw() {
}


void remove_req::__set_key(const std::string& val) {
  this->key = val;
}

uint32_t remove_req::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->key);
          this->__isset.key = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t remove_req::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("remove_req");

  xfer += oprot->writeFieldBegin("key", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->key);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(remove_req &a, remove_req &b) {
  using ::std::swap;
  swap(a.key, b.key);
  swap(a.__isset, b.__isset);
}

remove_req::remove_req(const remove_req& other8) {
  key = other8.key;
  __isset = other8.__isset;
}
remove_req& remove_req::operator=(const remove_req& other9) {
  key = other9.key;
  __isset = other9.__isset;
  return *this;
}
void remove_req::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "remove_req(";
  out << "key=" << to_string(key);
  out << ")";
}


remove_resp::~remove_resp() throw() {
}


void remove_resp::__set_err(const int32_t val) {
  this->err = val;
}

uint32_t remove_resp::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->err);
          this->__isset.err = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t remove_resp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("remove_resp");

  xfer += oprot->writeFieldBegin("err", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->err);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(remove_resp &a, remove_resp &b) {
  using ::std::swap;
  swap(a.err, b.err);
  swap(a.__isset, b.__isset);
}

remove_resp::remove_resp(const remove_resp& other10) {
  err = other10.err;
  __isset = other10.__isset;
}
remove_resp& remove_resp::operator=(const remove_resp& other11) {
  err = other11.err;
  __isset = other11.__isset;
  return *this;
}
void remove_resp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "remove_resp(";
  out << "err=" << to_string(err);
  out << ")";
}


batch_put_req::~batch_put_req() throw() {
}


void batch_put_req::__set_reqs(const std::vector<put_req> & val) {
  this->reqs = val;
}

uint32_t batch_put_req::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->reqs.clear();
            uint32_t _size12;
            ::apache::thrift::protocol::TType _etype15;
            xfer += iprot->readListBegin(_etype15, _size12);
            this->reqs.resize(_size12);
            uint32_t _i16;
            for (_i16 = 0; _i16 < _size12; ++_i16)
            {
              xfer += this->reqs[_i16].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.reqs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t batch_put_req::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("batch_put_req");

  xfer += oprot->writeFieldBegin("reqs", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->reqs.size()));
    std::vector<put_req> ::const_iterator _iter17;
    for (_iter17 = this->reqs.begin(); _iter17 != this->reqs.end(); ++_iter17)
    {
      xfer += (*_iter17).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(batch_put_req &a, batch_put_req &b) {
  using ::std::swap;
  swap(a.reqs, b.reqs);
  swap(a.__isset, b.__isset);
}

batch_put_req::batch_put_req(const batch_put_req& other18) {
  reqs = other18.reqs;
  __isset = other18.__isset;
}
batch_put_req& batch_put_req::operator=(const batch_put_req& other19) {
  reqs = other19.reqs;
  __isset = other19.__isset;
  return *this;
}
void batch_put_req::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "batch_put_req(";
  out << "reqs=" << to_string(reqs);
  out << ")";
}


batch_put_resp::~batch_put_resp() throw() {
}


void batch_put_resp::__set_resps(const std::vector<put_resp> & val) {
  this->resps = val;
}

uint32_t batch_put_resp::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->resps.clear();
            uint32_t _size20;
            ::apache::thrift::protocol::TType _etype23;
            xfer += iprot->readListBegin(_etype23, _size20);
            this->resps.resize(_size20);
            uint32_t _i24;
            for (_i24 = 0; _i24 < _size20; ++_i24)
            {
              xfer += this->resps[_i24].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.resps = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t batch_put_resp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("batch_put_resp");

  xfer += oprot->writeFieldBegin("resps", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->resps.size()));
    std::vector<put_resp> ::const_iterator _iter25;
    for (_iter25 = this->resps.begin(); _iter25 != this->resps.end(); ++_iter25)
    {
      xfer += (*_iter25).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(batch_put_resp &a, batch_put_resp &b) {
  using ::std::swap;
  swap(a.resps, b.resps);
  swap(a.__isset, b.__isset);
}

batch_put_resp::batch_put_resp(const batch_put_resp& other26) {
  resps = other26.resps;
  __isset = other26.__isset;
}
batch_put_resp& batch_put_resp::operator=(const batch_put_resp& other27) {
  resps = other27.resps;
  __isset = other27.__isset;
  return *this;
}
void batch_put_resp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "batch_put_resp(";
  out << "resps=" << to_string(resps);
  out << ")";
}


batch_get_req::~batch_get_req() throw() {
}


void batch_get_req::__set_reqs(const std::vector<get_req> & val) {
  this->reqs = val;
}

uint32_t batch_get_req::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->reqs.clear();
            uint32_t _size28;
            ::apache::thrift::protocol::TType _etype31;
            xfer += iprot->readListBegin(_etype31, _size28);
            this->reqs.resize(_size28);
            uint32_t _i32;
            for (_i32 = 0; _i32 < _size28; ++_i32)
            {
              xfer += this->reqs[_i32].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.reqs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t batch_get_req::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("batch_get_req");

  xfer += oprot->writeFieldBegin("reqs", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->reqs.size()));
    std::vector<get_req> ::const_iterator _iter33;
    for (_iter33 = this->reqs.begin(); _iter33 != this->reqs.end(); ++_iter33)
    {
      xfer += (*_iter33).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(batch_get_req &a, batch_get_req &b) {
  using ::std::swap;
  swap(a.reqs, b.reqs);
  swap(a.__isset, b.__isset);
}

batch_get_req::batch_get_req(const batch_get_req& other34) {
  reqs = other34.reqs;
  __isset = other34.__isset;
}
batch_get_req& batch_get_req::operator=(const batch_get_req& other35) {
  reqs = other35.reqs;
  __isset = other35.__isset;
  return *this;
}
void batch_get_req::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "batch_get_req(";
  out << "reqs=" << to_string(reqs);
  out << ")";
}


batch_get_resp::~batch_get_resp() throw() {
}


void batch_get_resp::__set_resps(const std::vector<get_resp> & val) {
  this->resps = val;
}

uint32_t batch_get_resp::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->resps.clear();
            uint32_t _size36;
            ::apache::thrift::protocol::TType _etype39;
            xfer += iprot->readListBegin(_etype39, _size36);
            this->resps.resize(_size36);
            uint32_t _i40;
            for (_i40 = 0; _i40 < _size36; ++_i40)
            {
              xfer += this->resps[_i40].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.resps = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t batch_get_resp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("batch_get_resp");

  xfer += oprot->writeFieldBegin("resps", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->resps.size()));
    std::vector<get_resp> ::const_iterator _iter41;
    for (_iter41 = this->resps.begin(); _iter41 != this->resps.end(); ++_iter41)
    {
      xfer += (*_iter41).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(batch_get_resp &a, batch_get_resp &b) {
  using ::std::swap;
  swap(a.resps, b.resps);
  swap(a.__isset, b.__isset);
}

batch_get_resp::batch_get_resp(const batch_get_resp& other42) {
  resps = other42.resps;
  __isset = other42.__isset;
}
batch_get_resp& batch_get_resp::operator=(const batch_get_resp& other43) {
  resps = other43.resps;
  __isset = other43.__isset;
  return *this;
}
void batch_get_resp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "batch_get_resp(";
  out << "resps=" << to_string(resps);
  out << ")";
}


batch_remove_req::~batch_remove_req() throw() {
}


void batch_remove_req::__set_reqs(const std::vector<remove_req> & val) {
  this->reqs = val;
}

uint32_t batch_remove_req::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->reqs.clear();
            uint32_t _size44;
            ::apache::thrift::protocol::TType _etype47;
            xfer += iprot->readListBegin(_etype47, _size44);
            this->reqs.resize(_size44);
            uint32_t _i48;
            for (_i48 = 0; _i48 < _size44; ++_i48)
            {
              xfer += this->reqs[_i48].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.reqs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t batch_remove_req::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("batch_remove_req");

  xfer += oprot->writeFieldBegin("reqs", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->reqs.size()));
    std::vector<remove_req> ::const_iterator _iter49;
    for (_iter49 = this->reqs.begin(); _iter49 != this->reqs.end(); ++_iter49)
    {
      xfer += (*_iter49).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(batch_remove_req &a, batch_remove_req &b) {
  using ::std::swap;
  swap(a.reqs, b.reqs);
  swap(a.__isset, b.__isset);
}

batch_remove_req::batch_remove_req(const batch_remove_req& other50) {
  reqs = other50.reqs;
  __isset = other50.__isset;
}
batch_remove_req& batch_remove_req::operator=(const batch_remove_req& other51) {
  reqs = other51.reqs;
  __isset = other51.__isset;
  return *this;
}
void batch_remove_req::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "batch_remove_req(";
  out << "reqs=" << to_string(reqs);
  out << ")";
}


batch_remove_resp::~batch_remove_resp() throw() {
}


void batch_remove_resp::__set_resps(const std::vector<remove_resp> & val) {
  this->resps = val;
}

uint32_t batch_remove_resp::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->resps.clear();
            uint32_t _size52;
            ::apache::thrift::protocol::TType _etype55;
            xfer += iprot->readListBegin(_etype55, _size52);
            this->resps.resize(_size52);
            uint32_t _i56;
            for (_i56 = 0; _i56 < _size52; ++_i56)
            {
              xfer += this->resps[_i56].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.resps = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t batch_remove_resp::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("batch_remove_resp");

  xfer += oprot->writeFieldBegin("resps", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->resps.size()));
    std::vector<remove_resp> ::const_iterator _iter57;
    for (_iter57 = this->resps.begin(); _iter57 != this->resps.end(); ++_iter57)
    {
      xfer += (*_iter57).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(batch_remove_resp &a, batch_remove_resp &b) {
  using ::std::swap;
  swap(a.resps, b.resps);
  swap(a.__isset, b.__isset);
}

batch_remove_resp::batch_remove_resp(const batch_remove_resp& other58) {
  resps = other58.resps;
  __isset = other58.__isset;
}
batch_remove_resp& batch_remove_resp::operator=(const batch_remove_resp& other59) {
  resps = other59.resps;
  __isset = other59.__isset;
  return *this;
}
void batch_remove_resp::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "batch_remove_resp(";
  out << "resps=" << to_string(resps);
  out << ")";
}

}} // namespace
