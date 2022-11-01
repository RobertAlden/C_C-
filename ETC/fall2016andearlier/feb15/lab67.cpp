// lab67.cpp
// Random numbers
//
// This program should display 20 random numbers in the range 1 to 100.
// Complete the program; then, compile & run it several times.
//---------------------------------------------------------------------
#include <iostream>
#include <cstdlib>	// for srand() and rand() functions
using namespace std;

int main()
{
  srand(time(0));	// Initializes the random number generator
  int r;		// a random number	


  // YOUR CODE: complete the for statament to repeat 20 times
  for(int n = 1; n<=20;n++)
  {
    // YOUR CODE: generate a random number between 1 and 100 and store it
    // in variable r.
    r = rand() % 100;


    cout << r << "  ";
  }

  cout << endl;
  return 0;
}
