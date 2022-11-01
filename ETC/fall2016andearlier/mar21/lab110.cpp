// lab110.cpp
// Read the following program and determine what it prints.
// Then, compile and run to see if you were correct.
// Don't add any code to this program!
//-----------------------------------------------------------

#include <iostream>
using namespace std;

// function prototype (declaration)

int square(int num);
// Returns the square of an integer;
//-----------------------------------------------------------

int main()
{
 square(10);
 return 0;
}
//-----------------------------------------------------------

int square(int num)
{
  return num * num;
}
//-----------------------------------------------------------
