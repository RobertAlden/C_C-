// lab113.cpp
// This file contains a modified version of lab110.
// Trace the following program and determine what it prints.
// Then, compile and run to see if you were correct.
//----------------------------------------------------------------

#include <iostream>
#include <iomanip>	// for setw()
using namespace std;

// function prototype
int square(int num);
//----------------------------------------------------------------

int main()
{
  for(int n = 1; n <= 10; n++)
  {
    cout << setw(3) << n << setw(4) << square(n) << endl;
  }

  return 0;
}
//----------------------------------------------------------------

int square(int num)
{
  return num * num;
}
//----------------------------------------------------------------

