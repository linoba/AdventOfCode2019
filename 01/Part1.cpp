#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
	int mass;
	int sum = 0;
	while (std::cin >> mass) {
		int current = (mass / 3) - 2;
		// std::cout << mass << " " << current << std::endl;
		sum += current;
	}
	std::cout << sum << std::endl;
	return 0;
}
