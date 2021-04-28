#include <iostream>

using namespace std;

int main() {
	char *p = new char;

	cout << "p lives: " << &p << endl;
	cout << "contents of p: " << (void *)p << endl;
	cout << "contents of heap: " << *p << endl;
	*p = 'm';
	cout << "contents of heap: " << *p << endl;
	delete p;

	while(1) {
		char j = 'k';
		p = &j;
		cout << "contents of p: " << (void *)p << endl;
		cout << "contents of heap: " << *p << endl;
		*p = 'f';
		cout << "contents of heap: " << *p << endl;
		delete p;
	}

	return 0;
}
