#include <fstream>
#include <iostream>
#include "day1.hpp"

int main() {
    std::ifstream file("data/day1.txt");

    Day1 obj;
    std::string line;
    while (std::getline(file, line)) {
        obj.solution(line);
    }
    std::cout << "Solution :" << obj.zero_cross << std::endl;
    return 0;
}
