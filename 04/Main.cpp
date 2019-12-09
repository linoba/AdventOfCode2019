#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

bool isPassword(int number) {
    if (number < 100000 || number > 999999) { return false; }
    int recurring = 0;
    bool recurring_twice = false;
    while (number) {
        int last = number % 10;
        number /= 10;
        int current = number % 10;
        if (current > last) { return false; }
        if (current == last) {
            recurring++;
        } else {
            if (recurring == 1) { recurring_twice = true; }
            recurring = 0;
        }
    }
    return recurring_twice;
}

int main( int argc, const char* argv[]) {
    std::string row;
    while (std::cin >> row) {
        std::stringstream ss(row);
        int start, end;
        ss >> start;    
        if (ss.peek() == '-') {
            ss.ignore();
        }
        ss >> end;
        int counter = 0;
        for (int i=start; i<=end; i++) {
            if (isPassword(i)) { counter ++; }
        }
        std::cout << counter << std::endl;
    }
    return 0;
}
