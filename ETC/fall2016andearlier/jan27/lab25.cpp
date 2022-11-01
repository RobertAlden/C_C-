// lab25.cpp
// This program inputs the altitude in feet from the keyboard, and then 
// outputs a message according to the following table:
//
// if altitude		output
// ---------------	-------
// less than 20000	"LOW"
// otherwise		"HIGH"
//
// Complete the program. Then, compile and run it several times
// to make sure it works according to the table.
//
// To compile:  g++  lab25.cpp
// To run:	./a.out
//----------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int altitude;

  cout << "Enter your altitude: ";
  cin  >> altitude;

  // ADD YOUR CODE BELOW THIS LINE

  if (altitude < 20000)
{
  cout << "Low." << endl;
}
 else cout << "High" << endl;




  return 0;
}
