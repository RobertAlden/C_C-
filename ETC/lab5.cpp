#include <iostream>
#include <fstream>
using namespace std;

main(){
	ifstream src ("infile.txt");
	int sum = 0;
	int num = 0;
	while (src >> num) {
		sum += num;
	}
	src.close();
	ofstream dest ("outfile.txt");
	dest << sum;
	dest.close();
	return 0;
}
