#include "day2.hpp"
#include <iostream>
#include<algorithm>
#include <sstream>
#include <string>
#include <cmath>

Day2::Day2(): sum(0) {
}

std::vector<std::string> Day2::split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }

    return tokens;
}

int get_number_digits(long x) {
    return std::to_string(std::labs(x)).size();
}

void Day2::solution1(const std::string& line) {
   std::vector<std::string> tokens = split(line, ',');
   for (int i = 0; i <= tokens.size(); i++){
       std::vector<std::string> ordered_elems = split(tokens[i], '-');
       long start = std::stol(ordered_elems[0]);
       long end = std::stol(ordered_elems[1]);
       for( long j = start; j <= end; j++){
            int num_digits = get_number_digits(j);
            if (num_digits % 2 == 1){
                continue;
            }
            int n = num_digits/2;
            int div = std::pow(10, n) + 1;

            if (j % div == 0){
                sum += j;
                std::cout << sum << std::endl;
            } 
       }
   }
   std::cout << "count" << std::endl;
    
}

long get_divisor(int num_digits, int n){
    std::string s;
    for(int i =0; i < num_digits; i++){
        if( i % n == 0){
            s +='1';
        }
        else{
            s += '0';
        }
    }
    std::reverse(s.begin(), s.end());
    return std::stol(s);
}

void Day2::solution2(const std::string& line) {
    std::vector<std::string> tokens = split(line, ',');
   for (int i = 0; i <= tokens.size(); i++){
       std::vector<std::string> ordered_elems = split(tokens[i], '-');
       long start = std::stol(ordered_elems[0]);
       long end = std::stol(ordered_elems[1]);
       for( long j = start; j <= end; j++){
            int num_digits = get_number_digits(j);
            bool invalid = false;
            for(int n = 1; n < num_digits; n++){
                if (num_digits % n == 0){
                    long div = get_divisor(num_digits, n);
                    if (j % div == 0){
                        std::cout << "div: " << div << " " << n << std::endl;
                        invalid = true;
                    }
                }
            }
            if (invalid){
                sum += j;
                std::cout << sum << "\t" << j <<std::endl;
            } 
       }
   }
}
