#include <iostream>
#include <thread>
#include <semaphore.h>
#include <condition_variable>
#include <ctime> 			//std::time_t, time (apenas para gerar os aleatórios)
#include <vector> 			//std::vector
#include <cstdlib> 			//stoi, stoul, rand, srand
#include <string>			//std::string
#include <chrono>			//std::chrono
#include <functional>		//std::ref

//semaphore for ME of the vector numbers
sem_t mutex;
//semaphore for ME for M number consumed
sem_t mutexMNumbers;
//semaphore for checking if the vector number is full
sem_t isFull;
//semaphore for checking if the vector number is empty
sem_t isEmpty;

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


void producer (std::vector<unsigned int> & vec, int M, int & m){
	while(1){				
		//critical session begin		
		sem_wait(&isEmpty);
		sem_wait(&mutex);	
		if(m >= M) break;		
		for (unsigned long int i = 0; i < vec.size(); i++){
			if(vec[i] == 0){					
				vec[i] = generateRandomNumber();
				std::cout << vec[i] << std::endl;
				break;
			}				
		}	
		//critical session ends
		sem_post(&mutex);
		sem_post(&isFull);
	}
}

void consumer(std::vector<unsigned int> & vec, int M, int & m){
	while(1){
		//critical session begin
		sem_wait(&isFull);
		sem_wait(&mutex);
		if(m >= M) break;	
		for (unsigned long int i = 0; i < vec.size(); i++){
			if(vec[i] != 0){
				std::cout << "O número "<<vec[i]<<" é primo: "<< primeCheck(vec[i])<< std::endl;
				vec[i] = 0;
				break;
			}				
		}
		m++;
		//critical session ends
		sem_post(&mutex);
		sem_post(&isEmpty);
	}
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

	sem_init(&mutex,0,1);
	sem_init(&mutexMNumbers,0,1);
	sem_init(&isFull,0,0);
	sem_init(&isEmpty,0,N);

	int m = 0;

	//getting time for the start
	auto startTime = std::chrono::steady_clock::now();

	//Producers Threads creation
	std::cout << "inserting producers threads" << std::endl;	
	for (int i = 0; i < numThreadsProducers; i++) {		
		threads.push_back( std::thread(producer, std::ref(randomNumberVector),M, std::ref(m)));
	}

	//Consumers Threads creation
	std::cout << "inserting consumers threads" << std::endl;
	for (int i = 0; i < numThreadsConsumers; i++) {
		threads.push_back( std::thread(consumer, std::ref(randomNumberVector), M, std::ref(m)));
	}

	//wait for the threads to complete. Main blocks
	for(auto& th : threads) th.join();

	sem_destroy(&mutex);
	sem_destroy(&mutexMNumbers);
	sem_destroy(&isFull);
	sem_destroy(&isEmpty);

	//getting time for the end
	auto endTime = std::chrono::steady_clock::now();


	//note that 1ms is a literal defined in <chrono>

	std::cout << "Tempo de execução: " << std::chrono::duration_cast<decltype(1ms)>(endTime - startTime).count() << " ms" << std::endl;

	return 0;

}

