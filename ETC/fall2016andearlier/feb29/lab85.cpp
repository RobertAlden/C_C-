// lab85.cpp
// Complete the body of the loop so that even numbers 0 to 50 will be
// displayed.
// The output should be 0 2 4 6 ... 50
//--------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int n = 0;

  while(n <= 50)
  {
  if (n % 2 == 0)
	{
	cout << n << " ";
	}
n++;
  }
	cout << endl;
  return 0;
}

