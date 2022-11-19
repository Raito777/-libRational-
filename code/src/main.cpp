#include <iostream>

#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<float> firstRatio(-2,-4);

    Ratio<float> secondRatio(-5,2);

    Ratio<float> thirdRatio(8,3);

    std::cout << firstRatio + secondRatio << std::endl;
    std::cout << firstRatio * secondRatio << std::endl;
    std::cout << firstRatio / secondRatio << std::endl;
    std::cout << Ratio<float>::sqrt(secondRatio) << std::endl;
    std::cout << Ratio<float>::cos(thirdRatio) << std::endl;
    std::cout << Ratio<float>::sin(thirdRatio) << std::endl;
    std::cout << Ratio<float>::exp(thirdRatio) << std::endl;
    std::cout << Ratio<float>::tan(thirdRatio) << std::endl;
    std::cout << Ratio<float>::abs(secondRatio) << std::endl;
    std::cout << Ratio<float>::abs(firstRatio) << std::endl;
    std::cout << Ratio<float>::pow(firstRatio,2) <<std::endl;
    

    return 0;
}