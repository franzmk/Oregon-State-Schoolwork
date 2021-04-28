/*********************************************************************
 * ** Program Filename: pit.h
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Header file for pit class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef PIT_H
#define PIT_H

#include "event.h"

class Pit : public Event {
	private:
		char symbol;
		int x;
		int y;
	public:
		/*********************************************************************
		 * ** Function: Pit()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Pit();
		/*********************************************************************
		 * ** Function: ~Pit()
		 * ** Description: default destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		~Pit();
		/*********************************************************************
		 * ** Function: void percept()
		 * ** Description: returns noise of pit
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void percept();
		/*********************************************************************
		 * ** Function: void encounter(int&)
		 * ** Description: action occurs if called
		 * ** Parameters: int&
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void encounter(int&);
		/*********************************************************************
		 * ** Function: char get_symbol()
		 * ** Description: returns symbol of event
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		char get_symbol();
		/*********************************************************************
		 * ** Function: void set_symbol(char)
		 * ** Description: sets symbol of event
		 * ** Parameters: char
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_symbol(char);
		/*********************************************************************
		 * ** Function: int get_x()
		 * ** Description: returns x pos of event
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		int get_x();
		/*********************************************************************
		 * ** Function: int get_y()
		 * ** Description: returns y pos of event
		 * ** Parameters: N/a 
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		int get_y();
		/*********************************************************************
		 * ** Function: void set_x(int)
		 * ** Description: sets x pos of event
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_x(int);
		/*********************************************************************
		 * ** Function: void set_y(int)
		 * ** Description: sets y pos of event
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_y(int);
};

#endif
