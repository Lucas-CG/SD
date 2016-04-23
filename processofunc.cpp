#include <csignal> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include <unistd.h> //fork, getpid
#include "processo.h"

using namespace std;

Processo::Processo(){
	//construtor
	set_pid(getpid());
	busyWait = false;
}

void Processo::set_pid(int id){
	pid = id;
}

int Processo::get_pid(){
	return pid;
}

void Processo::signal_handler(int code){	
	switch(code){	

		case 8: //SIGFPE: floating point exception
			//encerrar o processo
			cout << "Case 8" << endl;
			break;

		case 10: //SIGUSR1: user-defined 1: busyWait
			busyWait = true;

			//while

			break;

		case 12: //SIGUSR2: user-defined 2
			//fazer algo
			break;

		case 17:  //SIGCHLD: Parada do processo filho
			//fazer algo
			break;

		default:
			cout<< "Código inválido, tente novamente." <<endl;
	}
}

void Processo::send_signal(int pid, int sinal){

	int aswer;

	aswer =  kill(pid, sign);

	if(aswer != 0){
		throw "Processo destino inexistente!";		
	}
}

void Processo::receive_signal(){
	void (*handler1)(int);
		
	handler1 = signal(SIGFPE, signal_handler);


	void (*handler2)(int);
	
	handler2 = signal(SIGUSR1, signal_handler);


	void (*handler3)(int);
	
	handler3 = signal(SIGUSR2, signal_handler);

	
	void (*handler4)(int);
	
	handler4 = signal(SIGCHLD, signal_handler);

}

};