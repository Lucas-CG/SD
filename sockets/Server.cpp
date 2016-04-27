#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

using namespace std;

bool primeCheck(unsigned long long n){

	int k = 0;
	
	for(int i = 1; i < n/2; i++){
	    
		if(k > 1)
		
			return false;
			
		if(n % i == 0)
		
			k++;
			
	}
	
	return true;
	
}

int main ( int argc, char* argv[] )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  string data;
		  
		  new_sock >> data;
		  unsigned long long int receivedValue = std::stoull(data);

		  if(primeCheck(receivedValue)){
		  	cout<< "1" << endl;
		  	data += " É primo!";
		  }
		  else{
		  	cout << "0" << endl;
		  	data += " Não é primo!";
		  }
		  new_sock << data;
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
