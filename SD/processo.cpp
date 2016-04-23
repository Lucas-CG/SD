/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   processo.cpp
 * Author: vinicius
 * 
 * Created on April 22, 2016, 5:31 PM
 */

#include <csignal> //signal, kill
#include <iostream> //cout, cin
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include <unistd.h> //fork, getpid
#include "processo.h"

using namespace std;

processo::processo() {
    set_pid(getpid());
    
}

processo::~processo() {
}

void processo::set_pid(int id) {
    processo::pid = id;
}

int processo::get_pid() {
    return processo::pid;
}

void processo::signal_handler(int code) {
    switch (code) {

        case SIGFPE: //SIGFPE: floating point exception
            //encerrar o processo
            cout << "Case 8" << endl;
            break;

        case SIGUSR1: //SIGUSR1: user-defined 1: busyWait
           
            //while

            break;

        case SIGUSR2: //SIGUSR2: user-defined 2
            //fazer algo
            break;

        case SIGCHLD: //SIGCHLD: Parada do processo filho
            //fazer algo
            break;

        default:
            cout << "Código inválido, tente novamente." << endl;
    }
}

void processo::send_signal(int pid, int sinal) {
    
    int aswer = kill(pid, sinal);

    if (aswer != 0) {
        throw "Processo destino inexistente!";
    }
}

void processo::receive_signal() {
    void (*handler1)(int);

    handler1 = signal(SIGFPE, signal_handler);


    void (*handler2)(int);

    handler2 = signal(SIGUSR1, signal_handler);


    void (*handler3)(int);

    handler3 = signal(SIGUSR2, signal_handler);


    void (*handler4)(int);

    handler4 = signal(SIGCHLD, signal_handler);

}

