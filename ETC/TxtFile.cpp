#include <iostream>
#include <fstream>
using namespace std;

main(){
	int user = 999;
	ofstream dest ("numbers.txt");
	cout << "enter numbers till satisfied, input 0 to quit" << endl;
	while (user != 0)
	{
		cin >> user;
		dest << user << endl;
	}
	
	int input = 0;
	int count = 0;
	ifstream src ("numbers.txt");
	while (src >> input){
		cout << input << endl;
		count += input;
	} 
	cout << "sum is: " << count << endl;
	return 0;
}
