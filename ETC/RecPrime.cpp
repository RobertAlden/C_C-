#include <iostream>
using namespace std;

int isprime(int p, int i = 2){
	if (p == i) {return 1;}
	if (p % i == 0) {return 0;}
	return isprime(p,i+1);
}
	


main(){/*
	for (int i = 0; i < 15; i++) {
		cout <<  "is " << i << "prime? ";
		if (isprime(i)) {
			cout << "yes." << endl;
		} else {
			cout << "no." << endl;
		}
	}*/
	isprime(215);
	return 0;
}
