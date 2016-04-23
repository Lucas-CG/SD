/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   processofunc.h
 * Author: vinicius
 *
 * Created on April 22, 2016, 5:31 PM
 */

#ifndef PROCESSOFUNC_H
#define PROCESSOFUNC_H


int get_pid();
static void signal_handler(int code);
void send_signal(int pid, int sign);
void receive_signal();


#endif /* PROCESSOFUNC_H */

