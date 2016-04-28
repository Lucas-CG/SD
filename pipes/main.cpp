#include <cstdlib> //rand, srand, EXIT_FAILURE, EXIT_SUCCESS
#include <time.h> //time()
#include <iostream> //std::cout, std::cin
#include <stdio.h> // arquivos em C
#include <unistd.h> //fork
#include <string> //std::string, std::stoi, std::stoull, std::to_string


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

int main(int argc, char * argv[]) {
    
    int pipeFileDescriptors[2];
    char buffer[64];
    
    if (argc != 2) {
        
        cout << "Uso: " << argv[0] << " [quantidade de números a ser gerada]" << endl;
        
        return EXIT_FAILURE;
        
    }
    
    if (pipe(pipeFileDescriptors) == -1){
        
        //erro no pipe
        perror("Erro na criação do pipe!"); //imprime a mensagem de erro
        return EXIT_FAILURE;
        
    }
    
    
    //Criando subprocesso DEPOIS de criar o pipe, para os dois processos terem
    //os dois lados do pipe
    
    int pid = fork();
    
    if(pid == -1) {
        
        perror("Erro na criação do fork!");
        return EXIT_FAILURE;
        
    }
    
    if (pid == 0) { //processo filho -> CONSUMIDOR
    
        close(pipeFileDescriptors[1]); //Fecha o lado do pipe de ESCRITA (não usado)
        
        while (true) {
            
            read(pipeFileDescriptors[0], &buffer, 65);
            
            const string receivedMessage = buffer;
        
            unsigned long long int receivedValue = stoull(receivedMessage);
            
            cout << "CONSUMIDOR: Número " << receivedValue << " recebido." << endl;
            
            if (receivedMessage == "0")
                
                break;

            //verificando se é primo
            
            bool receivedValueIsPrime = primeCheck(receivedValue);
            
            
            if (receivedValueIsPrime)
            
                cout << "CONSUMIDOR: " << receivedValue << " é primo." << endl;
            
            else
            
                cout << "CONSUMIDOR: " << receivedValue << " não é primo" << endl;
            
        
        }
        
        //Finalizando o programa (recebeu 0)
        close(pipeFileDescriptors[0]); //Fecha o lado de LEITURA após o fim da operação
        cout << "CONSUMIDOR: Encerrado." << endl;
        return EXIT_SUCCESS;
        
    }
    
    else { //pai -> produtor
        
        close(pipeFileDescriptors[0]); //Fecha o lado de LEITURA (não usado)
        
        unsigned long long int minForRandom = 0;

        //argv[1] (argumento) é a quantidade de números a ser gerada
        const string argument = argv[1];

        int generatedAmount = stoi(argument);
        
        for (int i = 0; i < generatedAmount; i++) {
                    
            unsigned long long int numberToBeSent = generateRandomNumber(minForRandom);
            
            string printedMessage = to_string(numberToBeSent);

            //convertendo para string do C
            const char* sentMessage = printedMessage.c_str();


            cout << "PRODUTOR: Enviando o número " << printedMessage << endl;
            
            write(pipeFileDescriptors[1], sentMessage, printedMessage.size() + 1);

            //+1: byte NULL adicional no fim de strings do C
            
            cout << "PRODUTOR: Número " << printedMessage << " enviado" << endl;

            sleep(1);
            
        }
        
        
        
        cout << "PRODUTOR: Fim da geração de números aleatórios. Enviando 0." << endl;
        
        string zeroString = "0";

        const char* sentZero = zeroString.c_str();
        
        write(pipeFileDescriptors[1], sentZero, zeroString.size() + 1);
        
        cout << "PRODUTOR: Zero enviado." << endl;
        
        close(pipeFileDescriptors[1]);
        
        cout << "PRODUTOR: Encerrado." << endl;
        
        return EXIT_SUCCESS;
        
        
        
    }
    
    
    return EXIT_SUCCESS;
    
}