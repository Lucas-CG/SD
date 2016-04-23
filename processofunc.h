#ifndef PROCESSO_H
#define PROCESSO_H

class Processo{
	private:
		int pid;
		bool busyWait;
	public:
		Processo(); //construtor	
		void set_pid(int id);
		int get_pid();
		void signal_handler(int code);
		void send_signal(int pid, int sign);
		void receive_signal();
};
#endif