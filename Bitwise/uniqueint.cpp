/************************************/
/*              ^-_-^               */
/*  M. Cihan Ozer - mcihanozer.com  */
/************************************/

#include <vector>
#include <iostream>

int getUnique(std::vector < int > theList)
{
    int result = 0;
    
    for(int ei = 0; ei < theList.size(); ei++)
    {
        // Whenever you XOR, same elements cancels each other
        result ^= theList[ei];
    }

    return result;

}

void main()
{
   using std::cin;
   using std::cout;

	// Get the size of the list and elements
    int size;
    cin >> size;
    cin.ignore (); 
    std::vector<int> theList(size);

    for(int ei = 0; ei < size; ei++)
    {
        cin >> theList[ei];
    }
    
    // Get the unique element in the list
    cout << getUnique(theList);
}
