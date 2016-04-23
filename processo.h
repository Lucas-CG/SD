/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   processo.h
 * Author: vinicius
 *
 * Created on April 22, 2016, 5:31 PM
 */

#ifndef PROCESSO_H
#define PROCESSO_H

class processo {
public:
    processo();    
    virtual ~processo();
    void set_pid(int id);
    int get_pid();
    static void signal_handler(int code);
    void send_signal(int pid, int sign);
    void receive_signal();
private:
    int pid;

};

#endif /* PROCESSO_H */

