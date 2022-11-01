// lab66.cpp
// for-loops
//
// This program should display the following set of integers:
// -10 -5 0 5 10 15 20 ... 100
//-----------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  // YOUR CODE
  // insert the missing parts in the for-statement

  for(int n = -10;n<=100 ;n+=5)
  {
    cout << n << " ";
  }

  cout << endl;
  return 0;
}

