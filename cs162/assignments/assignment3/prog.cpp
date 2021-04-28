/*********************************************************************
 * ** Program Filename: zoo.cpp
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Holds main function, runs program
 * ** Input: N/a
 * ** Output: Program runs
 * *********************************************************************/

#include "zoo.h"

int main() {
	Zoo z;
	
	z.start();

	do {
		z.age();

		z.special_event();

		z.weekly_revenue();

		z.buy_animals();

		z.buy_feed();

		z.display();
	} while(z.week_check());

	return 0;
}	
