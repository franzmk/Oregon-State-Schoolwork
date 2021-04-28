#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

	int input, i;
	bool check = true;
	char stop;

	while (check == true) {

		bool prime = true;

		cout << "Enter a positive whole number: ";
		cin >> input;
		
		if (input < 0) {
			cout << endl;
			cout << "Enter a whole positive number ONLY: " << endl;
			cout << endl;
		}
		
		for (i = 2; i <= input / 2; i++) {
			if (input % i == 0) {
				prime = false;
				break;
			}
		}
		
		if (prime == true ) {	
			cout << endl;
			cout << input << " is a prime number!" << endl;
		}

		else {
			cout << endl;
			cout << input << " is not a prime number!" << endl;
		}

		cout << endl;
		cout << "Want to check another number? (y/n): ";
		cin >> stop;

		if (stop == 'y') {
			cout << endl;
			check = true;
		}
		else {
			check = false;
		}
	}

	return 0;
}
