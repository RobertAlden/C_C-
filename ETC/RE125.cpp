#include <iostream>
#include <string>
using namespace std;

int isPalindrome (char * s, int len) {
	if (s[0] == s[len-1]) {
		return isPalindrome(s+1,len-2);
		return 1;
	} else {return 0;}
}

main(){
	char word1[] = "racecar";
	char word2[] = "palindromic";
	cout << word1;
	char *ptr = word1;
	if (isPalindrome(ptr,7)) {
		cout << " is palindromic." << endl;
	} else {
		cout << " is not palindromic." << endl;
	}
	cout << word2;
	ptr = word2;
	if (isPalindrome(ptr,11)) {
		cout << " is palindromic." << endl;
	} else {
		cout << " is not palindromic." << endl;
	}

	return 0;
}
