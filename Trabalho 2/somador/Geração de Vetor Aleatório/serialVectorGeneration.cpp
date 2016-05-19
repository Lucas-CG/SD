#include <iostream>
#include <cstdint>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>

#define NUM_ELEMENTS 500000000 //500MB

void printVector(std::vector<int8_t> & vec, unsigned long int numElements) {

	for (unsigned long int i = 0; i < numElements; i++) {

		std::cout << static_cast<int>(vec.at(i)) << std::endl;
		//static_cast because cout treats int8_t as char

	}

}

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

int main(int argc, char** argv) {

	using namespace std::literals;

	auto vectorStartTime = std::chrono::steady_clock::now();

	std::vector<int8_t> numbers = generateRandomVector(NUM_ELEMENTS);

	auto vectorEndTime = std::chrono::steady_clock::now(); //end of vector generation

	std::cout << "Tempo de geração do vetor: " << std::chrono::duration_cast<decltype(1ms)>(vectorEndTime - vectorStartTime).count() << " ms" << std::endl;

	//printVector(numbers, NUM_ELEMENTS);

}
