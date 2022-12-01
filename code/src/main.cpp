#include <iostream>

#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(-2,-4);

    Ratio<int> secondRatio(5,2);

    if(firstRatio != firstRatio ){
        std::cout << "Ratio != ratio " << std::endl;
    }
    if(firstRatio != 1 ){
        std::cout << "Ratio != 1 " << std::endl;
    }
    if(1 != firstRatio){
        std::cout << "1 != ratio " << std::endl;
    }
    // std::cout << "ratio < value " << firstRatio < 0.5 << std::endl;
    // std::cout << "value < ratio " << 2 < secondRatio << std::endl;


    return 0;
}