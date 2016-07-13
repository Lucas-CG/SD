#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "MutualExclusion.h"

#include <unistd.h> //fork, getpid()
#include <random> //random number generators / distributions ???
#include <chrono> //std::chrono::steady_clock
#include <iostream> //std::cout, std::endl
#include <string> //std::string
#include <stdint.h> //int32_t

//um adendo: rand não é a coisa mais thread-safe, então acho uma boa usar <random> pra tentar melhorar isso
//(já que aqui aleatoriedade é bem importante)

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace mutualexclusion;


const int numprocs = 128;


void mutexOperation(std::string operation){

  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  MutualExclusionClient client(protocol);
      
  try {
  
    transport->open();    

    try {
   
      if (operation == "request") client.request(getpid());
      if (operation == "release") client.release(getpid());

    }
    
    catch (InvalidOperation& io) {
     
        cout << "InvalidOperation: " << io.why << endl;

    } 

      transport -> close();

  }

  catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }

}


int main(int argc, char** argv) {

  int32_t pid = 0;

  for (int i = 0; i < numprocs-1; i++) {

    pid = fork()

    if (pid == -1) std::cout << "Erro no fork" << std::endl;

    if (pid == 0) break; //children process

  }

  //parent and children do the same task!

  mutexOperation("request");

  //write into file...

  mutexOperation("release");


  return 0

  
}