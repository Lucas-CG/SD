#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <ctime> 			//std::time_t, time (apenas para gerar os aleatórios)
#include <vector> 			//std::vector
#include <cstdlib> 			//stoi, stoul, rand, srand
#include <string>			//std::string
#include <chrono>			//std::chrono
#include <functional>		//std::ref

std::mutex mtxVct;
std::condition_variable cvc;


unsigned int generateRandomNumber()
{
	srand(time(NULL));
    unsigned int resultRandomNumber = (rand() % 10000000);      
    
    return resultRandomNumber;
}



bool primeCheck(unsigned int n){

	int k = 0;
	
	for(int i = 1; i < n/2; i++){
	    
		if(k > 1)
		
			return false;
			
		if(n % i == 0)
		
			k++;
			
	}
	
	return true;
	
}


void producer (std::vector<unsigned int> & vec,int id){
	while(1){
		std::unique_lock<std::mutex> lck(mtxVct);
		unsigned int randomNumber = generateRandomNumber();
		cvc.wait(lck);
		for (unsigned long int i = 0; i < vec.size(); i++){
			if(vec[i] == 0){
				vec[i] = randomNumber;
				break;
			}				
		}
		std::cout<<id<<std::endl;
		cvc.notify_all();
	}
}

void consumer(std::vector<unsigned int> & vec){

}


int main(int argc, char** argv) {

	using namespace std::literals; //to use 1ms

	//catching first argument (size of integer numbers vector)

	const std::string argument1 = argv[1];

	unsigned long int N = stoi(argument1);

	//catching second argument (number of threads of producers)

	const std::string argument2 = argv[2];

	int numThreadsProducers = stoi(argument2);	

	//catching third argument (number of threads of consumers)

	const std::string argument3 = argv[3];

	int numThreadsConsumers = stoi(argument3);

	//catching fourth argument (number of numbers to be processed by the consumers)

	const std::string argument4 = argv[4];

	int M = stoi(argument4);

	std::vector<std::thread> threads;

	//creating the integer numbers vector with size N

	std::vector<unsigned int> randomNumberVector;

	std::cout << "creating vector" << std::endl;

	randomNumberVector.reserve(N);	

	for (unsigned long int i = 0; i < N; i++){
		//start all the position as free		
		randomNumberVector.push_back(0);
	}

	//getting time for the start

	auto startTime = std::chrono::steady_clock::now();

	//Producers Threads creation

	std::cout << "inserting producers threads" << std::endl;	
	for (int i = 0; i < numThreadsProducers; i++) {
		threads.push_back( std::thread(producer, std::ref(randomNumberVector),i));
	}


	//Consumers Threads creation
	std::cout << "inserting consumers threads" << std::endl;
	for (int i = 0; i < numThreadsConsumers; i++) {
		threads.push_back( std::thread(consumer, std::ref(randomNumberVector)));
	}

		
	//wait for the threads to complete. Main blocks

	for(auto& th : threads) th.join();

	//getting time for the end

	auto endTime = std::chrono::steady_clock::now();


	//note that 1ms is a literal defined in <chrono>

	std::cout << "Tempo de execução: " << std::chrono::duration_cast<decltype(1ms)>(endTime - startTime).count() << " ms" << std::endl;

	return 0;

}

