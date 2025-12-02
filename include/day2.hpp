#pragma once
#include <string>
#include <vector>

class Day2 {
public:
    Day2();
    void solution1(const std::string& line);
    void solution2(const std::string& line);
private:
    long sum;
    std::vector<std::string> split(const std::string& s, char delimiter);
}; 
