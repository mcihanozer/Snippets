#include "BitSet.hpp"

#include "bitutilities.hpp"

BitSet::BitSet(const std::string& pValue)
	:mBits(0)
{
	setStringToBit(pValue);
}

void BitSet::setValue(int pValue)
{
	mBits = pValue;
}

void BitSet::setValue(long int pValue)
{
	mBits = pValue;
}

void BitSet::setValue(long long int pValue)
{
	mBits = pValue;
}

void BitSet::setValue(std::string pValue)
{
	setStringToBit(pValue);
}

int BitSet::toInt() const
{
	return (int)mBits;
}
long int BitSet::toLong() const
{
	return (long int)mBits;
}
long long int BitSet::toLongLong() const
{
	return (long long int)mBits;
}

std::string BitSet::toString() const
{
	return BitUtilities::longLongToStr(mBits);
}

void BitSet::setStringToBit(const std::string& pValue)
{
	mBits = BitUtilities::strToLongLong(pValue);
}

// UTILITIY METHODS
unsigned int BitSet::operator[](int pIndex) const
{
	return (mBits >> pIndex) & 1;
}

long long int BitSet::operator()(int pIndex, int pValue)
{
	long long int value = (pValue != 0) ? 1 : 0;
	long long int mask = -1;
	int maskHelper = 1;

	maskHelper = maskHelper << pIndex;
	mask = mask ^ maskHelper;

	mBits = mBits & mask;
	value = value << pIndex;
	mBits = mBits | value;

	return mBits;
}

BitSet& BitSet::operator=(BitSet &pSource)
{
	mBits = pSource.toLongLong();

	return *this;
}
