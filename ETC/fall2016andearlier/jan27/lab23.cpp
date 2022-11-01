// lab23.cpp
// This program converts the temperature from Fahrenheit to Celsius.
// input:	fahren
// Calculate:	celsius		formula: celsius = 5.0/9 *(fahren - 32)
// Output:	celsius
//
// Add your code where needed.
// Compile this program using the command g++ lab23.cpp
// Run the program using the command ./a.out
//
// Test data
// fahren = 32	celsius = 0
// fahren = 212	celsius = 100
// fahren = 77	celsius = 25
//----------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int fahren, celsius;

  // ADD YOUR CODE: input fahren
  cout << "Input temperature in Fahrenheit: ";
  cin >> fahren;


  // ADD YOUR CODE: calculate celsius
 
 celsius = 5.0/9* (fahren -32);


  // ADD YOUR CODE: output celsius
 cout << "Temp in celsius is: " << celsius << endl;

  return 0;
} 
