// lab86.cpp
// This program should compute the following sum:
// 1 + 4 + 7 + 10 + ... + 100
//
// Complete the body of the while loop.
// The answer should be 1717
//------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int sum = 0;
  int n = 1;

  while(n <= 100)
  {
sum = sum + n;
n= n +3;
  }

  cout << "sum = " << sum << endl;

  return 0;
}

