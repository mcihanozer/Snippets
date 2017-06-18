#include "bitutilities.hpp"

#define MIN_WORD_SIZE 4

namespace BitUtilities
{
	int strToInt(const std::string& pValue)
	{
		return (int)strToLongLong(pValue);
	}

	long int strToLong(const std::string& pValue)
	{
		return (long)strToLongLong(pValue);
	}

	long long int strToLongLong(const std::string& pValue)
	{
		long long int bits = convertStrToBits(pValue);

		if (pValue[0] == '1')
		{
			bits = apply2sComponent(bits);
		}

		return bits;

	}

	long long int convertStrToBits(const std::string& pValue)
	{
		long long int result = 0;

		for (int bi = 0; bi < pValue.size(); bi++)
		{
			if (pValue[bi] == '1')
			{
				result += pow(2, (pValue.size() - (bi + 1)));
			}
		}

		return result;
	}

	long long int apply2sComponent(const long long int pValue)
	{
		long long int shiftBit = 1;
		long long int result = 0;
		int counter = 0;

		while (pValue >= shiftBit)
		{
			int newVal = !((pValue & shiftBit) != 0 ? 1 : 0);
			newVal = newVal << counter;
			result |= newVal;

			shiftBit = shiftBit << 1;
			counter++;
		}

		result += 1;

		return (result * -1);
	}

	std::string intToStr(const int pValue)
	{
		return longLongToStr(pValue);
	}

	std::string longToStr(const long int pValue)
	{
		return longLongToStr(pValue);
	}

	std::string longLongToStr(const long long int pValue)
	{
		std::string strBit = "";
		long long int copyBit = pValue;

		char zero, one;

		if (copyBit < 0)
		{
			strBit += "1";
			// Get ready for 2's complement conversion
			zero = '1';
			one = '0';

			copyBit *= -1;
			copyBit -= 1;
		}
		else
		{
			strBit += "0";
			zero = '0';
			one = '1';
		}

		strBit += convertBitsToStr(zero, one, copyBit);

		if (strBit.size() < MIN_WORD_SIZE)
		{
			std::string signCopy = "";

			while ((strBit.size() + signCopy.size()) < MIN_WORD_SIZE)
			{
				signCopy += strBit[0];
			}

			strBit = signCopy + strBit;
		}

		return strBit;
	}

	std::string convertBitsToStr(const char pZero, const char pOne, long long int pBits)
	{
		std::string strBit = "";

		while (pBits > 0)
		{
			if (pBits % 2 == 0)
			{
				strBit = pZero + strBit;
			}
			else
			{
				strBit = pOne + strBit;
			}

			pBits /= 2;
		}

		return strBit;
	}

}
