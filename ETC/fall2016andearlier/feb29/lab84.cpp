// lab84.cpp
// Tracing a while-loop
//
// Read the following program. How many times will the while loop
// display the word 'hello'?
// Compile and run to see if you were correct.
//----------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int n = 0;

  while(n <= 10)
  {
    cout << "Hello...\n";
    n++;
  }

  return 0;
}

