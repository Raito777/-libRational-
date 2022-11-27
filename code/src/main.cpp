#include <iostream>

#include <iostream>

#include "Ratio.hpp"


int main() {
    
    Ratio<int> firstRatio(-2,-4);

    Ratio<int> secondRatio(5,2);

    Ratio<int> thirdRatio(62,9);

    Ratio<int> fourthRatio(15,-3);

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

    std::cout <<"Convertion float to ratio: " << Ratio<int>::convertFloatToRatio(2.5,4) << std::endl;
    std::cout <<" ratio + float : " << thirdRatio + 2.5 << std::endl;
    float b = 2.5;
    std::cout << " si tu es un float tape dans tes mains :" << thirdRatio + b <<std::endl;
    std::cout <<" ratio + float  toi tes juste: " << thirdRatio + seventhRatio << std::endl;

    std::cout << "convertion ratio to float : " << Ratio<int>::convertRatioToFloat(thirdRatio);
   // std::cout << Ratio<int>::convertFloatToRatio(0.125658,10)<<std::endl;
    std::cout << " ratio * float" << thirdRatio * 2.5 << std::endl;
    std::cout << "bonne reponse = " << thirdRatio * secondRatio << std::endl;
    std::cout << "partie entiere ratio =" << Ratio<int>::partEntiere(thirdRatio) << std::endl;
    std::cout << "partie entiere float = " <<Ratio<float>::partEntiere(46.50)<<std::endl;


    //std::cout <<" float + ratio : " << 2.5 + firstRatio << std::endl;
   
    
    
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