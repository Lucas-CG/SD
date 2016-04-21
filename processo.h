#ifndef PROCESSO_H
#define PROCESSO_H

class Processo{
	private:
		int pid;
	public:
		Processo(); //construtor	
		set_pid(int id);
		get_pid();
		signal_handler(int code);
		send_signal(int pid, int sign);
		receive_signal();
};
#endif