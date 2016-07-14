#include "MutualExclusion.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <thrift/server/TThreadedServer.h>

#include <vector>
#include <iostream>
#include <stdint.h> //int32_t
#include <semaphore.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::mutualexclusion;

sem_t mutex;

class MutualExclusionHandler : virtual public MutualExclusionIf {
 public:
  MutualExclusionHandler() {

  }

  void request() {
    // Your implementation goes here
    sem_wait(&mutex);
    return;
    
  }

  void release() {
    // Your implementation goes here
    sem_post(&mutex);
    
  }

 private:
  std::vector<int> pendingRequests;

};


int main(int argc, char **argv) {

  sem_init(&mutex,0,1);    
    
  int port = 9090;
  
  shared_ptr<MutualExclusionHandler> handler(new MutualExclusionHandler());
  shared_ptr<TProcessor> processor(new MutualExclusionProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TBufferedTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());


  TThreadedServer server (processor,serverTransport,transportFactory,protocolFactory);  
  
  server.serve();
  
  sem_destroy(&mutex);
  
  return 0;
}

