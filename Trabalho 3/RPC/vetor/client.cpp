#include <iostream>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "Calculator.h"

#include <vector> //std::vector
#include <cmath> //std::pow, std::sqrt, std::log
#include <iostream> //std::cout, std::endl

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace oparitmeticas;

int main() {
  
  
/*

  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
  CalculatorClient client(protocol);

*/


  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
  boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  CalculatorClient client(protocol);

    
  try {
    transport->open();

    client.ping();
    cout << "ping()" << endl;

    static const double lt[] = {2.0, 3.0, 5.0};
    std::vector<double> vec (lt, lt + sizeof(lt) / sizeof(lt[0]) );

    try {
      client.power(vec, vec, 2);
      for (auto & it : vec) {
        std::cout << it << std::endl;
      }
    } catch (InvalidOperation& io) {
      cout << "InvalidOperation: " << io.why << endl;
    }
    transport->close();
  } catch (TException& tx) {
    cout << "ERROR: " << tx.what() << endl;
  }
}