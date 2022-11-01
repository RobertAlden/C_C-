// lab83.cpp
// This program will display a multiplication table for numbers 1-10. 
//-------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  for(int row = 1; row <= 10; row++)
  {
    for(int col = 1; col <= 10; col++)
    {
     // YOUR CODE: output the product (row*col); use setw(4) to format
	cout << setw(5) << row * col << " ";

    }
    cout << endl;
  }

  return 0;
}

