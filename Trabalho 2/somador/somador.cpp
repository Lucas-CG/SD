// Arguments: number of threads, vector size

#include <iostream> 		//std::cout, std::endl
#include <thread> 			//std::thread
#include <ctime> 			//std::time_t, time (apenas para gerar os aleatórios)
#include <vector> 			//std::vector
#include <cstdlib> 			//stoi, stoul, rand, srand
#include <atomic> 			//std::atomic_flag, ATOMIC_FLAG_INIT, std::atomic_flag.test_and_set()
#include <string>			//std::string
#include <chrono>			//std::chrono
#include <functional>		//std::ref
#include <cstdint>			//int8_t


//From c++11: std::thread, std::vector, std::array, std::atomic_flag,
//std::chrono, auto, decltype, std::ref, int8_t

//From c++14: chrono_literals


//spinlock functions

void acquire(std::atomic_flag & flag) { while(flag.test_and_set()) {} } //busy wait

void release(std::atomic_flag & flag) {flag.clear();}


std::vector<int8_t> generateRandomVector(unsigned long int vectorSize) {

	srand(time(NULL));

	std::vector<int8_t> ret;
	

	//allocating necessary space (avoids reallocating after insertion of elements)

	ret.reserve(vectorSize);

	for (unsigned long int i = 0; i < vectorSize; i++){

		ret.push_back( (rand() % 201) - 100 ); //-100 to +100

	}

	return ret;

}

//a part of the parallel sum

void parallelSum(std::vector<int8_t> & vec, unsigned long int first, unsigned long int last, long int & counter, std::atomic_flag &flag) {

	long int sum = 0;

	for(unsigned long int i = first; i < last; i++) sum += vec.at(i);


	//critical section begin

	acquire(flag);

	counter += sum;

	release(flag);

	//critical section end

}



int main(int argc, char** argv) {


	using namespace std::literals; //to use 1ms


	//Creating a lock

	std::atomic_flag lock = ATOMIC_FLAG_INIT; //False

	long int result = 0;

	
	//catching second argument (array size)


	const std::string argument2 = argv[2];

	unsigned long int numbersAmount = stoul(argument2);

	
	//Starting time measurement for vector generation

	auto vectorStartTime = std::chrono::steady_clock::now();

	std::vector<int8_t> numbers = generateRandomVector(numbersAmount);

	auto vectorEndTime = std::chrono::steady_clock::now(); //end of vector generation

	std::cout << "Tempo de geração do vetor: " << std::chrono::duration_cast<decltype(1ms)>(vectorEndTime - vectorStartTime).count() << " ms" << std::endl;
	

	//Catching thread number (first argument)

	const std::string argument1 = argv[1];

	int numThreads = stoi(argument1);


	//deciding the amount of elements for each thread

	unsigned long int partSize = (numbersAmount + numThreads - 1) / numThreads;

	std::vector<std::thread> threads;


	//getting time for the start

	auto startTime = std::chrono::steady_clock::now();


	//Thread creation

	for (int i = 0; i < numThreads; i++) {

		unsigned long int partStart = partSize * i;
		unsigned long int partEnd = ( partSize * (i + 1) < numbersAmount ) ? (partSize * (i + 1)) : numbersAmount;

		threads.push_back( std::thread(parallelSum, std::ref(numbers), partStart, partEnd, std::ref(result), std::ref(lock) ) );

	}

	
	//wait for the threads to complete. Main blocks

	for(auto& th : threads) th.join();


	//getting time for the end

	auto endTime = std::chrono::steady_clock::now();


	//note that 1ms is a literal defined in <chrono>

	std::cout << "Resultado: " << result << std::endl;

	std::cout << "Tempo de execução: " << std::chrono::duration_cast<decltype(1ms)>(endTime - startTime).count() << " ms" << std::endl;


	return 0;

}
