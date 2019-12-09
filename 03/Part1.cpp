#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

int main( int argc, const char* argv[]) {
    std::string string_row1, string_row2, element;
    while (std::cin >> string_row1) {
        // prepare
        std::vector<std::vector<bool>> grid;
        int max_width = 40000;
        int start_x = max_width / 2;
        int result = max_width * max_width;

        for (int i=0; i<max_width; i++) {
            std::vector<bool> row(max_width, false);
            grid.push_back(row);
        }
        int x = start_x;
        int y = start_x;
        int max_x = start_x;
        int max_y = start_x;
        std::stringstream ss(string_row1);
        while (std::getline(ss, element, ',')) {
            char c = element[0];
            int steps = std::stoi(element.substr(1));
            while (steps > 0) {
                grid[x][y] = 1;
                if (c == 'R') {
                    x++;
                } else if (c == 'L') {
                    x--;
                } else if (c == 'U') {
                    y--;
                } else {
                    y++;
                }
                steps--;
            }
            
            max_x = std::max(max_x, std::abs(x));
            max_y = std::max(max_y, std::abs(y));
        }

        std::cout << max_x << std::endl;
        std::cout << max_y << std::endl;
        std::cout << std::endl;

        /*for (std::vector<bool> a : grid) {
            for (bool b: a) {
                std::cout << b;
            }
            std::cout << std::endl;
        }*/

        // compare
        x = start_x;
        y = start_x;
        std::cin >> string_row2;
        ss = std::stringstream(string_row2);
        while (std::getline(ss, element, ',')) {
            char c = element[0];
            int steps = std::stoi(element.substr(1));
            while (steps > 0) {
                if (c == 'R') {
                    x++;
                } else if (c == 'L') {
                    x--;
                } else if (c == 'U') {
                    y--;
                } else {
                    y++;
                }
                steps--;
                if (grid[x][y]) {
                    int cur_distance = std::abs(x-start_x) + std::abs(y-start_x);
                    result = std::min(result, cur_distance);
                    std::cout << result << ", " << cur_distance << std::endl;
                }
            }
        }
        std::cout << result << std::endl << std::endl;
    }
    return 0;
}

// 50min