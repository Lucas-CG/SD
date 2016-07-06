/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Calculator_H
#define Calculator_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "calculator_types.h"

namespace oparitmeticas {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class CalculatorIf {
 public:
  virtual ~CalculatorIf() {}
  virtual void ping() = 0;
  virtual int32_t calculate(const Work& w) = 0;
};

class CalculatorIfFactory {
 public:
  typedef CalculatorIf Handler;

  virtual ~CalculatorIfFactory() {}

  virtual CalculatorIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(CalculatorIf* /* handler */) = 0;
};

class CalculatorIfSingletonFactory : virtual public CalculatorIfFactory {
 public:
  CalculatorIfSingletonFactory(const boost::shared_ptr<CalculatorIf>& iface) : iface_(iface) {}
  virtual ~CalculatorIfSingletonFactory() {}

  virtual CalculatorIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(CalculatorIf* /* handler */) {}

 protected:
  boost::shared_ptr<CalculatorIf> iface_;
};

class CalculatorNull : virtual public CalculatorIf {
 public:
  virtual ~CalculatorNull() {}
  void ping() {
    return;
  }
  int32_t calculate(const Work& /* w */) {
    int32_t _return = 0;
    return _return;
  }
};


class Calculator_ping_args {
 public:

  Calculator_ping_args(const Calculator_ping_args&);
  Calculator_ping_args& operator=(const Calculator_ping_args&);
  Calculator_ping_args() {
  }

  virtual ~Calculator_ping_args() throw();

  bool operator == (const Calculator_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Calculator_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_ping_pargs {
 public:


  virtual ~Calculator_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_ping_result {
 public:

  Calculator_ping_result(const Calculator_ping_result&);
  Calculator_ping_result& operator=(const Calculator_ping_result&);
  Calculator_ping_result() {
  }

  virtual ~Calculator_ping_result() throw();

  bool operator == (const Calculator_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Calculator_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_ping_presult {
 public:


  virtual ~Calculator_ping_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Calculator_calculate_args__isset {
  _Calculator_calculate_args__isset() : w(false) {}
  bool w :1;
} _Calculator_calculate_args__isset;

class Calculator_calculate_args {
 public:

  Calculator_calculate_args(const Calculator_calculate_args&);
  Calculator_calculate_args& operator=(const Calculator_calculate_args&);
  Calculator_calculate_args() {
  }

  virtual ~Calculator_calculate_args() throw();
  Work w;

  _Calculator_calculate_args__isset __isset;

  void __set_w(const Work& val);

  bool operator == (const Calculator_calculate_args & rhs) const
  {
    if (!(w == rhs.w))
      return false;
    return true;
  }
  bool operator != (const Calculator_calculate_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_calculate_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Calculator_calculate_pargs {
 public:


  virtual ~Calculator_calculate_pargs() throw();
  const Work* w;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_calculate_result__isset {
  _Calculator_calculate_result__isset() : success(false), ouch(false) {}
  bool success :1;
  bool ouch :1;
} _Calculator_calculate_result__isset;

class Calculator_calculate_result {
 public:

  Calculator_calculate_result(const Calculator_calculate_result&);
  Calculator_calculate_result& operator=(const Calculator_calculate_result&);
  Calculator_calculate_result() : success(0) {
  }

  virtual ~Calculator_calculate_result() throw();
  int32_t success;
  InvalidOperation ouch;

  _Calculator_calculate_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_ouch(const InvalidOperation& val);

  bool operator == (const Calculator_calculate_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(ouch == rhs.ouch))
      return false;
    return true;
  }
  bool operator != (const Calculator_calculate_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Calculator_calculate_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Calculator_calculate_presult__isset {
  _Calculator_calculate_presult__isset() : success(false), ouch(false) {}
  bool success :1;
  bool ouch :1;
} _Calculator_calculate_presult__isset;

class Calculator_calculate_presult {
 public:


  virtual ~Calculator_calculate_presult() throw();
  int32_t* success;
  InvalidOperation ouch;

  _Calculator_calculate_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CalculatorClient : virtual public CalculatorIf {
 public:
  CalculatorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  CalculatorClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  void send_ping();
  void recv_ping();
  int32_t calculate(const Work& w);
  void send_calculate(const Work& w);
  int32_t recv_calculate();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class CalculatorProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<CalculatorIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CalculatorProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_calculate(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CalculatorProcessor(boost::shared_ptr<CalculatorIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &CalculatorProcessor::process_ping;
    processMap_["calculate"] = &CalculatorProcessor::process_calculate;
  }

  virtual ~CalculatorProcessor() {}
};

class CalculatorProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CalculatorProcessorFactory(const ::boost::shared_ptr< CalculatorIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CalculatorIfFactory > handlerFactory_;
};

class CalculatorMultiface : virtual public CalculatorIf {
 public:
  CalculatorMultiface(std::vector<boost::shared_ptr<CalculatorIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~CalculatorMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CalculatorIf> > ifaces_;
  CalculatorMultiface() {}
  void add(boost::shared_ptr<CalculatorIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void ping() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->ping();
    }
    ifaces_[i]->ping();
  }

  int32_t calculate(const Work& w) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->calculate(w);
    }
    return ifaces_[i]->calculate(w);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class CalculatorConcurrentClient : virtual public CalculatorIf {
 public:
  CalculatorConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  CalculatorConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void ping();
  int32_t send_ping();
  void recv_ping(const int32_t seqid);
  int32_t calculate(const Work& w);
  int32_t send_calculate(const Work& w);
  int32_t recv_calculate(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif