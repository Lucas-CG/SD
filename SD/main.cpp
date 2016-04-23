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

#include <iostream>
#include <csignal> //signal, kill
#include <stdlib.h> //atoi (string para inteiro), comando "system"
#include <string> //strings, getline
#include <sstream> //criar sstream (para converter string p int)
#include "processo.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    processo p;

    cout << p.get_pid() << endl;
    
    p.send_signal(p.get_pid(), SIGCHLD);
    
    return 0;
}

