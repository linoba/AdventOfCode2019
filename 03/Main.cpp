#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
// g++ Main.cpp -lm -lcrypt -O2 -std=c++11

const int UNASSIGNED_GRID = -1;

int main( int argc, const char* argv[]) {
    std::string string_row1, string_row2, element;
    while (std::cin >> string_row1) {
        // prepare
        std::vector<std::vector<int>> grid;
        int max_width = 40000;
        int start_x = max_width / 2;
        int result = max_width * max_width;

        for (int i=0; i<max_width; i++) {
            std::vector<int> row(max_width, UNASSIGNED_GRID);
            grid.push_back(row);
        }
        int x = start_x;
        int y = start_x;
        int counter_steps = 0;
        std::stringstream ss(string_row1);
        while (std::getline(ss, element, ',')) {
            char c = element[0];
            int steps = std::stoi(element.substr(1));
            while (steps > 0) {
                if (grid[x][y] == UNASSIGNED_GRID) {
                    grid[x][y] = counter_steps;
                }
                counter_steps++;
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
        }

        // compare
        x = start_x;
        y = start_x;
        std::cin >> string_row2;
        ss = std::stringstream(string_row2);
        counter_steps = 0;
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
                counter_steps++;
                if (grid[x][y] >= 0) {
                    int cur_distance = grid[x][y] + counter_steps;
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
// +5min