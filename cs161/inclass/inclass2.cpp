#include <iostream>

using namespace std;

int main() {

	int age = 24;

	cout << "Original: " << age << endl;
	cout << "Increment 1: " <<  age++ << endl;
	cout << "Increment 2: " <<  ++age << endl;
	cout << "End: " << age << endl;

	if (age <= 21) {
		cout << "You can have a beer!" << endl;
	}

	else {
		cout << "Wait a few more years!" << endl;
	}

	cout << "End: " << age << endl;

	return 0;
}	
