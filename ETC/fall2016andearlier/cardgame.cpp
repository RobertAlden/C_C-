// A practice program for CS-1314: a simple card game
// The dealer draws 2 random cards and the player draws 2 cards.
// The portion to determine who wins has not been implemented
// yet.
//-------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>	// for rand(), srand() functions
using namespace std;

int main()
{
  int  rank[52];	// This array holds the rank of all cards.
  char suit[52];	// This array holds the suit of all cards.
  int  num;		// numeric value of some card

  srand(time(0));

  // Create a deck of cards
  num = 1;
  for(int i = 0; i < 52; i = i + 4)
  {
    suit[i]   = 'C';
    suit[i+1] = 'D';
    suit[i+2] = 'H';
    suit[i+3] = 'S';

    rank[i] = rank[i+1] = rank[i+2] = rank[i+3] = num;
    num++;
  }

  // Output the deck; for verification only
  for(int i = 0; i < 52; i++){
    cout << "[";
    if(rank[i] == 11)
      cout << 'J';
    else if(rank[i] == 12)
      cout << 'Q';
    else if(rank[i] == 13)
      cout << 'K';
    else
      cout << rank[i];

    cout << ' ' << suit[i] << ']' << endl;
  }
  cout << endl;


  // Dealer draws 2 cards (no face cards)

  int i = rand() % 40;        // Random number range 0-39
  while(rank[i] == 0)		// Draw the first card
    i = rand() % 40;		// Make sure the card is available

  int num1 = rank[i];		// Save the rank of 1st card
  rank[i]  = 0;			// Mark this card as used
 
  int j = rand() % 40;        // Random number range 0-39
  while(rank[j] == 0)		// Draw the 2nd card
    j = rand() % 40;		// Make sure the card is available

  int num2 = rank[j];		// Save the rank of 2nd card
  rank[j] = 0;				// Mark this card as used
  

  // Show dealer's cards
  cout << "DEALER: [" << num1 << " " << suit[i] << "] "; 
  cout << "[" << num2 << " " << suit[j] << "]"  << endl;

  // Remember dealer’s cards
  int dealerCard1 = num1;
  char dealerSuit1 = suit[i];
  int dealerCard2 = num2;
  char dealerSuit2 = suit[j];


  // Player draws 2 cards (no face cards)

  i = rand() % 40;            // Random number range 0-39
  while(rank[i] == 0)		// Draw the first card
    i = rand() % 40;		// Make sure the card is available

  num1 = rank[i];			// Save the rank of 1st card
  rank[i] = 0;				// Mark this card as used
 
  j = rand() % 40;            // Random number range 0-39
  while(rank[j] == 0)		// Draw the 2nd card
    j = rand() % 40;		// Make sure the card is available

  num2 = rank[j];			// Save the rank of the 2nd card
  rank[j] = 0;				// Mark this card as used
  
  // Show player's cards
  cout << "YOU:    [" << num1 << " " << suit[i] << "] "; 
  cout << "[" << num2 << " " << suit[j] << "]"  << endl;


  // Remember Player’s cards
  int playerCard1 = num1;
  char playerSuit1 = suit[i];
  int playerCard2 = num2;
  char playerSuit2 = suit[j];
  


  // In this section implement whatever rule you wish to
  // determine who wins this hand of the game. Note that as of 
  // now 4 cards have been drawn from the deck and the info for 
  // these 4 cards are in these variables:
  // dealerCard1, dealerSuit1, dealerCard2, dealerSuit2
  // playerCard1, playerSuit1, playerCard2, playerSuit2



}

