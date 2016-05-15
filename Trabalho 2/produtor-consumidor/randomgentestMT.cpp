#include <iostream>
#include <ctime>
#include <cstdint>
#include <cstdlib>
#include <thread>
#include <string>
#include <atomic>
#include <vector>
#include <functional>

using namespace std;

void generate100RandomNumbers(int threadNum, std::atomic_flag & bolt) {

	srand( ( threadNum * time(NULL) ) / 4  );

	for (int i = 0; i < 25; i++){

		int gen = (rand() % 201) - 100; //-100 to +100

		while(bolt.test_and_set()) {}

		cout << "Thread " << threadNum << ": " << gen << endl;

		bolt.clear();

	}


}


int main (int argc, char** argv){

	atomic_flag lock = ATOMIC_FLAG_INIT; //False

	vector<thread> threads;

	for (int i = 1; i < 5; i++) {

		threads.push_back( thread(generate100RandomNumbers, i, ref(lock) ) );

	}

	for(auto& th : threads) th.join();

	return 0;

}
