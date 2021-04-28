/*********************************************************************
 * ** Program Filename: bat.h
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Header file for bat class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef BAT_H
#define BAT_H

#include "event.h"

class Bat : public Event {
	private:
		char symbol;
		int x;
		int y;
	public:
		/*********************************************************************
		 * ** Function: Bat()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Bat();
		/*********************************************************************
		 * ** Function: ~Bat()
		 * ** Description: default destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		~Bat();
		/*********************************************************************
		 * ** Function: percept()
		 * ** Description: prints bat sound when player near
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void percept();
		/*********************************************************************
		 * ** Function: encounter(int&)
		 * ** Description: when player encounters this event, action occurs
		 * ** Parameters: int&
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void encounter(int&);
		/*********************************************************************
		 * ** Function: get_symbol()
		 * ** Description: returns event symbol
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		char get_symbol();
		/*********************************************************************
		 * ** Function: set_symbol(char)
		 * ** Description: sets symbol of event
		 * ** Parameters: char
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_symbol(char);
		/*********************************************************************
		 * ** Function: get_x()
		 * ** Description: gets x pos of event
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		int get_x();
		/*********************************************************************
		 * ** Function: get_y()
		 * ** Description: gets y pos of event
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		int get_y();
		/*********************************************************************
		 * ** Function: set_x(int)
		 * ** Description: sets x pos of event
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_x(int);
		/*********************************************************************
		 * ** Function: set_y(int)
		 * ** Description: sets y pos of event
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_y(int);
};

#endif
