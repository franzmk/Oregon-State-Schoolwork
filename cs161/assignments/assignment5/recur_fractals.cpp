/*********************************************************************
 * ** Program Filename: recur_fractals.cpp
 * ** Author: 
 * ** Date: 3/3/19
 * ** Description: Prints a recursive fractal after user inputs number of total stars and spaces
 * ** Input: stars and spaces
 * ** Output: a recursive fractal design
 * *********************************************************************/

#include <iostream>
#include <typeinfo>

using namespace std;

/*********************************************************************
 * ** Function: pattern
 * ** Description: This function takes n and i as parameters and prints a recursive fratal based on those inputs
 * ** Parameters: int n and int i
 * ** Pre-Conditions: user inputs number of stars and spaces
 * ** Post-Conditions: prints recursive fractal
 * *********************************************************************/ 

void pattern(int n, int i) {
	if(n == 0) return;

	else pattern(n/2, i);

	for (int k = 0; k < i; k++) cout << "  ";

	for (int k = 0; k < n; k++) cout << "* ";

	cout << endl;

	pattern(n/2, i + n/2);
}

/*********************************************************************
 * ** Function: main
 * ** Description: starts program, fills n and i, calls pattern(n, i)
 * ** Parameters: N/a
 * ** Pre-Conditions: N/a
 * ** Post-Conditions: program works
 * *********************************************************************/ 

int main() {
	int n = 0, i = 0;

	do{
		cout << "Enter number of stars: ";
		cin >> n;
	}while((n%2 != 0 || n < 0) && (typeid(n) != typeid(int)));

	do{
		cout << "Enter number of spaces: ";
		cin >> i;
	}while(typeid(i) != typeid(int));

	pattern(n, i);

	return 0;
}
