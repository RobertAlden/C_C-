// lab29.cpp
//
// A SIMPLE GUESSING GAME
// In this program the computer generates a random number between 0 and 4.
// If the player guesses the number correctly, the player wins; otherwise,
// the player loses.
//
// input:	guess
// output:	"YOU WIN!" or "SORRY!"
//
// Add your code where needed. Run the program several times.
//---------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>	// for rand() function
using namespace std;

int main()
{
  int secret;		// computer's secret number
  int guess;		// player's guess


  srand(time(0));	// initializes the random number generator
  secret = rand() % 5;	// generates a random number between 0 and 4


  // YOUR CODE: input the player's guess
  cout << "Guess a number between 0 and 4:";
  cin >> guess;


  // YOUR CODE: output both the guess and secret number
  cout << "The number was actually: " << secret << endl;
  cout << "You guessed: " << guess << endl;
 
  // YOUR CODE: determine if the player wins (output a message)
  // HINT: you need to use an if-else statement to compare the
  // variables secret and guess.
  if (guess != secret)
{

  cout << "You guessed incorrectly." << endl;

}

 else

{

 cout << "You win!" << endl;

}

 

  return 0;
}
