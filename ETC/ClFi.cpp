#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CombineFiles {
	public:
		void combine(string File1, string File2){
			ifstream F1 (File1.c_str());
			string input1;
			getline(F1,input1);
			F1.close();
			
			ifstream F2 (File2.c_str());
			string input2;
			getline(F2, input2);
			F2.close();
			
			string File3 = "fileout.txt";
			ofstream dest (File3.c_str());
			dest << input1 << endl;
			dest << input2 << endl;
		
		}

	
};

main(){
	CombineFiles obj1;
	obj1.combine("FileOne.txt","FileTwo.txt");
	return 0;
}
