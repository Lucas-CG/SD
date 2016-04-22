/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <csignal> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)


using namespace std;

int main(int argc, char* argv[]) {

    int signalCode = 0;
    string temp;

    while (true) {


        cout << "Insira um código de sinal. Opções:" << endl;
        cout << "-(Digite 8) SIGFPE (Floating Point Exception;" << endl;
        cout << "-(Digite 10) SIGUSR1 (User-Defined Signal 1);" << endl;
        cout << "-(Digite 12) SIGUSR2 (User-Defined Signal 2);" << endl;

        getline(cin, temp);

        if ((temp != "8") or (temp != "10") or (temp != "12"))
            cout << "Código inválido, tente novamente." << endl;
        continue;

        stringstream myStream(temp);

        if (myStream >> signalCode)
            cout << "inteiro inserido" << endl;
        break;

        cout << "Código inválido, tente novamente." << endl;

    }


    int x = system("ps aux | grep 'receptor.exe' | head -1 | awk '{print $2}' ");

    kill(x, signalCode);

    return 0;


}