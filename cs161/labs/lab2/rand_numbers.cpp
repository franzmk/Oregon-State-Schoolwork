#include <iostream>
#include <ctime> /*included to allow time() to be used*/
#include <cstdlib> /*include to allow rand() and srand() to be used*/

using namespace std;

int main() {

	int num; // variable to hold our random integer
	srand(time(NULL)); // seeds random number generator. Do this just once

	num = rand()%6;
	
	cout << "Num: " << num << endl;

	if (num==0) {
	cout << "Bummer, I'm zero!!!" << endl;
	}
	
	else if ((num%2)==1) {

		cout << "I'm an odd number!" << endl;
	
		if (num==1) {
			cout << "I'm the number 1!" << endl;
 		}
		
		if (num==3) {
			cout << "I'm the number 3!" << endl;
		}
		
		if (num==5) {
			cout << "I'm the number 5!" << endl;
		}
	}
	
	else if ((num%2)==0) {
		cout << "I'm an even number!" <<endl;
	}
		if (num==2) {
			cout << "I'm the number 2!" << endl;
		}
		if (num==4) {
			cout << "I'm the number 4!" << endl;
		}
	
}
