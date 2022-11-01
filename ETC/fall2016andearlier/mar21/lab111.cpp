// lab111.cpp
// This file contains a modified version of lab110.
// Trace the following program and determine what it prints.
// Then, compile and run to see if you were correct.
//---------------------------------------------------------------

#include <iostream>
using namespace std;

// function prototype

int square(int num);
// Returns the square of an integer.
//---------------------------------------------------------------

int main()
{
 cout << square(10) << endl;

 return 0;
}
//---------------------------------------------------------------

int square(int num)
{
  return num * num;
}
//---------------------------------------------------------------
