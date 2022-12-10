#ifndef RATIONNAL_H
#define RATIONNAL_H

#pragma once

#include <iostream>
#include <algorithm>
#include <limits>
#include <fstream>
#include <cmath>


// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.png width=400px
/// \tableofcontents
/// \section instroduction_sec What for?
/// Rational number is a number that can be expressed as the quotient or fraction p/q of two integers, a numerator p and a non-zero denominator q. It can be usefull for 
/// certain operations.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li Just add the Ratio.hpp file in yours include files
/// \li For this example project : if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html

/// \class Ratio
/// \brief class defining a ratio number.
template <typename T>
class Ratio{

	private : 
		T m_num;
		T m_den;

	public :
		// default constructor
		Ratio() : m_num(0), m_den(1) {};

		/// \brief constructor from a numerator and denominator
		/// \param numerator : the numerator of the rational number
		/// \param denominator : the denominator of the rational number
		Ratio(const T& numerator, const T &denominator) : m_num(numerator), m_den(denominator) {this->reduce();};


		/// \brief constructor from a value number, convert it into a rational number
		/// \param ratio the other rational number
		Ratio(const T& value);

		/// \brief constructor from another rational number
		/// \param ratio the other rational number
		Ratio(const Ratio &ratio) = default;

		/// \brief destructor
		~Ratio() = default;

		// /// \brief getter of the numerator
		inline T getNumerator() const {return m_num;};
		/// \brief getter of the denominator
		inline T getDenominator() const {return m_den;};
		/// \brief setter of the numerator
		void setNumerator(const T numerator) {this->m_num = numerator;};
		/// \brief setter of the denominator
		void setDenominator(const T denominator) {this->m_den = denominator;};

		/// \brief operator addition for rational numbers
		/// \param r the rational number to be added
		///\brief operator addition for rational numbers plus float/int
		/// \param r the float number to be added
		Ratio operator+(const Ratio &r) const;
		template<typename U>
		inline friend Ratio operator+(const Ratio &r, const U &value) {return r+convertFloatToRatio(value,4);}
		template<typename U>
		inline friend Ratio operator+(const U &value, const Ratio &r) {return r+convertFloatToRatio(value,4);}


		/// \brief operator soustraction for rational numbers
		/// \param r the rational number to substract
		Ratio operator-(const Ratio &r) const;
		///\brief operator soustraction for rational numbers minus float/int
		/// \param r the float number to be added
		template<typename U>
		inline friend Ratio operator-(const Ratio &r, const U &value) {return r-convertFloatToRatio(value,4);}
		template<typename U>
		inline friend Ratio operator-(const U &value, const Ratio &r) {return convertFloatToRatio(value,4)-r;}

	
		/// \brief operator unary minus operator
		Ratio operator-() const;

		/// \brief operator multiply for rational numbers
		/// \param r the rational number to multiply
		Ratio operator*(const Ratio &r) const;
		/// \brief operator multiply for rational numbers, multiply rational with value
		/// \param value the float number to multiply 
		template<typename U>
		inline friend Ratio operator*(const U &value, const Ratio &r) {return r*convertFloatToRatio(value,4);}
		template<typename U>
		inline friend Ratio operator*(const Ratio &r, const U &value) {return r*convertFloatToRatio(value,4);}

		/// \brief operator divide for rational numbers
		/// \param r the rational number to divide
		Ratio operator/(const Ratio &r) const;
		template<typename U>
		inline friend Ratio operator/(const Ratio &r, const U &value) {return r/convertFloatToRatio(value,4);}
		template<typename U>
		inline friend Ratio operator/(const U &value, const Ratio &r) {return convertFloatToRatio(value,4)/r;}


		/// \brief operator < for rational numbers
		/// \param r the rational number to compare
		bool operator<(const Ratio &r) const;
		template<typename U>
		inline friend bool operator<(const Ratio &r, const U &value) {return r < convertFloatToRatio(value,4);}
		template<typename U>
		inline friend bool operator<(const U &value, const Ratio &r) {return convertFloatToRatio(value,4) < r;}
	
		bool operator<=(const Ratio &r) const;
		template<typename U>
		inline friend bool operator<=(const Ratio &r, const U &value) {return r <= convertFloatToRatio(value,4);}
		template<typename U>
		inline friend bool operator<=(const U &value, const Ratio &r) {return convertFloatToRatio(value,4) <= r;}

		bool operator>(const Ratio &r) const;
		template<typename U>
		inline friend bool operator>(const Ratio &r, const U &value) {return r > convertFloatToRatio(value,4);}
		template<typename U>
		inline friend bool operator>(const U &value, const Ratio &r) {return convertFloatToRatio(value,4) > r;}


		bool operator>=(const Ratio &r) const;
		template<typename U>
		inline friend bool operator>=(const Ratio &r, const U &value) {return r >= convertFloatToRatio(value,4);}
		template<typename U>
		inline friend bool operator>=(const U &value, const Ratio &r) {return convertFloatToRatio(value,4) >= r;}


		bool operator==(const Ratio &r) const;
		template<typename U>
		inline friend bool operator==(const Ratio &r, const U &value) {return r == convertFloatToRatio(value,4);}
		template<typename U>
		inline friend bool operator==(const U &value, const Ratio &r) {return convertFloatToRatio(value,4) == r;}

		bool operator!=(const Ratio &r) const;
		template<typename U>
		inline friend bool operator!=(const Ratio &r, const U &value) {return r != convertFloatToRatio(value,4);}
		template<typename U>
		inline friend bool operator!=(const U &value, const Ratio &r) {return convertFloatToRatio(value,4) != r;}
		//inline friend Ratio operator*(const T &value, const Ratio &r) {return r*value;};
		//inline friend Ratio operator/(const T &value, const Ratio &r) {return Ratio(value)/r;};
		//inline friend Ratio operator-(const Ratio &r) {return Ratio(-r.m_num,-r.m_den);}; // unary minus

		/// \brief operator print for rational numbers
		/// \param r the rational number to print
		template<typename U>
        friend std::ostream& operator<< (std::ostream& stream, const Ratio<U> &r);

		/// \brief operator sin for rational numbers
		/// \param r the rational number to use
		static Ratio sin(const Ratio &r);
		/// \brief operator cos for rational numbers
		/// \param r the rational number to use
		static Ratio cos(const Ratio &r);
		/// \brief operator tan for rational numbers
		/// \param r the rational number to use
		static Ratio tan(const Ratio &r);
		/// \brief operator exp for rational numbers
		/// \param r the rational number to use
		static Ratio exp(const Ratio &r);
		/// \brief operator ln for rational numbers
		/// \param r the rational number to use
		static Ratio ln(const Ratio &r);
			/// \brief operator log10 for rational numbers
		/// \param r the rational number to use
		static Ratio log10(const Ratio &r);
		/// \brief operator abs for rational numbers
		/// \param r the rational number to use
		static Ratio abs(const Ratio &r);
		/// \brief operator pow for rational numbers
		/// \param r the rational number to use
		static Ratio pow(const Ratio &r, const T &n);
		/// \brief operator sqrt for rational numbers
		/// \param r the rational number to use
		static Ratio sqrt(const Ratio &r);

		static Ratio invert(const Ratio &r);

		//static float invert(const float &x);

		void reduce();
		static Ratio reduce(const Ratio &r);

		static int intPart(const Ratio &r);

		static int intPart(const float &x);

		static Ratio convertFloatToRatio(const float &x, unsigned int nbIter);

		static float convertRatioToFloat(const Ratio &r);
};

template <typename T>
Ratio<T>::Ratio(const T& value){
	const Ratio<T> r(convertFloatToRatio(value,4));
	this->m_num = r.getNumerator();
	this->m_den = r.getDenominator();
}
//------------------------------ARITHMETICS OPERATORS--------------------------------------//
template <typename T>
Ratio<T> Ratio<T>::operator+(const Ratio<T> &r) const {
	return Ratio<T>(this->m_num * r.m_den + this->m_den * r.m_num, this->m_den * r.m_den);
}

template <typename T>
Ratio<T> Ratio<T>::operator-(const Ratio<T> &r) const {
	return Ratio<T>(this->m_num * r.m_den - this->m_den * r.m_num, this->m_den * r.m_den);
}

template <typename T>
Ratio<T> Ratio<T>::operator-() const{
	return Ratio<T>(-m_num,m_den);
}


template <typename T>
Ratio<T> Ratio<T>::operator*(const Ratio<T> &r) const {
	if (this->m_den == 0 || r.m_den == 0){
        throw std::overflow_error("You can't divide by zero ! You're so CRAZY ");
    }
	return Ratio<T>(this->m_num* r.m_num, this->m_den*r.m_den);
}

template <typename T>
Ratio<T> Ratio<T>::operator/(const Ratio<T> &r) const {
	return Ratio<T>(this->m_num * r.m_den, r.m_num * this->m_den);
}
//----------------------------------------------------------------------------------------//

//------------------------------COMPARISON OPERATORS--------------------------------------//

template <typename T>
bool Ratio<T>::operator<(const Ratio<T> &r) const {
	return (this->m_num * r.m_den < this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator<=(const Ratio<T> &r) const {
	return (this->m_num * r.m_den <= this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator>(const Ratio<T> &r) const {
	return (this->m_num * r.m_den > this->m_den * r.m_num);
}


template <typename T>
bool Ratio<T>::operator>=(const Ratio<T> &r) const {
	return (this->m_num * r.m_den >= this->m_den * r.m_num);
}



template <typename T>
bool Ratio<T>::operator==(const Ratio<T> &r) const {
	return (this->m_num * r.m_den == this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator!=(const Ratio<T> &r) const {
	return (this->m_num * r.m_den != this->m_den * r.m_num);
}
//----------------------------------------------------------------------------------------//


template<typename T>
std::ostream& operator<<(std::ostream& stream, const Ratio<T> &r){
	stream << "(" << r.m_num << "/" << r.m_den << ")";
    return stream;
}

//------------------------------ARITHMETIC+ OPERATORS--------------------------------------//
template <typename T>
Ratio<T> Ratio<T>::sin(const Ratio<T> & r){
	return convertFloatToRatio(std::sin(convertRatioToFloat(r)),4);
}

template <typename T>
Ratio<T> Ratio<T>::cos(const Ratio<T> & r){
	return convertFloatToRatio(std::cos(convertRatioToFloat(r)),4);
}

template <typename T>
Ratio<T> Ratio<T>::tan(const Ratio<T> & r){
	return convertFloatToRatio(std::tan(convertRatioToFloat(r)),4);
}

template <typename T>
Ratio<T> Ratio<T>::exp(const Ratio<T> & r){
	return convertFloatToRatio(std::exp(convertRatioToFloat(r)),4);
}

template <typename T>
Ratio<T> Ratio<T>::ln(const Ratio<T> & r){
	return convertFloatToRatio(std::log(r.m_num) - std::log(r.m_den), 4);
}
template <typename T>
Ratio<T> Ratio<T>::log10(const Ratio<T> & r){
	return convertFloatToRatio(std::log10(r.m_num) - std::log10(r.m_den), 4);
}


template <typename T>
Ratio<T> Ratio<T>::abs(const Ratio<T> & r){
	return Ratio<T>(std::abs(r.m_num),std::abs(r.m_den));
}

template <typename T>
Ratio<T> Ratio<T>::pow(const Ratio<T> & r, const T &n){
	return Ratio<T>(std::pow(r.m_num,n),std::pow(r.m_den,n));
}

template <typename T>
Ratio<T> Ratio<T>::invert(const Ratio<T> &r){
	return Ratio<T>(r.m_den,r.m_num);
}

// template <typename T>
// float Ratio<T>::invert(const float &x){
// 	return Ratio<T>()
// }

template <typename T>
Ratio<T> Ratio<T>::sqrt(const Ratio<T> &r){

    if(r.m_num || r.m_den < 0)
	{
		throw std::overflow_error("You can't sqrt a negative number ! You're so WILD ");
	}

	return Ratio<T>(std::sqrt(r.m_num),std::sqrt(r.m_den));
}

//----------------------------------------------------------------------------------------//

//------------------------------FONCTIONS--------------------------------------//
template <typename T>
int Ratio<T>::intPart(const Ratio &r){
	int iterator = 0;
	Ratio<T> error(2,1);

	if(r<1){
		return 0;
	}

	if(r==1){
		return 1;
	}

	while(error>1){
		iterator++;
		error = r - iterator;	
	}

	return iterator;
}
template <typename T>
int Ratio<T>::intPart(const float &x){
	int iterator = 0;
	float error = 2.0;

	if(x<1){
		return 0;
	}
	if(x==1){
		return 1;
	}

	while(error>1){
		iterator++;
		error = x - iterator;
	}
	
	return iterator;
}

template <typename T>
void Ratio<T>::reduce(){
	if(this->m_num < 0 && this->m_den < 0)
	{
		this->m_num *= -1;
		this->m_den *= -1;
	}
	if(this->m_den < 0 && this->m_num > 0)
	{	
		this->m_num *= -1;
		this->m_den *= -1;
	}
	//si T est un entier, on utilise gcd()
	if constexpr (std::is_integral_v<T>){
	int theGcd = std::__gcd(this->m_num, this->m_den);

	this->m_num = this->m_num / theGcd;
	this->m_den = this->m_den / theGcd;
	} else {

		//si T est un float, on utilise l'algorithme d'Euclide étendu
		//l'algorithme d'Euclide permet de trouver le plus grand diviseur commun entre
		//deux nombre à virgule floattante
		T a  = this->m_num;
		T b =  this->m_den;
		T x = 1, y = 0, x_last = 0, y_last = 1, q, temp;
		while(b != 0){
			q = std::floor(a/b);
			temp = std::fmod(a, b); //on utilise fmod pour faire a % b, avec a et b nombres flottants
			a = b;
			b = temp;

			temp = x_last;
			x_last = x - q * x_last;
			x = temp;

			temp = y_last;
			y_last = y - q * y_last;
			y = temp;
		}
			this->m_num = this->m_num / a;
			this->m_den = this->m_den / a;
	}


}

template <typename T>
Ratio<T> Ratio<T>::reduce(const Ratio<T> & r){

	T theGcd = std::__gcd(r.m_num, r.m_den);
	if(theGcd == 1){
		return Ratio<T>(r.m_num,r.m_den);
	}
	T newNum = r.m_num / theGcd;
	T newDen = r.m_den / theGcd;

	return Ratio<T>(newNum, newDen);

}

template <typename T>
Ratio<T> Ratio<T>::convertFloatToRatio(const float &x, unsigned int nbIter){


	if(x == 0)
	{
		return Ratio<T>(0,1);
	}

	if(nbIter == 0)
	{
		return Ratio<T>(0,1);
	}

	if( x < 0)
	{
		return -convertFloatToRatio(-x,nbIter);
	}

	if(x < 1)
	{
		return invert(convertFloatToRatio(std::round(1/x * 1000.0) / 1000.0, nbIter));
	}

	if(x >= 1)
	{
		double q = intPart(x);
		return (Ratio<T>(q,1) + convertFloatToRatio(x - q, nbIter - 1));
	}
	return Ratio<T>(0,1);
}

template <typename T>
float Ratio<T>::convertRatioToFloat(const Ratio &r){

    if (r.m_den == 0)
        throw std::overflow_error("You can't divide by Zero ! ");
		
    return r.m_num/(float)r.m_den;
}

//----------------------------------------------------------------------------------------//


#endif