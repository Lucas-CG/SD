#include "MutualExclusion.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

//multithreaded server -?
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TNonblockingServer.h>


#include <vector>
#include <iostream>
#include <stdint.h> //int32_t

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::mutualexclusion;

class MutualExclusionHandler : virtual public MutualExclusionIf {
 public:
  MutualExclusionHandler() {
    
    //inicializar o vetor???

  }

  void request(const int32_t procID) {
    // Your implementation goes here
    printf("request\n");
  }

  void release(const int32_t procID) {
    // Your implementation goes here
    printf("release\n");
  }

 private:
  std::vector<int> pendingRequests;

};

int main(int argc, char **argv) {

  int port = 9090;

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

