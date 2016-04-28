#include "ServerSocket.h"
#include "SocketException.h"
#include <string> //std::string, std::stoull
#include <iostream> //std::cout
#include <cstdlib> //EXIT_SUCCESS

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

int main ( int argc, char* argv[] ) {

	std::cout << "Executando...\n";

	try {
    	//Cria o socket
    	ServerSocket server ( 30000 );

    	while ( true ) {

	  		ServerSocket new_sock;
	  		server.accept ( new_sock );

	  		try

	    	{

	    		while ( true )
				
				{
		  			
					string data;
		  
					new_sock >> data;
		  			
					unsigned long long int receivedValue = std::stoull(data);

					if(primeCheck(receivedValue)) {

						cout<< "1" << endl;
						data += " é primo!";

					}

					else {

						cout << "0" << endl;
						data += " não é primo!";

					}

					new_sock << data;

				}

	    	}

	  		catch ( SocketException& ) {}

		}

    }

	catch ( SocketException& e ) {

      cout << "Exceção capturada:" << e.description() << "\nEncerrando.\n";

    }

  return EXIT_SUCCESS;

}
