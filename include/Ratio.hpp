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

//git test

/// \class Ratio
/// \brief class defining a ratio number.
template <typename T>
class Ratio{

	private : 
                T m_nominator;
                T m_denominator;

	public :
                // default constructor
                Ratio() = default;

		// constructor by value
                Ratio(const T& nominator, const T &denominator) : m_nominator(nominator), m_denominator(denominator) {};

                // copy constructor
		Ratio(const Ratio &ratio) = default;

		// destructor
		~Ratio() = default;

                // getter / setter
		inline T & nominator() {return m_nominator;};
		inline T & denominator() {return m_denominator;};
		inline const T & nominator() const {return m_nominator;};
		inline const T & denominator() const {return m_denominator;};

};

#endif