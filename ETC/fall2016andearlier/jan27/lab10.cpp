// lab10.cpp
// This program calculates the surface area and volume of a rectangular box.
//
// Input:  length, width, height
// Output: area, volume
//
// Formulas: area = (2 * length * width) + (2 * length * height) +
//		    (2 * width * height) 
//
// volume = length * width * height
//
// Test data: 
//	length=20, width=15, height = 10
//	volume = 3000
//	area   = 1300
//--------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  double length, width, height;
  double area, volume;

  cout << "Enter the length of a box : ";
  cin  >> length;

  cout << "Enter the width of the box: ";
  cin  >> width;

  // YOUR CODE: input the height
  cout << "Enter the height of the box: ";
  cin >> height;


  // YOUR CODE: calculate the area
  area = (2 * length * width) + (2 * width * height) + (2 * length * height);
 

  // YOUR CODE: calculate the volume
  volume = length * width * height;


  // YOUR CODE: output the area and volume (using prompts)
  cout << "volume is equal to: " << volume << endl;
  cout << "area is equal to: " << area << endl;



  return 0;
}
