#include <iostream>

#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(-2,-4);

    Ratio<int> secondRatio(5,2);

    std::cout << "Ratio / ratio " << firstRatio / firstRatio << std::endl;
    std::cout << "ratio / value " << firstRatio / 0.5 << std::endl;
    std::cout << "value / ratio " << 2 / secondRatio << std::endl;

    
    return 0;
}