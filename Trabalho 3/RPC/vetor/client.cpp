#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "Calculator.h"

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
  std::vector<std::vector<double> > ret;
  ret.reserve(size);
  double lt[size];
  for (unsigned long int i = 0; i < size; i++){
      lt[i]=(rand() % size + 1);            
  }
  std::vector<double> vec (lt, lt + sizeof(lt) / sizeof(lt[0]) );
  return vec;
}


void getPower(std::vector<double> &vec, int begin, int end){

  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  CalculatorClient client(protocol);
      
  try {
  
    std::vector<double> v (vec.begin() + begin,  vec.end() - end);    

    transport->open();    

    client.ping();
    cout << "ping()" << endl;
      
    try {
      client.power(v, v, 2);    
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


  std::vector<double> vec = generateRandomVector(10000000);
  std::vector<std::thread> threads;  
  int numThreads = 2;
  int partSize = vec.size()/numThreads;

  for (int i = 0; i < numThreads; i++) {   
    threads.push_back( std::thread(getPower,std::ref(vec), i*partSize, (numThreads - i - 1)*partSize) );
  }

  for(auto& th : threads) th.join();
  
  for(auto& value: vec){
    std::cout << value << std::endl;  
  }
}