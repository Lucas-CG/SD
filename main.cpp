#include <csignal> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include "processo.h"


int main(int argc, char* argv[]) {
	
	Processo p;
	
	std::cout << p.get_pid() << std::endl;

	return 0;

}