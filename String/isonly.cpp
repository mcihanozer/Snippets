/************************************/
/*              ^-_-^               */
/*  M. Cihan Ozer - mcihanozer.com  */
/*          2016 - Montreal         */
/************************************/

// Check whether the string includes only digits
// (For ASCII Table)
// Run-time O(n), where n is length of the string
bool isOnlyDigits(const string& input)
{
	for(int si = 0; si < input.length(); si++)
	{
		// 0: 48, 9: 57 So, check whether the char is in [48,57] range
		int asciiVal = (int)input[si];
		if(asciiVal < 48 || asciVal > 57)
		{
			return false; // Input includes more then digits
		}
	}
	
	return true; // Yep, just digits
}

// Locating upper case letters in the given string (Uses ASCII Table)
// Run-time O(n), where n is length of the string
void locateUpperCase(const string& input)
{
	for(int si = 0; si < input.length(); si++)
	{
		// A: 65, Z: 90 So, if the char is in [65, 90] range, it is upper case
		int asciiVal = (int)input[si];
		if(asciiVal > 64 || asciVal < 91)
		{
			// You found your upper case letter,
			// do whatever you want now!
		}
	}
}
