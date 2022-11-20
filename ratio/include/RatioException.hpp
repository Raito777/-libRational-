#pragma once

#include <exception>
#include <string>


enum class ErrorLevel {minor, major, fatal};

std::string ErrorLevel2Sstring(const ErrorLevel &errorLevel);

class RatioException : public std::exception
{
	public:

		RatioException(const std::string &description = "", const int &errorId = 0, const ErrorLevel &errorLevel = ErrorLevel::minor) noexcept ;

		virtual ~RatioException() noexcept {}

	public:
		const char *what() const noexcept override 
		{
			return m_what.c_str();
		}

	private:
		std::string m_what;
};

// convert enum to string
std::string ErrorLevel2Sstring(const ErrorLevel &errorLevel){
	std::string errorLevelString;
	switch(errorLevel){
		case ErrorLevel::minor :
			errorLevelString = "minor";
			break;
		case ErrorLevel::major :
			errorLevelString = "major";
			break;
		case ErrorLevel::fatal :
			errorLevelString = "fatal";
			break;
		default : 
			errorLevelString = "unknown";
	};

	return errorLevelString;
}


RatioException::RatioException(const std::string &description, const int &errorId, const ErrorLevel &errorLevel) noexcept	
{
	m_what	= std::string("\nException launched:")
	        + "\n   Level   : " + ErrorLevel2Sstring(errorLevel)
	        + "\n   Code    : " + std::to_string(errorId)
	        + "\n   Message : " + description;
}