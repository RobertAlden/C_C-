#include <iostream>
using namespace std;

void IterFibonacci(int a) {
	int x=1, y=1, result;
	if (a < 3){
		cout << "Fibonacci value for " << a << "is 1." << endl;
	} else {
		
		for (int i = 0;i < a-2;i++){
			result = x+y;
			x = y;
			y = result;
		}
	}
	cout << "Fibonacci value for " << a << " is " << result << endl;
};

int RecurFibonacci(int a) {
	int x;
	if (a < 3) {
	return 1;
	} else {
	return RecurFibonacci(a - 1) + RecurFibonacci(a - 2);
	}
};

main (){
	int n;
	cout << " enter value for n ";
	cin >> n;
	IterFibonacci(n);
	cout << "Fibonacci value for " << n << " is " << RecurFibonacci(n) << endl;
	return 0;
}
