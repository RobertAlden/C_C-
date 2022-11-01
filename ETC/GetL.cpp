#include <iostream>
#include <fstream>
using namespace std;

main(){
	ifstream src ("Text.txt");
	char source[25];
	int stop;
	src.getline(source,21,',');
	do {
		cout << source << endl;
		cin >> stop;
		src.getline(source,21,',');
	} while (!src.eof());
	return 0;
}
