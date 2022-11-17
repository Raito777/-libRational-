#include <iostream>

#include "../include/plop.hpp"
#include "../include/Ratio.hpp"


int main() {

    // appel de ploup
    ploup();
    
    Ratio<int> firstRatio();

    Ratio<long> secondRatio(5,2);

    std::cout << "Second ratio :" << secondRatio.nominator() << "/" << secondRatio.denominator() << std::endl;

    return 0;
}