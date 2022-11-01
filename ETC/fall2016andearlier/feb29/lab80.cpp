// lab80.cpp
// Tracing a nested for-loop
//
// Look at this program; can you tell how many times the
// word hello will be displayed on the screen?
// Compile, run and check to see if you were correct.
//-------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  for(int row = 1; row <= 3; row++)
  {
   for(int col = 1; col <= 5; col++)
   {
     cout << "hello ";
   }
   cout << endl;
  }

  return 0;
}

