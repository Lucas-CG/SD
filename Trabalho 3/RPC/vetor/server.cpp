#include "Calculator.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/server/TThreadedServer.h>

#include <vector> //std::vector
#include <cmath> //std::pow, std::sqrt, std::log
#include <iostream> //std::cout, std::endl


using namespace ::apache::thrift;

using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;


using namespace oparitmeticas;

class CalculatorHandler : virtual public CalculatorIf {
 public:
  CalculatorHandler() {}

  void ping() {
    printf("ping\n");
  }

  void power(std::vector<double> & _return, const std::vector<double> & received, const double exp) {

    for(auto & it : received) {
        _return.push_back(std::pow(it, exp));
    }    
  
  }

  void log(std::vector<double> & _return, const std::vector<double> & received) {
            
    for(auto & it : received) {
        _return.push_back(std::log(it));    
    }    
  }

  void root(std::vector<double> & _return, const std::vector<double> & received) {

    for(auto &it : received){
        _return.push_back(std::sqrt(it));
    }    
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  
  shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
  shared_ptr<TProcessor> processor(new CalculatorProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TBufferedTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());


  TThreadedServer server (processor,serverTransport,transportFactory,protocolFactory);  
  
  server.serve();
  

  return 0;
}