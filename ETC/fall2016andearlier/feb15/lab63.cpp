// lab63.cpp
// for-loops
//
// This program will display a table integers 1 to 20 including their squares
// and cubes. The output will look similar to the following:
// 1    1    1
// 2    4    8
// 3    9   27
// :
// 20  400  8000
//
// If you want numebrs to align properly, use the setw(5) to print each value.
//----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>	// for setw()
using namespace std;

int main()
{
  for(int n = 1; n <= 20; n++)
  {
   // YOUR CODE:
   // output three numbers: n, n squared, and n cubed; all on the same line
	cout << (n) << " ";
	cout << (n*n) << " ";
	cout << (n*n*n) << endl;

  }

  return 0;
}

