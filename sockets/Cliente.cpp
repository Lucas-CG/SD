#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream> //std::cout
#include <string> //std::string, std::to_string
#include <ctime> //time()
#include <cstdlib> //rand, srand, EXIT_FAILURE, EXIT_SUCCESS

using namespace std;

unsigned long long int generateRandomNumber(unsigned long long int &ln) {

    //muda a "semente" usada no cálculo de números aleatórios para a hora atual
    srand(time(NULL));

    //rand: cálculo de 2 números aleatórios inteiros (32 bits cada)
    //e os armazena em números de 64 bits
    unsigned long long int randomNumber1 = abs(rand());
    unsigned long long int randomNumber2 = abs(rand());

    //deslocamento à esquerda de 32 bits do primeiro número
    randomNumber1 = randomNumber1 << (sizeof(int) * 8);   

    //concatena os dois números de 32 bits, formando um de 64
    unsigned long long int result = (randomNumber1 | randomNumber2) + ln;
    ln = result;
    
    return result;

}


int main ( int argc, char* argv[] )
{
  try {      

      ClientSocket client_socket ( "localhost", 30000 );

      string answer;

      try {

        unsigned long long int minForRandom = 0;

        //gera numeros aleatórios e envia
        for(int i = 0; i < 200; i++){  

          unsigned long long int numberToBeSent = generateRandomNumber(minForRandom);

          string printedMessage = to_string(numberToBeSent);

          client_socket << printedMessage;
          client_socket >> answer;

          cout << answer << endl;

        }

        client_socket << "0";
        client_socket >> answer;

	    }

      catch ( SocketException& ) {}

      cout << "Resposta recebida do servidor:\n\"" << answer << "\"\n";;

  }

  catch ( SocketException& e ) {

      cout << "Exceção capturada: " << e.description() << "\n";

  }

  return EXIT_SUCCESS;

}
