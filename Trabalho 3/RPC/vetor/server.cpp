#include "Calculator.h"
#include <thrift/protocol/TBinaryProtocol.h>
//#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>


//multithreaded server
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TNonblockingServer.h>

#include <vector> //std::vector
#include <cmath> //std::pow, std::sqrt, std::log
#include <iostream> //std::cout, std::endl


#include <unistd.h> //sleep para testes

using namespace ::apache::thrift;

using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;


using namespace oparitmeticas;



class CalculatorHandler : virtual public CalculatorIf {
 public:
  CalculatorHandler() {
    // Your initialization goes here
  }

  void ping() {
    // Your implementation goes here
    printf("ping\n");
  }

  void power(std::vector<double> & _return, const std::vector<double> & received, const double exp) {

    for(auto & it : received) {
        _return.push_back(std::pow(it, exp));
    }

    std::cout << "power" << std::endl;
  
  }

  void log(std::vector<double> & _return, const std::vector<double> & received) {
            
    for(auto & it : received) {
        _return.push_back(std::log(it));    
    }

    std::cout << "natural log" << std::endl;
  }

  void root(std::vector<double> & _return, const std::vector<double> & received) {

    for(auto &it : received){
        _return.push_back(std::sqrt(it));
    }
    std::cout << "square root" << std::endl;
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  
  /*

  shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
  shared_ptr<TProcessor> processor(new CalculatorProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

  */


  // using thread pool with maximum 15 threads to handle incoming requests
  shared_ptr<CalculatorHandler> handler(new CalculatorHandler());
  shared_ptr<TProcessor> processor(new CalculatorProcessor(handler));
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(128);
  shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
  threadManager->threadFactory(threadFactory);
  threadManager->start();
  TNonblockingServer server(processor, protocolFactory, port, threadManager);

  
  server.serve();
  return 0;
}