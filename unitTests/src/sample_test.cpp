#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>


#include "Ratio.hpp"

///-----------------------------constructors----------------------------------------------///

TEST (RatioConstructor, defaultConstructor) { 
    Ratio<int> r1;
    Ratio<int> r2(0,1);

    ASSERT_EQ (r1, r2);
}

TEST (RatioConstructor, valueConstructor) { 
    const size_t maxNb = 10000;
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator = uniformIntDistribution(generator);
        const int denominator = uniformIntDistribution(generator);
        Ratio<int> r1(numerator, denominator);
        Ratio<int> r2;
        r2.numerator() = numerator;
        r2.denominator() = denominator;

	    ASSERT_EQ (r1, r2);
    }
}
      
TEST (RatioConstructor, copyConstructor) { 
    const size_t maxNb = 10000;
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator = uniformIntDistribution(generator);
        const int denominator = uniformIntDistribution(generator);

        Ratio<int> r1(numerator, denominator);
        Ratio<int> r2(r1);

	    ASSERT_EQ (r1.numerator(), r2.numerator());
	    ASSERT_EQ (r1.denominator(), r2.denominator());
    }
}

///-----------------------------Arithmetics operators----------------------------------------------///

TEST (RatioArithmetic, plusRatio) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);
        const int numerator2 = uniformIntDistribution(generator);
        const int denominator2 = uniformIntDistribution(generator);

        Ratio<int> r1(numerator1,denominator1), r2(numerator2,denominator2), r3(r1.numerator() * r2.denominator() + r1.denominator() * r2.numerator(), r1.denominator() * r2.denominator());
	    ASSERT_EQ (r1 + r2, r3);
        ASSERT_EQ (r2 + r1, r3);
    }
}

TEST (RatioArithmetic, plusRatioAndValues) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);

	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);

        double value = uniformDistributionValue(generator);

        Ratio<int> ratioValue(Ratio<int>::convertFloatToRatio(value, 10));


        Ratio<int> r1(numerator1,denominator1), r3(r1.numerator() * ratioValue.denominator() + r1.denominator() * ratioValue.numerator(), r1.denominator() * ratioValue.denominator());
	    ASSERT_EQ (r1 + ratioValue, r3);
        ASSERT_EQ (ratioValue + r1, r3);
    }
}

TEST (RatioArithmetic, minusRatio) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);
        const int numerator2 = uniformIntDistribution(generator);
        const int denominator2 = uniformIntDistribution(generator);

        Ratio<int> r1(numerator1,denominator1), r2(numerator2,denominator2);
        Ratio<int> r3(r1.numerator() * r2.denominator() - r1.denominator() * r2.numerator(), r1.denominator() * r2.denominator());
        Ratio<int> r4(r1.denominator() * r2.numerator() - r1.numerator() * r2.denominator(), r1.denominator() * r2.denominator());

	    ASSERT_EQ (r1 - r2, r3);
        ASSERT_EQ (r2 - r1, r4);
    }
}

TEST (RatioArithmetic, minusRatioAndValues) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);

	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);

        double value = uniformDistributionValue(generator);

        Ratio<int> ratioValue(Ratio<int>::convertFloatToRatio(value, 10));


        Ratio<int> r1(numerator1,denominator1);
        Ratio<int> r3(r1.numerator() * ratioValue.denominator() - r1.denominator() * ratioValue.numerator(), r1.denominator() * ratioValue.denominator());
        Ratio<int> r4(r1.denominator() * ratioValue.numerator() - r1.numerator() * ratioValue.denominator(), r1.denominator() * ratioValue.denominator());

	    ASSERT_EQ (r1 - ratioValue, r3);
        ASSERT_EQ (ratioValue - r1, r4);
    }
}

TEST (RatioArithmetic, productRatio) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);
        const int numerator2 = uniformIntDistribution(generator);
        const int denominator2 = uniformIntDistribution(generator);

        Ratio<int> r1(numerator1,denominator1), r2(numerator2,denominator2), r3(r1.numerator() * r2.numerator(), r1.denominator() * r2.denominator());
	    ASSERT_EQ (r1 * r2, r3);
        ASSERT_EQ (r2 * r1, r3);
    }
}

TEST (RatioArithmetic, productRatioAndValues) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);

	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);

        double value = uniformDistributionValue(generator);

        Ratio<int> ratioValue(Ratio<int>::convertFloatToRatio(value, 10));


        Ratio<int> r1(numerator1,denominator1);
        Ratio<int> r2(r1.numerator() * ratioValue.numerator(), r1.denominator() * ratioValue.denominator());

	    ASSERT_EQ (r1 * ratioValue, r2);
        ASSERT_EQ (ratioValue * r1, r2);
    }
}

TEST (RatioArithmetic, divisionRatio) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);
        const int numerator2 = uniformIntDistribution(generator);
        const int denominator2 = uniformIntDistribution(generator);

        Ratio<int> r1(numerator1,denominator1), r2(numerator2,denominator2);
        Ratio<int> r3(r1.numerator() * r2.denominator(), r1.denominator() * r2.numerator());
        Ratio<int> r4(r2.numerator() * r1.denominator(), r2.denominator() * r1.numerator());

	    ASSERT_EQ (r1 / r2, r3);
        ASSERT_EQ (r2 / r1, r4);
    }
}

TEST (RatioArithmetic, divisionRatioAndValues) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);

        double value = uniformDistributionValue(generator);

        Ratio<int> ratioValue(Ratio<int>::convertFloatToRatio(value, 10));


        Ratio<int> r1(numerator1,denominator1);
        Ratio<int> r2(r1.numerator() * ratioValue.denominator(), r1.denominator() * ratioValue.numerator());
        Ratio<int> r3(ratioValue.numerator() * r1.denominator(), ratioValue.denominator() * r1.numerator());

	    ASSERT_EQ (r1 / ratioValue, r2);
        ASSERT_EQ (ratioValue / r1, r3);
    }
}


TEST (RatioArithmetic, sinRatio) { 
    const size_t maxNb = 10000;  // max number for no
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxNb);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxNb),maxNb);

    for(int run = 0; run < 1000; ++run){
        const int numerator1 = uniformIntDistribution(generator);
        const int denominator1 = uniformIntDistribution(generator);
        const int numerator2 = uniformIntDistribution(generator);
        const int denominator2 = uniformIntDistribution(generator);

        Ratio<int> r1(numerator1,denominator1), r2(numerator2,denominator2);
        Ratio<int> r3(r1.numerator() * r2.denominator(), r1.denominator() * r2.numerator());
        Ratio<int> r4(r2.numerator() * r1.denominator(), r2.denominator() * r1.numerator());

	    ASSERT_EQ (r1 / r2, r3);
        ASSERT_EQ (r2 / r1, r4);
    }
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}