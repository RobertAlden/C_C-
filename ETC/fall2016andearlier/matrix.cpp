#include <iostream>
using namespace std;

class matrix{
	private:
	double a1,a2,a3,a4;
	public:
	void setValues(double,double,double,double);
	void getValues();
	matrix addMatrix(matrix);
	matrix subMatrix(matrix);
	matrix multMatrix(matrix);
};

main(){
	matrix obj1, obj2, obj3;
	cout << "matrix 1:" << endl;
	obj1.setValues(1,2,3,4);
	obj1.getValues();
	cout << "matrix 2:" << endl;
	obj2.setValues(5,6,7,8);
	obj2.getValues();
	cout << "Adding matrices: "<< endl;
	obj3 = obj1.addMatrix(obj2);
	obj3.getValues();
	cout << "Subtracting matrices: "<< endl;
	obj3 = obj1.subMatrix(obj2);
	obj3.getValues();
	cout << "Multiplying matrices: "<< endl;
	obj3 = obj1.multMatrix(obj2);
	obj3.getValues();
	return 0;
};

void matrix::setValues(double a, double b, double c, double d){
	a1 = a;
	a2 = b;
	a3 = c;
	a4 = d;
}

void matrix::getValues(){
	cout << "( " << a1 << " " << a2 << " )" << endl;
	cout << "( " << a3 << " " << a4 << " )" << endl;
}

matrix matrix::addMatrix(matrix other){
	matrix result;
	result.a1 = a1 + other.a1;
	result.a2 = a2 + other.a2;
	result.a3 = a3 + other.a3;
	result.a4 = a4 + other.a4;
	return result;
}
matrix matrix::subMatrix(matrix other){
	matrix result;
	result.a1 = a1 - other.a1;
	result.a2 = a2 - other.a2;
	result.a3 = a3 - other.a3;
	result.a4 = a4 - other.a4;
	return result;
}
matrix matrix::multMatrix(matrix other){
	matrix result;
	result.a1 = a1 * other.a1;
	result.a2 = a2 * other.a2;
	result.a3 = a3 * other.a3;
	result.a4 = a4 * other.a4;
	return result;
}
