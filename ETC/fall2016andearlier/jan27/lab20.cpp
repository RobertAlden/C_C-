// lab20.cpp
// This program calculates how far an object drops in a freefall.
//
// Input:  time (in seconds)
// Output: distance
//
// Formula: distance = 0.5 * acceleration * time * time
// where acceleration is 32 (feet per second for gravity)
//
// Test data
// time = 10, distance = 1600
// time = 60, distance = 57600
//----------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  const int ACCELERATION = 32;
  double time, distance, yard, mile;

  // input the time (YOUR CODE)

  cout << "Input duration of fall: " << endl;
  cin >> time;
  // calculate the distance
  // YOUR CODE. use the ACCELERATION constant in your formula
  distance = .5 * ACCELERATION * time * time;
  yard = distance * 0.333;
  mile = distance * 0.000189384;
  // output the distance (YOUR CODE)
  cout << "Total distance in various metrics is : " << endl;
  cout << "Feet: " << distance << ", Yards: " << yard << ", Miles: " << mile << endl;


  return 0;
}
