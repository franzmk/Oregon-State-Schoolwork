/*********************************************************************
 * ** Program Filename: prog.cpp
 * ** Author: Max Franz
 * ** Date: 6/9/19
 * ** Description: This is the main file for my linked list class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "list.h"

/*********************************************************************
 * ** Function: main()
 * ** Description: This is the main function for the linked list assignment. It's above 20 lines
 * in order to test all of the functionality, it can be muich shorter.
 * ** Parameters: N/a
 * ** Pre-Conditions: program runs
 * ** Post-Conditions: program ran
 * *********************************************************************/

int main() {
	char again;
	do {
		Linked_List *list = new Linked_List();

		int val = 0;
		char cont;
		do {
			cout << "Number: ";
			cin >> val;
			list->push_back(val);

			cout << "Do you want to enter another number? (y/n): ";
			cin >> cont;

			cout << endl;
			cin.clear();
		} while(cont == 'y');

		cout << "Number: ";
		cin >> val;
		list->push_front(val);

		cout << endl;

		cout << "Number: ";
		cin >> val;
		list->push_front(val);

		cout << endl;
		cin.clear();

		cout << "Number to insert: ";
		cin >> val;
		list->insert(val, 3);

		cout << endl;
		cout << "Length: " << list->get_length() << endl;
		cout << endl;

		char a_or_d;
		cout << "Do you want to sort in ascending or descending order? (a/d): ";
		cin >> a_or_d;

		cout << endl;

		if(a_or_d == 'a') list->sort_ascending();
		else if(a_or_d == 'd') list->sort_descending();

		list->print();

		delete list;

		cout << endl;
		cout << "Do you want to do this again? (y/n): ";
		cin >> again;

	} while(again == 'y');

	return 0;
}
