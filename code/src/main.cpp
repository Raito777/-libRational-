#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(1,2);

    Ratio<long int> secondRatio(7417,12395);

    Ratio<float> thirdRatio(0.6666666666666666);

    Ratio<double> fourthRatio(-2.5,5.5);

    if(firstRatio < firstRatio){
        std::cout << "Ratio < ratio " << std::endl;
    }
    if(firstRatio < 0.25){
        std::cout << "Ratio < 0.25 " << std::endl;
    }
    if(0.25 < firstRatio){
        std::cout << "0.25 < ratio " << std::endl;
    }

    // Ratio<int> fifthRatio(6,12);

    // Ratio<int> sixthRatio(1,2);

    // Ratio<int> seventhRatio(5,2);

    // std::cout << Ratio<int>::sin(firstRatio) << std::endl;
    // std::cout << Ratio<int>::cos(firstRatio) << std::endl;
    // std::cout << Ratio<int>::tan(firstRatio) << std::endl;
    // std::cout << Ratio<int>::exp(firstRatio) << std::endl;
    // std::cout << Ratio<int>::ln(firstRatio) << std::endl;
    // std::cout << Ratio<int>::log10(firstRatio) << std::endl;
    
    // std::cout << firstRatio / fourthRatio << std::endl;
    // std::cout << fourthRatio / 2 << std::endl;
    // std::cout << 2 / fourthRatio << std::endl;
    return 0;
}