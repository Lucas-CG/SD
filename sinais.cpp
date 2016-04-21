#include <csignal> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include <unistd.h> //fork

using namespace std;

bool signal_handler(int code){
	//modifiquei o tipo de retorno para bool para aproveitar o comportamento em demais locais
	//adicionei o case 17 e o default (erro de digitação)	

	bool wrongCode = false;

	switch(code){
		

		case 8: //SIGFPE: floating point exception
			//fazer algo
			break;

		case 10: //SIGUSR1: user-defined 1
			//fazer algo
			break;

		case 12: //SIGUSR2: user-defined 2
			//fazer algo
			break;

		case 17:  //SIGCHLD: Parada do processo filho
			//fazer algo
			break;

		default:
			cout<< "Código inválido, tente novamente." <<endl;
			wrongCode = true;	

	}

	return wrongCode;
}


int main(int argc, char* argv) {
	
	int child = fork(); //cria processo filho, retorna pid do filho para o pai e 0 para o filho
	//Sinal para encerrar o processo filho: SIGCHLD (17)

	//Emissor

	if (child > 0){

		int signalCode = 0;
		string temp;
		bool wrongCode = true;

		while(wrongCode) {		

			cout << "Insira um código de sinal. Opções:" << endl;
			cout << "-(Digite 8) SIGFPE (Floating Point Exception;" << endl;
			cout << "-(Digite 10) SIGUSR1 (User-Defined Signal 1);" << endl;
			cout << "-(Digite 12) SIGUSR2 (User-Defined Signal 2);" << endl;
			cout << "-(Digite 17) SIGCHLD (Parada de processo filho);" << endl;

			getline(cin, temp);

			signalCode = atoi(temp);

			wrongCode = signal_handler(signalCode);

		}


		kill(child, signalCode); //enviar sinal de código signalCode para filho

	}

	//Receptor
	

	else if (child == 0) {


		void (*handler1)(int);
		
		handler1 = signal(SIGFPE, signal_handler);


		void (*handler2)(int);
		
		handler2 = signal(SIGUSR1, signal_handler);


		void (*handler3)(int);
		
		handler3 = signal(SIGUSR2, signal_handler);

		
		void (*handler4)(int);
		
		handler4 = signal(SIGCHLD, signal_handler);


		while (true) {

			int i = 1;

		}



	}

	else { //child == -1 significa que houve um erro

		cout << "Ocorreu um erro na criação do processo filho. Tente novamente." << endl;

	}

	return 0;

}
