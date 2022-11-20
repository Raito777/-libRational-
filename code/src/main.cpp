#include <iostream>

#include <iostream>

#include "Ratio.hpp"

#include "RatioException.hpp"


int main() {
    
    Ratio<int> firstRatio(-2,-4);

    Ratio<int> secondRatio(-5,2);

    Ratio<int> thirdRatio(8,3);

    Ratio<int> fourthRatio(15,-3);

    Ratio<int> fifthRatio(6,12);

    std::cout << "firstRatio : " << firstRatio << std::endl;
    std::cout << "secondRatio : " << secondRatio << std::endl;
    std::cout << "thirdRatio : " << thirdRatio << std::endl;
    std::cout << "fourthRatio : " << fourthRatio << std::endl;

    // std::cout << "first ratio * secondRatio : " << firstRatio * secondRatio << std::endl;
    // std::cout << "first ratio / secondRatio : " << firstRatio / secondRatio << std::endl;
    // //std::cout << "sqrt(secondRatio) : " << Ratio<int>::sqrt(secondRatio) << std::endl;
    // std::cout << "cos(thirdRatio) : " << Ratio<int>::cos(thirdRatio) << std::endl;
    // std::cout << "sin(thirdRatio) : " << Ratio<int>::sin(thirdRatio) << std::endl;
    // std::cout << "exp(thirdRatio) : " << Ratio<int>::exp(thirdRatio) << std::endl;
    // std::cout << Ratio<int>::tan(thirdRatio) << std::endl;
    // std::cout << Ratio<int>::abs(secondRatio) << std::endl;
    // std::cout << Ratio<int>::abs(firstRatio) << std::endl;
    // std::cout << Ratio<int>::pow(firstRatio,2) <<std::endl;

    std::cout <<"Convertion : " << Ratio<int>::convertFloatToRatio(4.42,4) << std::endl;
    
    if(firstRatio < secondRatio)
    {
        std::cout << "1" << std::endl;
    }
    if(firstRatio <= secondRatio)
    {
        std::cout << "2" << std::endl;
    }
    if(firstRatio > secondRatio)
    {
        std::cout << "3" << std::endl;
    }
    if(firstRatio >= secondRatio)
    {
        std::cout << "4" << std::endl;
    }
    if(firstRatio == fifthRatio)
    {
        std::cout << "5" << std::endl;
    }
    if(firstRatio != fifthRatio)
    {
        std::cout << "6" << std::endl;
    }

    if(fourthRatio == -5)
    {
        std::cout << "true" << std::endl;
    }
    
    return 0;
}