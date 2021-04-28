#include <iostream>

using namespace std;

int fib_recurs(int n) {
	int f0 = 0, f1 = 1, f = 0;
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	else {
		//for (int i = 0; i <= n; i++) {
			return fib_recurs(n-1) + fib_recurs(n-2);
		//}
	}
	//return f;
}

int main() {
	int n = 0;
	cout << "Enter a number: ";
	cin >> n;
	cout << endl;
	cout << "Fibonocci: " << fib_recurs(n) << endl;
}
