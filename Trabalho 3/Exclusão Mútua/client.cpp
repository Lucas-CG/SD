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
#include <cstdlib> //rand, srand
#include <fstream> //std::ofstream


using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace mutualexclusion;


void mutexOperation(){

  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  MutualExclusionClient client(protocol);
      
  try {
  
    transport->open();    

    try {
      
        int ownpid = getpid();
        
        std::string message = "Processo " + std::to_string(ownpid) + " presente!";

        srand(ownpid);
        
      for (int i = 0; i < 100; ++i) {
    
        double waitTime = (double) rand() / ((double) RAND_MAX +1);
    
        sleep(waitTime);
        
        client.request();
        
        std::ofstream out;
        out.open("output.txt", std::ofstream::out | std::ofstream::app);
        out << message << "\n";
        out.close();
        
        client.release();
    
      }
      

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

  if (argc != 3) std::cout << "Uso: ./client [arrival: bulk OR sequential] [número de processos]" << std::endl;

  std::string arrival = argv[1];

  std::string argument2 = argv[2];
  
  const int numprocs = std::stoi(argument2);


  int32_t pid = 0;

  for (int i = 0; i < numprocs-1; i++) {
      
    int32_t childpid = 0;

    childpid = fork();

    if (childpid == -1) std::cout << "Erro no fork" << std::endl;

    if (childpid == 0) break; //children process
    
    if (arrival == "sequential") sleep(1);

  }
    
  mutexOperation();      
  return 0;

  
}