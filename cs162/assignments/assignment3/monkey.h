/*********************************************************************
 * ** Program Filename: monkey.h
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Header file for monkey class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef MONKEY_H
#define MONKEY_H

#include "animal.h"

class Monkey : public Animal {
	private:

	public:
		/*********************************************************************
		 * ** Function: Monkey()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Monkey();
		/*********************************************************************
		 * ** Function: Monkey(string name)
		 * ** Description: 1-parameter constructor
		 * ** Parameters: string name
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Monkey(string name);
		/*********************************************************************
		 * ** Function: Monkey (const Monkey&)
		 * ** Description: copy constructor
		 * ** Parameters: const Monkey&
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Monkey (const Monkey&);
		/*********************************************************************
		 * ** Function: Monkey& operator=(const Monkey&)
		 * ** Description: assignment operator overload
		 * ** Parameters: const Monkey&
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Monkey& operator=(const Monkey&);
		/*********************************************************************
		 * ** Function: ~Monkey()
		 * ** Description: destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope
		 * ** Post-Conditions: correct
		 * *********************************************************************/
		~Monkey();
		/*********************************************************************
		 * ** Function: revenue()
		 * ** Description: returns revenue for monkey
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int revenue();
		/*********************************************************************
		 * ** Function: bonus_revenue()
		 * ** Description: returns extra revenue for monkey
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int bonus_revenue();
};

#endif
