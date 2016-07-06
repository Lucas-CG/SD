#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "Calculator.h"

#include <vector> //std::vector
#include <cmath> //std::pow, std::sqrt, std::log
#include <iostream> //std::cout, std::endl
#include <thread>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace oparitmeticas;


void getPower(std::vector<double> &vec, int begin, int end){
  std::vector<double> v (vec.begin() + begin,  vec.end() - end);  
  for(auto& value : v){
    std::cout << value << std::endl;
  }
}

int main(int argc, char** argv) {

  //boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  //boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
  //boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  //CalculatorClient client(protocol);

  static const double lt[] = {2.0, 3.0, 5.0,6.0};
  int sizeList = sizeof(lt)/sizeof(lt[0]);
  std::vector<double> vec (lt, lt + sizeList );
  std::vector<std::thread> threads;
  int numThreads = 2;
  int partSize = sizeList/numThreads;

  for (int i = 0; i < numThreads; i++) {   
    threads.push_back( std::thread(getPower,std::ref(vec), i*partSize, i*partSize) );
  }

  for(auto& th : threads) th.join();

  /*
  try {
    
    transport->open();

    client.ping();
    cout << "ping()" << endl;

    static const double lt[] = {2.0, 3.0, 5.0,6.0};
    long int sizeList = sizeof(lt)/sizeof(lt[0]);
    std::vector<double> vec (lt, lt + sizeList );
    std::vector<std::thread> threads;
    int numThreads = 1;    
    long int partSize = sizeList/numThreads;
    //std::cout<<partSize<<std::endl;

    for(int i=0; i<numThreads; i++){
      threads.push_back(std::thread(getPower,std::ref(vec),i*partSize,(numThreads-i)*partSize));
    }
    //getPower(vec,1,3);

    /*
    try {
      client.power(vec, vec, 2);
      for (auto & it : vec) {
        std::cout << it << std::endl;
      }
    } catch (InvalidOperation& io) {
      cout << "InvalidOperation: " << io.why << endl;
    }
    transport->close();
  
    transport -> close();
  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
  */
}