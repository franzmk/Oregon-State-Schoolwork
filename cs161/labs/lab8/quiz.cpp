#include <iostream>

using namespace std;

int main() {
	int *p1 = new int;
	int *p2 = new int;

	p1 = p2;

	*p1 = 6;
	*p2 = 7;

	if(p1 == p2) {
		cout << "p1: " << p1 << endl;
		cout << "p2: " << p2 << endl;
		cout << "*p1: " << *p1 << endl;
		cout << "*p2: " << *p2 << endl;
	}
	else {
		cout << "p1: " << p1 << endl;
		cout << "p2: " << p2 << endl;
		cout << "*p1: " << *p1 << endl;
		cout << "*p2: " << *p2 << endl;
	}

	return 0;
}
