#include <iostream>

using namespace std;

int main() {
	int x;
	cout << "Do you like vi as an editor? (y-1/n-0): ";
	cin >> x;

	if (x == 1) {
		cout << endl;
		cout << "You love vi!" << endl;
	}
	else {
		cout << endl;
		cout << "You hate vi!" << endl;
	}

	return 0;
}
