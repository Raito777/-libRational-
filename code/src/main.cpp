#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(1,2);
    Ratio<long int> secondRatio(0.6666666);

    //you can print rational numbers object
    std::cout << "secondRatio : " << secondRatio << std::endl;

    //do artithmetic operations

    std::cout << "-firstRatio : " << -firstRatio << std::endl;

    std::cout << "firstRatio + secondRatio : " << firstRatio + secondRatio << std::endl;
    std::cout << "firstRatio + 2 : "  << firstRatio + 2 << std::endl;
    std::cout << "2 + firstRatio : " << 2 + firstRatio << std::endl;

    std::cout << "firstRatio * secondRatio : " << firstRatio * secondRatio << std::endl;
    std::cout << "firstRatio * 2 : " << firstRatio * 2 << std::endl;
    std::cout << "2 firstRatio : " << 2 * firstRatio << std::endl;

    std::cout << "firstRatio / secondRatio : " << firstRatio / secondRatio << std::endl;
    std::cout << "firstRatio / 2 : " << firstRatio / 2 << std::endl;
    std::cout << "2 / firstRatio : " << 2 / firstRatio << std::endl;

    std::cout << "firstRatio - secondRatio : " << firstRatio - secondRatio << std::endl;
    std::cout << "firstRatio - 2 : "  << firstRatio - 2 << std::endl;
    std::cout << "2 - firstRatio : " << 2 - firstRatio << std::endl;

    //and other operations

    std::cout << "cos(firstRatio) : " << Ratio<int>::cos(firstRatio) << std::endl;
    std::cout << "sin(firstRatio) : " << Ratio<int>::sin(firstRatio) << std::endl;
    std::cout << "tan(firstRatio) : " << Ratio<int>::tan(firstRatio) << std::endl;
    std::cout << "exp(firstRatio) : " << Ratio<int>::exp(firstRatio) << std::endl;
    std::cout << "ln(firstRatio) : " << Ratio<int>::ln(firstRatio) << std::endl;
    std::cout << "log10(firstRatio) : " << Ratio<int>::log10(firstRatio) << std::endl;


    
    return 0;
}