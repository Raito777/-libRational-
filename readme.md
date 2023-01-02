# libRational

## What for ?

> **Rational number** is a number that can be expressed as the quotient or fraction p/q of two integers, a numerator p and a non-zero denominator q. It can be usefull for certain operations. This library allow you to **create and use rational numbers** in c++.

## How to install
#### Dependecies

> Nothing exept Doxygen for this project (if you want the documentation).

#### Install with cmake (Linux / Mac)

+ Just include Ratio.hpp file in yours include files
    + [path to build]/ratio/include/Ratio.hpp

+ For this example project : if Doxygen installed: make html

+ The documentation will be located in :
    + [path to build]/INTERFACE/doc/doc-doxygen/html/index.html

## How to use ?

#### How to create a rational number object 
    
    //values of numerator and denominator (with ints)

    Ratio<int> firstRatio(1,2);
    //firstRatio = 1/2

    //a value that will be converted in a rational number

    Ratio<int> secondRatio(0.66666666666);
    //secondRatio = 2/3

    //work also with other type of integers

    Ratio<long int> secondRatio(0.66666666666);
    //secondRatio = 2/3

    //nothing

    Ratio<float> fourthRatio();
    //fourthRatio = 0/1;
    
#### How to use a rational number object
    
    Ratio<int> firstRatio(1,2);
    Ratio<long int> secondRatio(0.66666666666);

    //you can print rational numbers object
    std::cout << "firstRatio : " << firstRatio << std::endl;

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
