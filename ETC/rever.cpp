#include <iostream>
#include <string>
using namespace std;

void reverse(char *s, int len){
	char temp = s[0];
	for (int i = 0; i < len;i++) {s[i] = s[i+1];}
	s[len-1] = temp;
	if (len > 2) reverse(s , len-1);
}

main(){
	char word[] = "HelloWorld";
	cout << word << endl;
	char *ptr = word;
	reverse(ptr, 10);
	cout << word << endl;
	return 0;
}
