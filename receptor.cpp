#include <signal.h> //signal, kill
#include <iostream> //cout, cin


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

int main(int argc, char* argv[]){
	
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