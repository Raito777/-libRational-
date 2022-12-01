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


    Ratio<int> fifthRatio(6,12);

    Ratio<int> sixthRatio(1,2);

    Ratio<int> seventhRatio(5,2);

    // std::cout << "firstRatio : " << firstRatio << std::endl;
    // std::cout << "secondRatio : " << secondRatio << std::endl;
    // std::cout << "thirdRatio : " << thirdRatio << std::endl;
    // std::cout << "fourthRatio : " << fourthRatio << std::endl;
    //std::cout <<" /0 : " << sixthRatio*seventhRatio << std::endl;
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

    std::cout <<"négatif !!!: " << Ratio<int>::convertFloatToRatio(-0.125,4) << std::endl;
    std::cout <<"positif: " << Ratio<int>::convertFloatToRatio(0.125,4) << std::endl;
//     std::cout <<" ratio + float : " << thirdRatio + 2.5 << std::endl;
//     float b = 2.5;
//     std::cout << " si tu es un float tape dans tes mains :" << thirdRatio + b <<std::endl;
//     std::cout <<" ratio + float  toi tes juste: " << thirdRatio + seventhRatio << std::endl;

//     std::cout << "convertion ratio to float : " << Ratio<int>::convertRatioToFloat(thirdRatio);
//    // std::cout << Ratio<int>::convertFloatToRatio(0.125658,10)<<std::endl;
//     std::cout << " ratio * float" << thirdRatio * 2.5 << std::endl;
//     std::cout << "bonne reponse = " << thirdRatio * secondRatio << std::endl;
//     std::cout << "partie entiere ratio =" << Ratio<int>::intPart(thirdRatio) << std::endl;
//     std::cout << "partie entiere float = " <<Ratio<float>::intPart(46.50)<<std::endl;

//     std::cout << "moins unaire " << -thirdRatio << std::endl;

//     std::cout << "ratio * float " << secondRatio * 0.7 << std::endl;
//     std::cout << "float * ratio " << 0.2 * secondRatio << std::endl;
//     //std::cout <<" float + ratio : " << 2.5 + firstRatio << std::endl;
   
    
    
    // if(firstRatio < sqrt(2))
    // {
    //     std::cout << "1" << std::endl;
    // }
    // if(firstRatio <= secondRatio)
    // {
    //     std::cout << "2" << std::endl;
    // }
    // if(firstRatio > secondRatio)
    // {
    //     std::cout << "3" << std::endl;
    // }
    // if(firstRatio >= secondRatio)
    // {
    //     std::cout << "4" << std::endl;
    // }
    // if(firstRatio == fifthRatio)
    // {
    //     std::cout << "5" << std::endl;
    // }
    // if(firstRatio != fifthRatio)
    // {
    //     std::cout << "6" << std::endl;
    // }

    // if(fourthRatio == -5)
    // {
    //     std::cout << "true" << std::endl;
    // }
    
    return 0;
}