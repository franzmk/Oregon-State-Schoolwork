/******************************************************
 * ** Program: assignment1.cpp
 * ** Author: Mx Fanz
 * ** Date: 01/13/2019
 * ** Description: This program prints the values of shorts, ints, and longs and then calculates them by using bits and bytes to prove it.
 * ** Input: N/A
 * ** Output: Short min, short max, unsigned short, int min, int max, unsigned int, long min, long max, unsigned long
 * ******************************************************/ 


#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {

	//Preprocessor stuff
	//Preprocessor shorts
	cout << "Short min: " << SHRT_MIN << endl;
	cout << "Short max: " << SHRT_MAX << endl;
	cout << "Unsigned short max: " << USHRT_MAX << endl;

	//Preprocessor ints
	cout << "Int min: " << INT_MIN << endl;
	cout << "Int max: " << INT_MAX << endl;
	cout << "Unsigned int max: " << UINT_MAX << endl;
	
	//Preprocessor longs
	cout << "Long min: " << LONG_MIN << endl;
	cout << "Long max: " << LONG_MAX << endl;
	cout << "Unsigned long max: " << ULONG_MAX << endl;

	cout << "-----------------------------------" << endl;

	//Using sizeof and pow
	//Calculated shorts
	cout << "Short min: " << (-(pow(2, (sizeof(short)*8)-1))) << endl;
	cout << "Short max: " << pow(2, (sizeof(short)*8)-1)-1  << endl;
	cout << "Unsigned short: " << pow(2, (sizeof(short)*8))-1 << endl;

	//Calculated ints
	cout << "Int min: " << (int) (-(pow(2, (sizeof(int)*8)-1))) << endl;
	cout << "Int max: " << (int)  pow(2, (sizeof(int)*8)-1)-1 << endl;
	cout << "Unsigned int: " << (unsigned int) pow(2, (sizeof(int)*8))-1 << endl;

	//Calculated longs
	cout << "Long min: " << (long) (-(pow(2, (sizeof(long)*8)-1))) << endl;
	cout << "Long max: " << (long)  pow(2, (sizeof(long)*8)-1)-1 << endl;
	cout << "Unsigned long: " << (unsigned long) pow(2, (sizeof(long)*8))-1 << endl;

	return 0;
}

