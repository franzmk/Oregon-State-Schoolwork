/*********************************************************************
 * ** Program Filename: meerkat.h
 * ** Author: MAx
 * ** Date: 5/12/19
 * ** Description: Header file for meerkat class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef MEERKAT_H
#define MEERKAT_H

#include "animal.h"

class Meerkat : public Animal {
	private:

	public:
		/*********************************************************************
		 * ** Function: Meerkat()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Meerkat();
		/*********************************************************************
		 * ** Function: Meerkat(string name)
		 * ** Description: 1-parameter constructor
		 * ** Parameters: string name
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Meerkat(string name);
		/*********************************************************************
		 * ** Function: Meerkat(const Meerkat&)
		 * ** Description: copy constructor
		 * ** Parameters: const Meerkat&
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Meerkat(const Meerkat&);
		/*********************************************************************
		 * ** Function: Meerkat& operator=(const Meerkat&)
		 * ** Description: assignment operator overload
		 * ** Parameters: const Meerkat&
		 * ** Pre-Conditions: object assigned to other object
		 * ** Post-Conditions: correct
		 * *********************************************************************/
		Meerkat& operator=(const Meerkat&);
		/*********************************************************************
		 * ** Function: ~Meerkat()
		 * ** Description: destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope
		 * ** Post-Conditions: correct
		 * *********************************************************************/
		~Meerkat();
		/*********************************************************************
		 * ** Function: revenue()
		 * ** Description: returns revenue for meerkat
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int revenue();
};

#endif
