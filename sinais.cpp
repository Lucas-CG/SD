#include <signal.h> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include <unistd.h> //fork

using namespace std;

void signal_handler(int code){

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


	}

}


int main(int argc, char* argv) {
	
	int child = fork(); //cria processo filho, retorna pid do filho para o pai e 0 para o filho
	//Sinal para encerrar o processo filho: SIGCHLD (17)

	//Emissor

	if (child > 0){

		int signalCode = 0;
		string temp;
		
		while(true) {


			cout << "Insira um código de sinal. Opções:" << endl;
			cout << "-(Digite 8) SIGFPE (Floating Point Exception;" << endl;
			cout << "-(Digite 10) SIGUSR1 (User-Defined Signal 1);" << endl;
			cout << "-(Digite 12) SIGUSR2 (User-Defined Signal 2);" << endl;
			cout << "-(Digite 17) SIGCHLD (Parada de processo filho);" << endl;

			getline(cin, temp);

			signalCode = atoi(temp);

			if ( (signalCode != 8) or (signalCode != 10) or (signalCode != 12) ) {
				
				cout << "Código inválido, tente novamente." << endl;

				continue;
			
			}

			break;
		
		}


		int x = system("ps aux | grep 'receptor.exe' | head -1 | awk '{print $2}' ");

		kill(x, signalCode);
		
		return 0;

	}

	//Receptor
	

	else if (child == 0) {


		void (*handler1)(int);
		
		handler1 = signal(SIGFPE, signal_handler);


		void (*handler2)(int);
		
		handler2 = signal(SIGUSR1, signal_handler);


		void (*handler3)(int);
		
		handler3 = signal(SIGUSR2, signal_handler);


		while (true) {

			int i = 1;

		}

		return 0;


	}

	else { //child == -1 significa que houve um erro

		cout << "Ocorreu um erro na criação do processo filho. Tente novamente." << endl;
		return;

	}


}
