#include <iostream>
using namespace std;

void Hanoi(int num, char source, char destination, char intermediate){
	if (num > 0) {
	Hanoi(num-1, source, intermediate, destination);
	cout << "Move disc " << num << " from " << source << " to " << destination << endl;
	Hanoi(num-1, intermediate, destination, source);
	}
}

main(){
	int n;
	cout << "Enter number of discs: ";
	cin >> n;
	Hanoi(n, 'A', 'C', 'B');
	return 0;
}

