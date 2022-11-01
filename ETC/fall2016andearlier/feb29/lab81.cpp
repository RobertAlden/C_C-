// lab81.cpp
// This program is supposed to display a rectangle of stars with
// 5 rows and 20 columns.
// The output should look like the following. Add your code where needed.
// ********************
// ********************
// ********************
// ********************
// ********************
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{

  // YOUR CODE: complete the heading of each loop
  // DO NOT change the body of the innermost loop

  for(int i=0; i<5; i++)
  {
    for(int b=0; b<20; b++)
    {
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}

