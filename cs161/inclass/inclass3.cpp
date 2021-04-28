#include <iostream>

using namespace std;

int main() {

	int x;

	cout << "Number: ";
	cin >> x;

	switch (x) {

		case 0:
			cout << "Zero" << endl;
			break;
		case 1:
			cout << "One" << endl;
			break;
		default:
			cout << "Error" << endl;
	}

	return 0;
}
