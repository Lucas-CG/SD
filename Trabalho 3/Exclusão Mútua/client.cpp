#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream> //std::cout
#include <string> //std::string, std::to_string, std::stoi
#include <cstdlib> //rand, srand, EXIT_FAILURE, EXIT_SUCCESS
#include <random> //std::mt19937, uniform_real_distribution
#include <unistd.h> //fork, getpid, sleep
#include <climits> //RAND_MAX
#include <fstream> //std::ofstream

const std::string texts[3] = {"bom dia!", "boa tarde!", "boa noite!"};

void request(ClientSocket & sock, int pid){

	std::string answer;

	std::string pidstring = std::to_string(pid);

	std::string sentString = "REQ" + pidstring;

	sock << sentString;

	sock >> answer;

}

void release(ClientSocket & sock, int pid){
	
	std::string answer;

	std::string pidstring = std::to_string(pid);

	std::string sentString = "REL" + pidstring;

	sock << sentString;

	sock >> answer;

}

int main ( int argc, char* argv[] ) {

	
	if (argc != 3) std::cout << "Uso: ./client [arrival: bulk OR sequential] [número de processos]" << std::endl;

	std::string arrival = argv[1];

	std::string argument2 = argv[2];


	const int nprocs = std::stoi(argument2);

	int childpid = 0;

	//generating N processes
	for (int i = 0; i < nprocs-1; i++) {

		fork();

		if (childpid == 0) break; //filho

		if (arrival == "sequential") sleep(1);

	}

	int ownpid = getpid();

  
	try {      

      ClientSocket client_socket ( "localhost", 30000 );

      string answer;


    	try {

    		for (int i = 0; i < 100; ++i) {

    			srand(ownpid);

    			double waitTime = (double) rand() / ((double) RAND_MAX +1);

    			sleep(waitTime);

	    		request(client_socket, ownpid);

	    		std::ofstream out("output.txt");

	    		out << alguma frase

	    		out.close();

	    		release(client_socket, ownpid);

	    	}

		}

    	catch ( SocketException& e) {
    		std::cout << "Exceção capturada: " << e.description() << std::endl;
    		return EXIT_FAILURE;
    	}


	}

  catch ( SocketException& e ) {

      std::cout << "Exceção capturada: " << e.description() << std::endl;
      return EXIT_FAILURE;

  }

  return EXIT_SUCCESS;

}
