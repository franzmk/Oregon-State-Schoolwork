#include <iostream>

using namespace std;

int c(int i) {
	if (i > 3)
		return 1;
	return i + c(++i);
}

int main() {
	cout << c(0) << endl;
}
