#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

double myAddition(double, double);
double mySubtraction(double, double);
double myMultiplication(double, double);
double myDivision(double, double);
int myPower(int, int);
void myMenu();
void selection();

main(){
	myMenu();
	return 0;
}

double myAddition(double a, double b){
	double result;
	result = a+b;
	return result;
};
double mySubtraction(double a, double b){
	double result;
	result = a-b;
	return result;
};
double myMultiplication(double a, double b){
	double result;
	result = a*b;
	return result;
};
double myDivision(double a, double b){
	double result;
	result = a/b;
	return result;
};
int myPower(int a, int b){
	int result = b;
	
	for (int x = 1; x<a;x++)
	{
	result = result*b;	
//	cout << result << endl;
	};
	
	return result;
};

void myMenu(){
	cout << "Calculator" << endl;
	cout << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiplication" << endl;
	cout << "4. Division" << endl;
	cout << "5. Power" << endl;
	cout << "   Select an operation (1, 2, 3, 4, 5):" << endl;
	selection();
};

void selection(){
	int select;
	int a,b,resultb;
	double c,d,result;
	cin >> select;
	
	switch (select) {
		case 1:
		cout << "enter first operand: " << endl;
		cin >> c;
		cout << "enter second operand: " << endl;
		cin >> d;
		result = myAddition(c,d);
		cout << "the result is: " << result << endl;
		break;
		case 2:
		cout << "enter first operand: " << endl;
		cin >> c;
		cout << "enter second operand: " << endl;
		cin >> d;
		result = mySubtraction(c,d);
		cout << "the result is: " << result << endl;
		break;
		case 3:
		cout << "enter first factor: " << endl;
		cin >> c;
		cout << "enter second factor: " << endl;
		cin >> d;
		result = myMultiplication(c,d);
		cout << "the result is: " << result << endl;
		break;
		case 4:
		cout << "enter first operand: " << endl;
		cin >> c;
		cout << "enter second operand: " << endl;
		cin >> d;
		result = myDivision(c,d);
		cout << "the result is: " << result << endl;
		break;
		case 5:
		cout << "enter exponent: " << endl;
		cin >> a;
		cout << "enter value: " << endl;
		cin >> b;
		resultb = myPower(a,b);
		cout << "the result is: " << resultb << endl;
		break;
	}
	string query;
	cout << "do you wish to continue? ";
	cin >> query;
	if (query == "y") myMenu();
};
