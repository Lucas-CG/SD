#include <iostream> //std::cout
#include <fstream> //std::ifstream

int main(int argc, char** argv) {


	double amount = 0.0;
	double total = 0.0;
	double num, average;

	//catching only argument (name of file)

	const char* fileName = argv[1];

	std::ifstream numbersFile(fileName);

	while(numbersFile >> num) {

		total = total + num;

		amount = amount + 1.0;

	}

	average = total/amount;

	std::cout << average << std::endl;

	return 0;

}