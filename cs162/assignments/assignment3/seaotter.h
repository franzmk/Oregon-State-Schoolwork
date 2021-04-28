/*********************************************************************
 * ** Program Filename: seaotter.h
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Header file for seaotter class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef SEAOTTER_H
#define SEAOTTER_H

#include "animal.h"

class Seaotter : public Animal {
	private:

	public:
		/*********************************************************************
		 * ** Function: Seaotter()
		 * ** Description: default constructor 
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Seaotter();
		/*********************************************************************
		 * ** Function: Seaotter(string name)
		 * ** Description: 1-parameter constructor
		 * ** Parameters: string name
		 * ** Pre-Conditions: object declared 
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Seaotter(string name);
		/*********************************************************************
		 * ** Function: Seaotter (const Seaotter&)
		 * ** Description: copy constructor
		 * ** Parameters: const Seaotter&
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Seaotter (const Seaotter&);
		/*********************************************************************
		 * ** Function: Seaotter& operator=(const Seaotter&)
		 * ** Description: assignment operator overload
		 * ** Parameters: const Seaotter&
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Seaotter& operator=(const Seaotter&);
		/*********************************************************************
		 * ** Function: ~Seaotter()
		 * ** Description: destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope
		 * ** Post-Conditions: correct deletion
		 * *********************************************************************/
		~Seaotter();
		/*********************************************************************
		 * ** Function: revenue()
		 * ** Description: returns revenue for seaotter
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int revenue();
};

#endif
