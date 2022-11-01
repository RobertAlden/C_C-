// lab116.cpp
// Complete the coding of the given function.
// The function should calculate and return the perimeter of
// a rectangle.
// The main program is already written for you. Read the main function
// but DO NOT modify it.
//
// Compile and run. Test using the following data:
// If length = 10, width = 7,  then p = 34
// If length = 30, width = 30, then p = 120 
//----------------------------------------------------------------

#include <iostream>
using namespace std;

// function prototype
int perim(int length, int width);
//----------------------------------------------------------------

int main()
{
  int length, width, p;

  cout << "Enter the length: ";
  cin  >> length;

  cout << "Enter the width: ";
  cin  >> width;

  p = perim(length, width);

  cout << "Perimeter = " << p << endl;
  return 0;
}
//----------------------------------------------------------------

int perim(int length, int width)
{
  // YOUR CODE: return the perimeter of the rectangle


}
//----------------------------------------------------------------

