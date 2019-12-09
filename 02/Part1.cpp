#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int getRequiredFuel(int mass) {
	return (mass / 3) - 2;
}

int main( int argc, const char* argv[]) {
	std::string row;
	while (std::cin >> row) {
		std::vector<int> data;
		std::stringstream ss(row);
		for (int i; ss >> i;) {
        	data.push_back(i);    
        	if (ss.peek() == ',') {
            	ss.ignore();
        	}
    	}
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
		std::cout << std::endl;
	}
	return 0;
}

// 25min