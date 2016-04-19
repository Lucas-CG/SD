#include <signal.h> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include <unistd.h> //fork

using namespace std;

int child = fork(); //cria processo filho, retorna pid do filho para o pai e 0 para o filho
//Sinal para encerrar o processo filho: SIGCHLD (17)



