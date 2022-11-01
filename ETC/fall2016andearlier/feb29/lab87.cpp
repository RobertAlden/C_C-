// lab87.cpp
// Complete the body of the loop so that it will compute the sum:
// 1 + 2 + 3 + ... + 100
//
// The answer should be 5050
//-----------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int sum = 0;	// keeps track of the summation
  int n = 1;

  while(n <= 100)
  {
  sum= sum +n;
	n++;

  }

  cout << "sum = " << sum << endl;

  return 0;
}

