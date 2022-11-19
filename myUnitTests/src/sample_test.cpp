#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>


#include "Ratio.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, valueConstructor) { 
	Ratio<int> r(1,2);

	ASSERT_EQ (r.numerator(), 1);
    ASSERT_EQ (r.denominator(), 2);

}

TEST (RatioArithmetic, plus) { 


    const size_t maxNb = 1000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run=0; run<100; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);
        const int numerator2 = uniformIntDistribution(generator);
        const int denominator2 = uniformIntDistribution(generator);

	    Ratio<int> r1(numerator1,denominator1), r2(numerator2,denominator2), r3(r1 + r2);

	    ASSERT_EQ (r1.numerator() * r2.denominator() + r1.denominator() * r2.numerator(), r3.numerator());
        ASSERT_EQ (r1.denominator() * r2.denominator(), r3.denominator());
    }

}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}