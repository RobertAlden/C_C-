// lab130.cpp
// A void function using a reference parameter
// This program will simply read a number and display it.
// Add your code where it is requested.
//
//-----------------------------------------------------------------
#include <iostream>
using namespace std;

// Function prototype

void getInteger(int &number);
// Reads an integer from the keyboard and returns it to the caller.
 
//-----------------------------------------------------------------
int main()
{
  int number;

  // YOUR CODE: call the getInteger function using number
getInteger(number);


  // YOUR CODE: output the number using a cout statement

cout << number << endl;

  return 0;
}
//---------------------------------------------------------------
// Function implementation

void getInteger(int &number)
{
  // YOUR CODE: ask the user to enter an integer and then input it
  // into number.
cout << "input an interger: " << endl;
cin >> number;


}
//---------------------------------------------------------------
