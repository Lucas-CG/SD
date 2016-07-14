#include "MutualExclusion.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <thrift/server/TThreadedServer.h>

#include <iostream> //std::cout, std::endl
#include <semaphore.h> //sem_(t, wait, post, init, destroy)
#include <chrono> //std::chrono::system_clock
#include <ctime> //ctime, time_t
#include <string> //std::string
#include <fstream> //std::ofstream

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::mutualexclusion;

using namespace std::chrono;

sem_t mutex;
sem_t mutexLog;

class MutualExclusionHandler : virtual public MutualExclusionIf {
 public:
  MutualExclusionHandler() {

  }
  
  void writeLog(long unsigned t, std::string message){
    
    std::ofstream out;
    out.open("log.txt", std::ofstream::out | std::ofstream::app);
    out << message <<": " << t << " ms\n";
    out.close();
  }

  void request() {
    
    auto now = system_clock::now().time_since_epoch();
    
    auto nowinmillis = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    //time_t now_date = system_clock::to_time_t(now);
    
    sem_wait(&mutexLog);
      
    writeLog(nowinmillis,"REQUEST");
    sem_post(&mutexLog);
    
    sem_wait(&mutex);
    
    //now = system_clock::now();
    //now_date = system_clock::to_time_t(now);
    
    sem_wait(&mutexLog);
    //escreve no log GRANT
    writeLog(nowinmillis,"GRANT");

    sem_post(&mutexLog);
    
  }

  void release() {
    
    //system_clock::time_point now = system_clock::now();
    //time_t now_date = system_clock::to_time_t(now);
    
    auto now = system_clock::now().time_since_epoch();
    
    auto nowinmillis = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();    
    
    sem_post(&mutex);
    sem_wait(&mutexLog);
    //escreve no log RELEASE
    writeLog(nowinmillis,"RELEASE");
    sem_post(&mutexLog);
    
  }

};



int main(int argc, char **argv) {

  sem_init(&mutex,0,1);
  sem_init(&mutexLog,0,1);
    
  int port = 9090;
  
  shared_ptr<MutualExclusionHandler> handler(new MutualExclusionHandler());
  shared_ptr<TProcessor> processor(new MutualExclusionProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TBufferedTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());


  TThreadedServer server (processor,serverTransport,transportFactory,protocolFactory);  
  
  server.serve();
  
  sem_destroy(&mutex);
  sem_destroy(&mutexLog);
    
  return 0;
}

