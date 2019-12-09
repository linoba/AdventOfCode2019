#include <iostream>
#include <cstdlib>
#include <cmath>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int getRequiredFuel(int mass) {
	return (mass / 3) - 2;
}

int main( int argc, const char* argv[]) {
	int mass;
	int sum = 0;
	while (std::cin >> mass) {
		int current = getRequiredFuel(mass);
		sum += current;
		while (current > 0) {
			current = getRequiredFuel(current);
			if (current > 0) {
				sum += current;
			}
		}
	}
	std::cout << sum << std::endl;
	return 0;
}
