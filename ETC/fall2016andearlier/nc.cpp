//Input: Number within range of 0 to 2000000000(+2bil)
//Find how many places are in the number.
//Then counting from the largest place, convery each digits into its written format and append the appropriate numeral to the end.
//Be sure to handle special cases: 11 (eleven), 12 (twelve) 13-19 (x-teen)
//Output: Text Version of Number

#include <iostream>
using namespace std;

int main()
{
	int digits, number, number2, x, i, teen;
	cout << endl;
	cout << "please enter your number you wish to convert (number must be < 1 billion):" << endl;
	cin >> number;
	number2 = number;
	x = number2;
	teen = 0;
	digits = 0; do { number /= 10; digits++; } while (number != 0);
	cout << "Your number is: " << endl;
	for (i = digits; i > 0; i--)
	{
		if (i==9)
		{   
			x = number2/100000000;
			number2 = number2 % 100000000;
			if (x == 1)
				cout << "one hundred ";
			else if (x == 2)
				cout << "two hundred ";
			else if (x == 3)
				cout << "three hundred ";
			else if (x == 4)
				cout << "four hundred ";
			else if (x == 5)
				cout << "five hundred ";
			else if (x == 6)
				cout << "six hundred ";
			else if (x == 7)
				cout << "seven hundred ";
			else if (x == 8)
				cout << "eight hundred ";
			else if (x == 9)
				cout << "nine hundred ";
		}
		else if (i==8)
		{
			x = number2/10000000;
			number2 = number2 % 10000000;
			if (x == 1)
				teen = 1;
			else if (x == 2)
				cout << "twenty ";
			else if (x == 3)
				cout << "thirty ";
			else if (x == 4)
				cout << "fourty ";
			else if (x == 5)
				cout << "fifty ";
			else if (x == 6)
				cout << "sixty ";
			else if (x == 7)
				cout << "seventy ";
			else if (x == 8)
				cout << "eighty ";
			else if (x == 9)
				cout << "ninety ";
		}
		else if (i==7)
		{
			x = number2/1000000;
			number2 = number2 % 1000000;
			if (teen == 1) 
			{
			if (x == 0)
				cout << "ten ";
			else if (x == 1)
				cout << "eleven ";
			else if (x == 2)
				cout << "twelve ";
			else if (x == 3)
				cout << "thirteen ";
			else if (x == 4)
				cout << "fourteen ";
			else if (x == 5)
				cout << "fifteen ";
			else if (x == 6)
				cout << "sixteen ";
			else if (x == 7)
				cout << "seventeen ";
			else if (x == 8)
				cout << "eighteen ";
			else if (x == 9)
				cout << "nineteen ";
			}
			else if (teen == 0)
			{
				if (x == 1)
				cout << "one ";
			else if (x == 2)
				cout << "two ";
			else if (x == 3)
				cout << "three ";
			else if (x == 4)
				cout << "four ";
			else if (x == 5)
				cout << "five ";
			else if (x == 6)
				cout << "six ";
			else if (x == 7)
				cout << "seven ";
			else if (x == 8)
				cout << "eight ";
			else if (x == 9)
				cout << "nine ";
			};
			cout << "million, ";
			teen = 0;
		}
		if (i==6)
		{   
			x = number2/100000;
			number2 = number2 % 100000;
			if (x == 1)
				cout << "one hundred ";
			else if (x == 2)
				cout << "two hundred ";
			else if (x == 3)
				cout << "three hundred ";
			else if (x == 4)
				cout << "four hundred ";
			else if (x == 5)
				cout << "five hundred ";
			else if (x == 6)
				cout << "six hundred ";
			else if (x == 7)
				cout << "seven hundred ";
			else if (x == 8)
				cout << "eight hundred ";
			else if (x == 9)
				cout << "nine hundred ";
		}
		else if (i==5)
		{
			x = number2/10000;
			number2 = number2 % 10000;
			if (x == 1)
				teen = 1;
			else if (x == 2)
				cout << "twenty ";
			else if (x == 3)
				cout << "thirty ";
			else if (x == 4)
				cout << "fourty ";
			else if (x == 5)
				cout << "fifty ";
			else if (x == 6)
				cout << "sixty ";
			else if (x == 7)
				cout << "seventy ";
			else if (x == 8)
				cout << "eighty ";
			else if (x == 9)
				cout << "ninety ";
		}
		else if (i==4)
		{
			x = number2/1000;
			number2 = number2 % 1000;
			if (teen == 1) 
			{
			if (x == 0)
				cout << "ten ";
			else if (x == 1)
				cout << "eleven ";
			else if (x == 2)
				cout << "twelve ";
			else if (x == 3)
				cout << "thirteen ";
			else if (x == 4)
				cout << "fourteen ";
			else if (x == 5)
				cout << "fifteen ";
			else if (x == 6)
				cout << "sixteen ";
			else if (x == 7)
				cout << "seventeen ";
			else if (x == 8)
				cout << "eighteen ";
			else if (x == 9)
				cout << "nineteen ";
			}
			else if (teen == 0)
			{
				if (x == 1)
				cout << "one ";
			else if (x == 2)
				cout << "two ";
			else if (x == 3)
				cout << "three ";
			else if (x == 4)
				cout << "four ";
			else if (x == 5)
				cout << "five ";
			else if (x == 6)
				cout << "six ";
			else if (x == 7)
				cout << "seven ";
			else if (x == 8)
				cout << "eight ";
			else if (x == 9)
				cout << "nine ";
			};
				cout << "thousand,";
			teen = 0;
		}
		if (i==3)
		{   
			x = number2/100;
			number2 = number2 % 100;
			if (x == 1)
				cout << " one hundred";
			else if (x == 2)
				cout << " two hundred";
			else if (x == 3)
				cout << " three hundred";
			else if (x == 4)
				cout << " four hundred";
			else if (x == 5)
				cout << " five hundred";
			else if (x == 6)
				cout << " six hundred";
			else if (x == 7)
				cout << " seven hundred";
			else if (x == 8)
				cout << " eight hundred";
			else if (x == 9)
				cout << " nine hundred";
		}
		else if (i==2)
		{
			x = number2/10;
			number2 = number2 % 10;
			if (x == 1)
				teen = 1;
			else if (x == 2)
				cout << " twenty";
			else if (x == 3)
				cout << " thirty";
			else if (x == 4)
				cout << " fourty";
			else if (x == 5)
				cout << " fifty";
			else if (x == 6)
				cout << " sixty";
			else if (x == 7)
				cout << " seventy";
			else if (x == 8)
				cout << " eighty";
			else if (x == 9)
				cout << " ninety";
		}
		else if (i==1)
		{
			cout << " ";
			x = number2/1;
			number2 = number2 % 1;
			if (teen == 1) 
			{
			if (x == 0)
				cout << "ten";
			else if (x == 1)
				cout << "eleven";
			else if (x == 2)
				cout << "twelve";
			else if (x == 3)
				cout << "thirteen";
			else if (x == 4)
				cout << "fourteen";
			else if (x == 5)
				cout << "fifteen";
			else if (x == 6)
				cout << "sixteen";
			else if (x == 7)
				cout << "seventeen";
			else if (x == 8)
				cout << "eighteen";
			else if (x == 9)
				cout << "nineteen";
			}
			else if (teen == 0)
			{
				if (x == 1)
				cout << "one";
			else if (x == 2)
				cout << "two";
			else if (x == 3)
				cout << "three";
			else if (x == 4)
				cout << "four";
			else if (x == 5)
				cout << "five";
			else if (x == 6)
				cout << "six";
			else if (x == 7)
				cout << "seven";
			else if (x == 8)
				cout << "eight";
			else if (x == 9)
				cout << "nine";
			};
			teen = 0;
			cout << "." << endl;
		};		
	}
	
	return(0);
}
