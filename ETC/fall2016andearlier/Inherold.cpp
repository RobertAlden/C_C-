#include <iostream>
#include <string>
using namespace std;

class Person {
	string LName;
	string FName;
	int phone;
	
	public:
	void print(){
		cout << LName << ", " << FName << ", " << phone << ";" << endl;
	}
	void setLName(string a){
		LName = a;
	}
	void setFName(string a){
		FName = a;
	}
	void setPhone(int a){
		phone = a;
	}
	string getLName(){
		return LName;
	}
	string getFName(){
		return FName;
	}
	int getPhone(){
		return phone;
	}
	
};
class Student :public Person {
	string Major;
	
	public:
	void print(){
		Person::print();
		cout << getMajor() << ";" << endl;
	}
	void setMajor(string a){
		Major = a;
	}
	string getMajor(){
		return Major;
	}
};
main(){
	Student A;
	A.setLName("Alden");
	A.setFName("Robert");
	A.setPhone(3556789);
	A.setMajor("CS");
	A.print();
	return 0;
}