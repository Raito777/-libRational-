#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(5,2);

    Ratio<int> secondRatio(7417,12395);

    // if(firstRatio != firstRatio ){
    //     std::cout << "Ratio != ratio " << std::endl;
    // }
    // if(firstRatio != 1 ){
    //     std::cout << "Ratio != 1 " << std::endl;
    // }
    // if(1 != firstRatio){
    //     std::cout << "1 != ratio " << std::endl;
    // }

    // Ratio<int> fifthRatio(6,12);

    // Ratio<int> sixthRatio(1,2);

    // Ratio<int> seventhRatio(5,2);

    std::cout << Ratio<int>::sin(firstRatio) << std::endl;
    std::cout << Ratio<int>::cos(firstRatio) << std::endl;
    std::cout << Ratio<int>::tan(firstRatio) << std::endl;
    std::cout << Ratio<int>::exp(firstRatio) << std::endl;
    std::cout << Ratio<int>::ln(firstRatio) << std::endl;
    std::cout << Ratio<int>::log10(firstRatio) << std::endl;

    return 0;
}