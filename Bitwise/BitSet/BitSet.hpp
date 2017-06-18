#ifndef BITSET_HPP
#define BITSET_HPP

#include <string>

class BitSet
{
public:

	BitSet() : mBits(0) {}
	BitSet(int value) : mBits(value) {}
	BitSet(long int value) : mBits(value) {}
	BitSet(long long int value) : mBits(value) {}

	BitSet(const std::string& value);

	void setValue(int value);
	void setValue(long int value);
	void setValue(long long int value);
	void setValue(std::string value);

	// Converts the current value of the bit field to desired type 
	int toInt() const;
	long int toLong() const;
	long long int toLongLong() const;
	std::string toString() const;

	// Utility methods

	unsigned int operator[](int index) const;	// Returns the bit value at required index.
	long long int operator()(int index, int value);	// Set the bit with given index to given
													// value and returns the new value
	BitSet& operator=(BitSet& pSource);	// Copy operator

private:

	void setStringToBit(const std::string& value);

	long long int mBits;

};

#endif // !BITSET_HPP
