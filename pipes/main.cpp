#include <cstdlib> //rand, srand, EXIT_FAILURE, EXIT_SUCCESS, atoi
#include <time.h> //time()
#include <iostream> //cout, cin
#include <stdio.h> // arquivos em C
#include <unistd.h> //fork
#include <climits> //INT_MAX
#include <string> //Strings, obviamente


using namespace std;


int generateRandom(int &ln){ //gerando aleatórios de 0 a 2147483647 (RAND_MAX)

	srand(time(NULL));
	ln = rand() + (ln + 1);
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

int main(int argc, int * argv[]) {
    
    int pipeFileDescriptors[2];
    char buffer[100];
    
    if (argc != 2) {
        
        cout << Uso: << argv[0] << " [quantidade de números a ser gerada]" << endl;
        
        return EXIT_FAILURE;
        
    }
    
    if (pipe(pipeFileDescriptors) == -1){
        
        //deu ruim no pipe
        perror("Erro na criação do pipe!") //imprime a mensagem de erro
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
    
    if (pid == 0) { //esse é o filho -> consumidor
    
        close(pipeFileDescriptors[1]); //Fecha o lado de ESCRITA (não usado)
        
        while (true) {
            
            read(pipeFileDescriptors[0], &buffer, 100);
            
            string receivedMessage = buffer;
        
            int receivedValue = atoi(receivedMessage);
            
            cout << "Número " << receivedValue << "recebido." << endl;
            
            if (receivedValue == 0)
                
                break;

            //verificando se é primo
            
            bool receivedValueIsPrime = primeCheck(receivedValue);
            
            
            if (receivedValueIsPrime)
            
                cout << receivedValue << " é primo." << endl;
            
            else
            
                cout << receivedValue << " não é primo" << endl;
            
        
        }
        
        //Finalizando o programa (recebeu 0)
        close(pipeFileDescriptors[0]); //Fecha o lado de LEITURA após o fim da operação
        cout << "Consumidor encerrado."
        return EXIT_SUCCESS;
        
    }
    
    else { //pai -> produtor
        
        close(pipeFileDescriptors[0]); //Fecha o lado de LEITURA (não usado)
        
        int minForRandom = 0;
        
        for (int i = 0; i < argv[1]; i++) { //argv[1] é a quantidade de números a ser gerada,
        //passada como argumento
            
            int numberToBeSent = generateRandom(minForRandom);
            
            string sentMessage = to_string(numberTobeSent);
            
            cout << "Enviando o número " << sentMessage << endl;
            
            write(pipeFileDescriptors[1], sentMessage, sentMessage.size() + 1); //ver se é realmente necessário o +1 (caractere EOF?)
            
            cout << "Número " << sentMessage << " enviado" << endl;
            
        }
        
        
        
        cout << "Fim da geração de números aleatórios. Enviando 0." << endl;
        
        string sentZero = "0";
        
        write(pipeFileDescriptors[1], sentZero, sentZero.size() + 1);
        
        cout << "Zero enviado." << endl;
        
        close(pipeFileDescriptors[1]);
        
        cout << "Produtor encerrado." << endl;
        
        return EXIT_SUCCESS;
        
        
        
    }
    
    
    return EXIT_SUCCESS;
    
}