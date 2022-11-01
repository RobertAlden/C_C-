#include <iostream>
using namespace std;

void quiz(int i){ // 5
	if (i > 1) {
		quiz(i/2); //  
		quiz(i/2);
	}
	cout << "*";
}
/*
quiz(5) "*"
-
quiz(2) "*"
quiz(2) "*"
-
quiz(1) "*"
quiz(1) "*"
quiz(1) "*"
quiz(1) "*"

*/

main(){
	quiz(75);
	cout << endl;
	return 0;
}
