
#ifndef PROCESSOFUNC_H
#define PROCESSOFUNC_H


int get_pid();
static void signal_handler(int code);
void send_signal(int pid, int sign);
void receive_signal();


#endif /* PROCESSOFUNC_H */

