#include <cstdlib>
#include <time.h>
#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]){
	int ln;
	int range;
	int n;
	srand(time(NULL));
	ln = rand() % range;
	//envia numero para filho

	for(int i = 0; i<n; i++){
		ln = rand() % range + (ln+1);
		//envia numero para filho

		/* filho
			pegar primeiro numero no pipe
			if(verificaPrimo(n)){
				cout << n << " é primo" <<endl;
			}


		*/

	}
	//envia 0 e o filho terminal
}
