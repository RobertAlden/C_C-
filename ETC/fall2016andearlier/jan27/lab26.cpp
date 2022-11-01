// lab26.cpp
// To be able to buy an M-rated video game the buyer must be 17 or older.
// This program inputs the birth year of a game player and outputs the msg
// "OK TO BUY" or "NOT ALLOWED".
//
// input: 	year
// calculate:	age
// output:	"ALLOWED" or "NOT ALLOWED"
//
// Add your code to the missing part and test the program using this data:
// year		output
// 2000		NOT ALLOWED
// 1990		ALLOWED
//------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int year, age;

  cout << "Enter your birth year: ";
  cin  >> year;

  // ADD YOUR CODE: calculate age (based on the current year 2016)
  age = 2016 - year;


  // ADD YOUR CODE: use an if-statement and output the proper message
 if (age < 17)
{
 cout << "Not allowed." << endl;
}
 else cout << "Allowed." << endl;


  return 0;
}
