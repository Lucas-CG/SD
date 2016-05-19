#include <iostream> 		//std::cout, std::endl
#include <thread> 			//std::thread
#include <ctime> 			//std::time_t, time (apenas para gerar os aleatórios)
#include <vector> 			//std::vector
#include <cstdlib> 			//stoi, stoul, rand, srand
#include <string>			//std::string
#include <chrono>			//std::chrono
#include <functional>		//std::ref
#include <cstdint>			//int8_t

#define NUM_ELEMENTS 500000000 //500MB





void printVector(std::vector<int8_t> & vec, unsigned long int numElements) {

	for (unsigned long int i = 0; i < numElements; i++) {

		std::cout << static_cast<int>(vec.at(i)) << std::endl;
		//static_cast because cout treats int8_t as char

	}

}

void insertIntoVector(std::vector<int8_t> & vec, int threadNumber, unsigned int threadsAmount){

	srand(time(NULL));

	for (unsigned long int i = threadNumber; i < vec.size(); i+= threadsAmount) {

		vec.at(i) = (rand() % 201) - 100; //-100 to +100

	}
}

std::vector<int8_t> generateRandomVector(unsigned long int vectorSize){

	unsigned int availableThreads = std::thread::hardware_concurrency();

	std::vector<int8_t> ret(vectorSize, 0);

	std::vector<std::thread> vectorThreads;

	for (unsigned int i = 0; i < availableThreads; i++){
		vectorThreads.push_back(std::thread(insertIntoVector, std::ref(ret), i, availableThreads));
	}

	for (auto& vth : vectorThreads) vth.join();

	return ret;

}





int main(int argc, char** argv) {


	using namespace std::literals;

	//std::atomic_flag flag = ATOMIC_FLAG_INIT; //False

	auto vectorStartTime = std::chrono::steady_clock::now();

	std::vector<int8_t> numbers = generateRandomVector(NUM_ELEMENTS);

	auto vectorEndTime = std::chrono::steady_clock::now(); //end of vector generation

	std::cout << "Tempo de geração do vetor: " << std::chrono::duration_cast<decltype(1ms)>(vectorEndTime - vectorStartTime).count() << " ms" << std::endl;

	//printVector(numbers, NUM_ELEMENTS);

	std::cout << numbers.size() << std::endl;


}
