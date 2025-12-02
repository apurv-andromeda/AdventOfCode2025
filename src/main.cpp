#include <fstream>
#include <iostream>
#include "day2.hpp"

int main() {
    std::ifstream file("data/day2.txt");

    Day2 obj;
    std::string line;
    while (std::getline(file, line)) {
        obj.solution2(line);
    }
    
    return 0;
}
