#ifndef BITUTILITIES_HPP
#define BITUTILITIES_HPP

#include <string>

namespace BitUtilities
{
	int strToInt(const std::string& value);
	long int strToLong(const std::string& value);
	long long int strToLongLong(const std::string& value);

	std::string intToStr(const int value);
	std::string longToStr(const long int value);
	std::string longLongToStr(const long long int value);

	long long int convertStrToBits(const std::string& value);
	std::string convertBitsToStr(const char zero, const char one, long long int bits);
	long long int apply2sComponent(const long long int value);
}



#endif // !BITUTILITIES_HPP
