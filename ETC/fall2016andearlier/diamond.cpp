#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void displayDiamond(int);

int main(){
	int base;
	cout << "Input a odd number value for width for diamond: ";
	cin >> base;
	//if (base / 2 != 0) && (base > 2) 
	displayDiamond(base);	
	/*else 
	{cout << "Your input failed to meet requested parameters so it was adjusted." << endl;
	base++;
	displayDiamond(base);
	}
	*/
	return 0;
	
};
void displayDiamond(int num){
	// This forloop cover the top half of the diamond.
	for (int i = 0;i < ((num-1)/2); i++){
		int space = floor((num - (2 * i)) / 2);
		for (int q = 0;q < space;q++)
		{
			cout << "  ";
		};
		for (int f = 0;f < i*2+1;f++) cout << " *";
	
		for (int r = 0;r < space;r++)
		{
			cout << "  ";
		};
		cout << endl;
	};
	// This loop covers the middle line which will always be the defined value in width
	for (int i = 0;i<num;i++){
		cout << " *";
	};
	cout << endl;
	// And this loop tapers off the diamond.
	for (int i = 1;i < ((num-1)/2)+1; i++){
		int space = i;
		for (int q = 0;q < space; q++){
			cout << "  ";
		};
		for (int f = 0;f < num - (space*2);f++){
			 cout << " *";
		};
		for (int q = 0;q < space; q++){
			cout << "  ";
		};
	cout << endl;
	};

};
