// lab82.cpp
// Print a flag
//
// This program is supposed to display a flag and a flag pole.
// The code to display the flag portion is already written.
// You need to write a nested loop (similar to the flag code)
// that will dislay the pole.
//--------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  // This code segment displays the flag. DO NOT CHANGE THIS CODE!
  for(int row = 1; row <= 10; row++)
  {
    for(int col = 1; col <= 40; col++)
    {
      cout << '*';
    }
    cout << endl;
  }
  //--------------------------------------------------------------

  // YOUR CODE: write a similar nested loop for the flag pole
  // print 15 rows and 7 columns of the character '|'
for (int i = 0;i<15;i++)
{
for (int b =0;b<7;b++)
{
cout << "|";
}
cout << endl;
}




  return 0;
}

