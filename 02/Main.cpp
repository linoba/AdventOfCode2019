#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int executeWithVerbAndNoun(int noun, int verb, std::string row) {
	std::vector<int> data;
	std::stringstream ss(row);
	for (int i; ss >> i;) {
    	data.push_back(i);    
    	if (ss.peek() == ',') {
        	ss.ignore();
    	}
	}
	data[1] = noun;
	data[2] = verb;
	int index = 0;
	while (data[index] != 99) {
		int a = data[data[index+1]];
		int b = data[data[index+2]];
		int op_result = 0;
		if (data[index] == 1) {
			op_result = a + b;
		} else {
			op_result = a * b;
		}
		int write_index = data[index+3];
		data[write_index] = op_result;
		index += 4;
	}
	return data[0];
}


int main( int argc, const char* argv[]) {
	std::string row;
	while (std::cin >> row) {
		for (int noun=0; noun<100; noun++) {
			for (int verb=0; verb<100; verb++) {
				int result = executeWithVerbAndNoun(noun, verb, row);
				std::cout << std::setw(4) << noun;
				std::cout << std::setw(4) << verb;
				std::cout << std::setw(10) << result << std::endl;
				if (result == 19690720) {
					return 0;
				}
			}
		}
		
	}
	return 0;
}
