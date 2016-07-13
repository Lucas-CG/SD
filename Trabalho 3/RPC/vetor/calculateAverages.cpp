#include <iostream> //std::cout
#include <fstream> //std::ifstream
#include <string>
#include <stdlib.h>

int main(int argc, char** argv) {
	
	double amount = 0.0;
	double total = 0.0;
	double num, average;
	std::string s;

	const char* fileName = argv[1];

	std::ifstream numbersFile(fileName);
	while(numbersFile >> s) {
		num = atof(s.c_str());		
		total = total + num;

		amount = amount + 1.0;

	}

	average = total/amount;

	std::cout << average << std::endl;

	return 0;

}