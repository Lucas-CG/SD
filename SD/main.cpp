/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vinicius
 *
 * Created on April 22, 2016, 4:30 PM
 */

#include <iostream> //cout, cin
#include <csignal> //signal, kill
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include "processofunc.h"
#include <climits>
#include <unistd.h>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    while (true) {
        cout << "O pid do processo é: " << get_pid() << endl;
        cout << "Escolha uma das opções a seguir:" << endl;
        cout << "Para enviar sinal digite 1:" << endl;
        cout << "Para receber sinal digite 2:" << endl;
        cout << "Para encerrar o programa digite 9:" << endl;

        int c;
        cin >> c;

        switch (c) {
            case 1:
                try {
                    int s;
                    int id;
                    cout << "Digite o pid do processo destino" << endl;
                    cin >> id;
                    cout << "Digite o tipo de sinal que deseja enviar" << endl;
                    cin >> s;
                    send_signal(id, s);
                }                catch (const char *msg) {
                    cerr << msg << endl << endl;
                }
                break;

            case 2:

                cout << "Escolha o tipo de espera: 0 para ocupada ou 1 bloqueante" << endl;
                int waitType;
                cin >> waitType;

                receive_signal();
                if(waitType == 0){
                    while(true){
                        cout << "Aguardando sinal ..." << endl;                        
                    }
                }
                else if(waitType == 1){                    
                    sleep(INT_MAX);
                }
                

                break;

            case SIGKILL:
                cout << "Programa encerrado" << endl;
                raise(SIGKILL);
                break;

            default:
                cout << "Opção escolhida inexistente, tente outra vez!" << endl << endl;

        }
    }

    return 0;
}

