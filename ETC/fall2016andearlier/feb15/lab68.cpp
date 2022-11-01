// lab68.cpp
// Summations of integers using for-loops
//
// This program will compute the sum 1+2+3+...+1000
// The output should be 500500
//--------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int sum = 0;

  for(int n = 1; n <= 1000; n++)
  {
    // YOUR CODE: update the variable sum (add n to sum and store in sum)
	sum = sum + n;

  }

  cout << "Sum of 1 to 1000 = " << sum << endl;
  return 0;
}

