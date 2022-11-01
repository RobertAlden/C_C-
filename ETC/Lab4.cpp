#include <iostream>
using namespace std;

void pattern(int n){
	cout << n << endl;
	if (n<8242) {
	pattern(2 * n);
	}
	cout << n << endl;
}

int main(){
	pattern(840);
	return 0;
}
