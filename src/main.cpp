#include <iostream>

#include "../include/Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(2,4);

    Ratio<int> secondRatio(5,2);

    std::cout << firstRatio + secondRatio << std::endl;

    return 0;
}