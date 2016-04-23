#include <cstdlib>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include "pipe.h"

void write(int n){

}

void read(){

}
int geraAleatorio(int range){
	
}

bool verificaPrimo(int n){
	int k = 0;
	for(int i=1; i< n/2; i++){
		if(k > 1){
			return false;
		}
		if(n%i == 0){
			k++;
		}
	}
	return true;
}
