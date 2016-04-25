#include <cstdlib> //rand, srand, EXIT_FAILURE, EXIT_SUCCESS
#include <time.h> //time()
#include <iostream> //std::cout, std::cin
#include <stdio.h> // arquivos em C
#include <unistd.h> //fork
#include <climits> //INT_MAX
#include <string> //std::string, std::stoi, std::to_string

//Coisas a verificar: por que generateRandom está gerando números negativos?
//                    por que o programa entra em loop quando especifico a geração de APENAS 5 números?


using namespace std;


int generateRandom(int &ln){ //gerando aleatórios de 1 a 2147483647 (RAND_MAX)

	srand(time(NULL));
	ln = ( 1 + rand() ) + (ln + 1);

    cout << "PRODUTOR: Número " << ln << "gerado" << endl;

	return ln;
	
}

bool primeCheck(int n){

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
    char buffer[100];
    
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
        
        //que bad...
        
        perror("Erro na criação do fork!");
        return EXIT_FAILURE;
        
    }
    
    if (pid == 0) { //processo filho -> CONSUMIDOR
    
        close(pipeFileDescriptors[1]); //Fecha o lado do pipe de ESCRITA (não usado)
        
        while (true) {
            
            read(pipeFileDescriptors[0], &buffer, 100);
            
            const string receivedMessage = buffer;
        
            int receivedValue = stoi(receivedMessage);
            
            cout << "CONSUMIDOR: Número " << receivedValue << " recebido." << endl;
            
            if (receivedValue == 0)
                
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
        
        int minForRandom = 0;

        const string argument = argv[1];
        int generatedAmount = stoi(argument);
        
        for (int i = 0; i < generatedAmount; i++) { //argv[1] é a quantidade de números a ser gerada,
        //passada como argumento
            
            int numberToBeSent = generateRandom(minForRandom);
            
            string printedMessage = to_string(numberToBeSent);

            const char* sentMessage = printedMessage.c_str(); //convertendo para string do C


            cout << "PRODUTOR: Enviando o número " << printedMessage << endl;
            
            write(pipeFileDescriptors[1], sentMessage, printedMessage.size() + 1);

            //+1: byte NULL adicional no fim de strings do C
            
            cout << "PRODUTOR: Número " << printedMessage << " enviado" << endl;
            
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