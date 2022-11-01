#include <iostream>
#include <fstream>
using namespace std;


int main(){
	ifstream myfile ("OurFirstFile.txt");
	string line;
	getline(myfile,line);
	cout << line << endl;
	myfile.close();
	return 0;
}
