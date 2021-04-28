#include <iostream>

using namespace std;

void fun(int &f) {
	cout << "Fun" << endl;
}

int fun(int *f) {
	cout << "Fun1" << endl;
	return 0;
}

int main() {
	int x = 10, y = 20;

	int &r = x; //address of r is now x
	int *p = 0; //p now points to the address '0'

	fun(r); //type is referance
	fun(p); //type is splat

	cout << "X lives: " << &x << endl;
	cout << "R lives: " << &r << endl;
	cout << "R contents: " << r << endl;

	r = y; //r is x so x is changed to y
	cout << "X contents: " << x << endl;
	
	p = &y; //p now points to y
	cout << "P lives: " << &p << endl; //different address than y, but points to y
	cout << "Contents of p: " << p << endl; //same address as y because p points to the contents of y
	cout << "Y lives: " << &y << endl; //address of y
	cout << "Contents of what p points to: " << *p << endl; //points to the contents of p which is y
	*p += 5; //changes y because p points to y
	cout << "Y: " << y << endl;
	cout << "Y: " << *p << endl;

	return 0;
}
