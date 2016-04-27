#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string>
#include <climits>
#include <time.h>
#include <cstdlib>

using namespace std;

unsigned long long int generateRandomNumber(unsigned long long int &ln)
{
  srand(time(NULL));
    unsigned long long int randomNumber1 = abs(rand());
    unsigned long long int randomNumber2 = abs(rand());
    randomNumber1 = randomNumber1 << (sizeof(int)*8);   
    unsigned long long int resultRandomNumber = (randomNumber1 | randomNumber2) + ln;   
    ln = resultRandomNumber;
    
    return resultRandomNumber;
}


int main ( int argc, char* argv[] )
{
  try
    {

      ClientSocket client_socket ( "localhost", 30000 );

      string reply;

      try
	{
    unsigned long long int minForRandom = 0;
    //gera numeros aleatórios e envia
    for(int i= 0; i< 5; i++){      
      unsigned long long int numbeToBeSent = generateRandomNumber(minForRandom);

      string printedMessage = to_string(numbeToBeSent);

      client_socket << printedMessage;
      client_socket >> reply;

      cout << reply << endl;
    }
	}
      catch ( SocketException& ) {}

      cout << "Resposta recebida do servidor:\n\"" << reply << "\"\n";;

    }
  catch ( SocketException& e )
    {
      cout << "Exceção capturada:" << e.description() << "\n";
    }

  return 0;
}
