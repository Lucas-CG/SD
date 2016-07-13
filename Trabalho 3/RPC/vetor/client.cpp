#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "Calculator.h"

#include <chrono>
#include <vector> //std::vector
#include <cmath> //std::pow, std::sqrt, std::log
#include <iostream> //std::cout, std::endl
#include <thread>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace oparitmeticas;


std::vector<double> generateRandomVector(int size) {
  srand(time(NULL));
  std::vector<double> ret;
  ret.reserve(size);
  for (unsigned long int i = 0; i < size; i++){
      ret.push_back(rand() % size + 1);            
  }
  return ret;
}

void doOperation(std::vector<double> &vec, int begin, int end, int operation,int expoent){

  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  CalculatorClient client(protocol);
      
  try {
  
    std::vector<double> v (vec.begin() + begin,  vec.end() - end);    

    transport->open();        
      
    try {

      switch(operation){
        case 1:
          client.power(v, v, expoent);
          break;
        case 2:
          client.log(v,v);
          break;
        case 3:
          client.root(v,v);
          break;                  
      }         

      for(int i=0; i< v.size(); i++){
        vec.at(begin + i) = v.at(i);
      }    
      } catch (InvalidOperation& io) {
        cout << "InvalidOperation: " << io.why << endl;
      }  
      transport -> close();

  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
}


int main(int argc, char** argv) {  

  const std::string argument1 = argv[1];
  int operation = stoi(argument1);  

  const std::string argument2 = argv[2];
  unsigned long int numThreads = stoi(argument2);    

  int expoent;

  if(argc == 4){
    const std::string argument3 = argv[3];
    expoent = stoi(argument3);
  } 
  else{
    expoent = 2;
  } 

  std::vector<double> vec = generateRandomVector(100000000);
  std::vector<std::thread> threads;  
  int partSize = vec.size()/numThreads;

  auto startTime = std::chrono::steady_clock::now();

  for (int i = 0; i < numThreads; i++) {       
    threads.push_back( std::thread(doOperation,std::ref(vec), i*partSize, (numThreads - i - 1)*partSize,std::ref(operation),std::ref(expoent)) );  
  }

  for(auto& th : threads) th.join();
 
  auto endTime = std::chrono::steady_clock::now(); 
  std::cout << "Tempo de execução: "<<std::chrono::duration<double, std::milli>(endTime - startTime).count() << std::endl; 
}