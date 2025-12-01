#include "day1.hpp"
#include <iostream>

Day1::Day1(){
    counter = 50;
    zero_cross = 0;
}

void Day1::solution(const std::string& line) {
    int value = std::stoi(line.substr(1));
    int sign = 1;
    if( line.front() == 'L') {
        sign = -1;
    }
    for ( int i = 0; i < value; i++){
        counter = (counter + 100 + sign) % 100;
        
        if (counter == 0) {
            zero_cross += 1;
        }
    }
}
