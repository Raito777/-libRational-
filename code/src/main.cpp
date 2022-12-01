#include <iostream>

#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(-2,-4);

    Ratio<int> secondRatio(5,2);

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

    std::cout << Ratio<int>::convertFloatToRatio(1.33333,10) << std::endl;
    
    return 0;
}