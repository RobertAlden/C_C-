#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream myfile ("OurFirstFile.txt");
	myfile << "A happy day";
	myfile.close();
	return 0;
}
