// lab27.cpp
// This program inputs 2 numbers and stores the larger number in variable max.
// Then, it outputs max.
//
// input:	num1, num2
// output:	max
//----------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int num1, num2;
  int max;

  cout << "Enter an integer: ";
  cin  >> num1;

  cout << "Enter another integer: ";
  cin  >> num2;

  // ADD CODE: use one if-else statement and copy to max the larger number.
  // DO NOT USE ANY cout STMTS INSIDE THE if-STMT
  if (num1 > num2)
	 max = num1; 
  else
	 max = num2; 


  //---------------------------------------------------------------------
  cout << "The larger number is " << max << endl;
  
  return 0;
}
