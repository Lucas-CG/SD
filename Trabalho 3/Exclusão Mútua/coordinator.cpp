#include "ServerSocket.h"
#include "SocketException.h"
#include <string> //std::string, std::stoi, string::substr
#include <iostream> //std::cout
#include <cstdlib> //EXIT_SUCCESS
#include <queue> //std::queue

void attendRequest(ServerSocket & sock, std::queue<ServerSocket> & q){

	if ( q.empty() ) sock << "GRANT";

	q.push(sock);

}

void attendRelease(std::queue<ServerSocket> & q){

	q.pop();

	if ( !q.empty() ) {

		ServerSocket sock = q.front();

		sock << "GRANT";

	}

}

int main ( int argc, char* argv[] ) {

	std::cout << "Executando..." << std::endl;

	std::queue<ServerSocket> executionQueue;

	try {
    	//Socket creation
    	ServerSocket server (30000);

    	while (true) {

	  		ServerSocket new_sock;
	  		server.accept ( new_sock );

	  		try

	    	{

				std::string data;
		  
				new_sock >> data;

				int pid = std::stoi(data.substr(3));

				if (data.substr(0, 3) == "REQ") attendRequest(new_sock, pid, executionQueue);
				if (data.substr(0, 3) == "REL") attendRelease(new_sock, pid, executionQueue);
		  			

				}

	    	}

	  		catch ( SocketException& e ) {

		      cout << "Exceção capturada:" << e.description() << "\nEncerrando.\n";
		      return EXIT_FAILURE;

	  		}

		}

    }

	catch ( SocketException& e ) {

      cout << "Exceção capturada:" << e.description() << "\nEncerrando.\n";
      return EXIT_FAILURE;

    }

  return EXIT_SUCCESS;

}
