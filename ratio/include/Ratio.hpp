#ifndef RATIONNAL_H
#define RATIONNAL_H

#pragma once

#include <iostream>
#include <numeric>
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
		Ratio() = default;

		/// \brief constructor from a numerator and denominator
		/// \param numerator : the numerator of the rational number
		/// \param denominator : the denominator of the rational number
		Ratio(const T& numerator, const T &denominator) : m_num(numerator), m_den(denominator) {this->reduce();};

		/// \brief constructor from another rational number
		/// \param ratio the other rational number
		Ratio(const Ratio &ratio) = default;

		/// \brief destructor
		~Ratio() = default;

		/// \brief getter of the numerator
		inline T & numerator() {return m_num;};
		/// \brief getter of the denominator
		inline T & denominator() {return m_den;};
		/// \brief setter of the numerator
		inline const T & numerator() const {return m_num;};
		/// \brief setter of the denominator
		inline const T & denominator() const {return m_den;};

		/// \brief operator addition for rational numbers
		/// \param r the rational number to be added
		Ratio operator+(const Ratio &r) const;
		///\brief operator addition for rational numbers plus float/int
		/// \param r the float number to be added
		Ratio operator+(const float &value) const;
		/// \brief operator soustraction for rational numbers
		/// \param r the rational number to substract
		Ratio operator-(const Ratio &r) const;
		/// \brief operator unary minus operator
		Ratio operator-() const;
		/// \brief operator multiply for rational numbers
		/// \param r the rational number to multiply
		Ratio operator*(const Ratio &r) const;
		/// \brief operator divide for rational numbers
		/// \param r the rational number to divide
		Ratio operator/(const Ratio &r) const;

		/// \brief operator < for rational numbers
		/// \param r the rational number to compare
		bool operator<(const Ratio &r) const;
		bool operator<(const T &value) const;
		bool operator<=(const Ratio &r) const;
		bool operator<=(const T &value) const;
		bool operator>(const Ratio &r) const;
		bool operator>(const T &value) const;
		bool operator>=(const Ratio &r) const;
		bool operator>=(const T &value) const;

		bool operator==(const Ratio &r) const;
		bool operator==(const T &value) const;
		bool operator!=(const Ratio &r) const;
		bool operator!=(const T &value) const;
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
		/// \brief operator log for rational numbers
		/// \param r the rational number to use
		static Ratio log(const Ratio &r);
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

		static Ratio convertFloatToRatio(const float &x, unsigned int nbIter);

		static float convertRatioToFloat(const Ratio &r);
};
//------------------------------ARITHMETICS OPERATORS--------------------------------------//
template <typename T>
Ratio<T> Ratio<T>::operator+(const Ratio<T> &r) const {
	return Ratio<T>(this->m_num * r.m_den + this->m_den * r.m_num, this->m_den * r.m_den);
}

template <typename T>
Ratio<T> Ratio<T>::operator+(const float &value) const {
	Ratio<T> r = convertFloatToRatio(value,4);
	std::cout << "le ratio de value est :" << convertFloatToRatio(value,10) << std::endl;
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
bool Ratio<T>::operator<(const T &value) const {
	Ratio<T> ratioValue(value, 1);
	return (this->m_num * ratioValue.m_den < this->m_den * ratioValue.m_num);
}

template <typename T>
bool Ratio<T>::operator<=(const Ratio<T> &r) const {
	return (this->m_num * r.m_den <= this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator<=(const T &value) const {
	Ratio<T> ratioValue(value, 1);
	return (this->m_num * ratioValue.m_den <= this->m_den * ratioValue.m_num);
}

template <typename T>
bool Ratio<T>::operator>(const Ratio<T> &r) const {
	return (this->m_num * r.m_den > this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator>(const T &value) const {
	Ratio<T> ratioValue(value, 1);
	return (this->m_num * ratioValue.m_den > this->m_den * ratioValue.m_num);
}

template <typename T>
bool Ratio<T>::operator>=(const Ratio<T> &r) const {
	return (this->m_num * r.m_den >= this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator>=(const T &value) const {
	Ratio<T> ratioValue(value, 1);
	return (this->m_num * ratioValue.m_den >= this->m_den * ratioValue.m_num);
}

template <typename T>
bool Ratio<T>::operator==(const Ratio<T> &r) const {
	return (this->m_num * r.m_den == this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator==(const T &value) const {
	Ratio<T> ratioValue(value, 1);
	return (this->m_num * ratioValue.m_den == this->m_den * ratioValue.m_num);
}

template <typename T>
bool Ratio<T>::operator!=(const Ratio<T> &r) const {
	return (this->m_num * r.m_den != this->m_den * r.m_num);
}

template <typename T>
bool Ratio<T>::operator!=(const T &value) const {
	Ratio<T> ratioValue(value, 1);
	return (this->m_num * ratioValue.m_den != this->m_den * ratioValue.m_num);
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
	return Ratio<T>(std::sin(r.m_num/r.m_den),1);
}

template <typename T>
Ratio<T> Ratio<T>::cos(const Ratio<T> & r){
	return Ratio<T>(std::cos(r.m_num/r.m_den),1);
}

template <typename T>
Ratio<T> Ratio<T>::tan(const Ratio<T> & r){
	return Ratio<T>(std::tan(r.m_num/r.m_den),1);
}

template <typename T>
Ratio<T> Ratio<T>::exp(const Ratio<T> & r){
	return Ratio<T>(std::exp(r.m_num/r.m_den),1);
}

template <typename T>
Ratio<T> Ratio<T>::log(const Ratio<T> & r){
	return Ratio<T>(std::log(r.m_num)-std::log(r.m_den),1);
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
	T theGcd = std::gcd(this->m_num, this->m_den);
	this->m_num = this->m_num / theGcd;
	this->m_den = this->m_den / theGcd;

}

template <typename T>
Ratio<T> Ratio<T>::reduce(const Ratio<T> & r){

	T theGcd = std::gcd(r.m_num, r.m_den);
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

	if(x < 1)
	{
		return invert(convertFloatToRatio(1/x, nbIter));
		
	}

	if(x >= 1)
	{
		double q = floor(x);
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