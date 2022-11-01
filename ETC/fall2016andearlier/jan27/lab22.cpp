// lab22.cpp
//
// This program converts a given total elapsed time in seconds to
// hours, minutes, and seconds. For example, 3725 seconds corresponds to
// 1 hour, 2 minutes, and 5 seconds.
//
// Input:  time (in seconds)
// Output: hours, minutes, seconds
//
// Test data
// time =  3600, hours =  1, minutes =  0, seconds =  0
// time =  4230, hours =  1, minutes = 10, seconds = 30
// time = 50391, hours = 13, minutes = 59, seconds = 51
//-----------------------------------------------------------------------
#include <iostream>
using namespace std;

int main()
{
  int time;
  int hours, minutes, seconds;

  // input the time (YOUR CODE)
  cout << "Enter duration in seconds: ";
  cin >> time;


  // calculate hours (YOUR CODE)

  hours = time / 3600;
  time = time % 3600;

  // calculate minutes (YOUR CODE)

  minutes = time / 60;
  time = time % 60;
  // calculate seconds (YOUR CODE)
  seconds  = time; 

  // output hours, minutes, seconds (YOUR CODE)
 cout << "Your time is equivalent to: " << hours << ":" << minutes << ":" << seconds << "(H:M:S)" << endl;


  return 0;
}
