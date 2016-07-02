/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Example_H
#define Example_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "example_types.h"

namespace Example {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ExampleIf {
 public:
  virtual ~ExampleIf() {}
  virtual void ping() = 0;
  virtual void printMessage() = 0;
};

class ExampleIfFactory {
 public:
  typedef ExampleIf Handler;

  virtual ~ExampleIfFactory() {}

  virtual ExampleIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ExampleIf* /* handler */) = 0;
};

class ExampleIfSingletonFactory : virtual public ExampleIfFactory {
 public:
  ExampleIfSingletonFactory(const boost::shared_ptr<ExampleIf>& iface) : iface_(iface) {}
  virtual ~ExampleIfSingletonFactory() {}

  virtual ExampleIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ExampleIf* /* handler */) {}

 protected:
  boost::shared_ptr<ExampleIf> iface_;
};

class ExampleNull : virtual public ExampleIf {
 public:
  virtual ~ExampleNull() {}
  void ping() {
    return;
  }
  void printMessage() {
    return;
  }
};


class Example_ping_args {
 public:

  Example_ping_args(const Example_ping_args&);
  Example_ping_args& operator=(const Example_ping_args&);
  Example_ping_args() {
  }

  virtual ~Example_ping_args() throw();

  bool operator == (const Example_ping_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Example_ping_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Example_ping_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Example_ping_pargs {
 public:


  virtual ~Example_ping_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Example_ping_result {
 public:

  Example_ping_result(const Example_ping_result&);
  Example_ping_result& operator=(const Example_ping_result&);
  Example_ping_result() {
  }

  virtual ~Example_ping_result() throw();

  bool operator == (const Example_ping_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Example_ping_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Example_ping_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Example_ping_presult {
 public:


  virtual ~Example_ping_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class Example_printMessage_args {
 public:

  Example_printMessage_args(const Example_printMessage_args&);
  Example_printMessage_args& operator=(const Example_printMessage_args&);
  Example_printMessage_args() {
  }

  virtual ~Example_printMessage_args() throw();

  bool operator == (const Example_printMessage_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Example_printMessage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Example_printMessage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Example_printMessage_pargs {
 public:


  virtual ~Example_printMessage_pargs() throw();

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Example_printMessage_result {
 public:

  Example_printMessage_result(const Example_printMessage_result&);
  Example_printMessage_result& operator=(const Example_printMessage_result&);
  Example_printMessage_result() {
  }

  virtual ~Example_printMessage_result() throw();

  bool operator == (const Example_printMessage_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const Example_printMessage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Example_printMessage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Example_printMessage_presult {
 public:


  virtual ~Example_printMessage_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ExampleClient : virtual public ExampleIf {
 public:
  ExampleClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ExampleClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void printMessage();
  void send_printMessage();
  void recv_printMessage();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ExampleProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<ExampleIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ExampleProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_ping(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_printMessage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ExampleProcessor(boost::shared_ptr<ExampleIf> iface) :
    iface_(iface) {
    processMap_["ping"] = &ExampleProcessor::process_ping;
    processMap_["printMessage"] = &ExampleProcessor::process_printMessage;
  }

  virtual ~ExampleProcessor() {}
};

class ExampleProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ExampleProcessorFactory(const ::boost::shared_ptr< ExampleIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< ExampleIfFactory > handlerFactory_;
};

class ExampleMultiface : virtual public ExampleIf {
 public:
  ExampleMultiface(std::vector<boost::shared_ptr<ExampleIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ExampleMultiface() {}
 protected:
  std::vector<boost::shared_ptr<ExampleIf> > ifaces_;
  ExampleMultiface() {}
  void add(boost::shared_ptr<ExampleIf> iface) {
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

  void printMessage() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->printMessage();
    }
    ifaces_[i]->printMessage();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ExampleConcurrentClient : virtual public ExampleIf {
 public:
  ExampleConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ExampleConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void printMessage();
  int32_t send_printMessage();
  void recv_printMessage(const int32_t seqid);
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
