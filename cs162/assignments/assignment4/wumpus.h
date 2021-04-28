/*********************************************************************
 * ** Program Filename: wumpus.h
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Header file for wumpus class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"

class Wumpus : public Event {
	private:
		char symbol;
		bool alive;
		int x;
		int y;
	public:
		/*********************************************************************
		 * ** Function: Wumpus()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Wumpus();
		/*********************************************************************
		 * ** Function: ~Wumpus()
		 * ** Description: default destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		~Wumpus();
		/*********************************************************************
		 * ** Function: void percept()
		 * ** Description: returns noise of wumpus
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
		 * ** Function: bool get_alive()
		 * ** Description: returns alive boolean
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		bool get_alive();
		/*********************************************************************
		 * ** Function: void set_alive(bool)
		 * ** Description: sets alive bool
		 * ** Parameters: bool
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_alive(bool);
		/*********************************************************************
		 * ** Function: int get_x()
		 * ** Description: returns x pos
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		int get_x();
		/*********************************************************************
		 * ** Function: int get_y()
		 * ** Description: returns y pos
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		int get_y();
		/*********************************************************************
		 * ** Function: void set_x(int)
		 * ** Description: sets x pos
		 * ** Parameters: int 
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_x(int);
		/*********************************************************************
		 * ** Function: void set_y(int)
		 * ** Description: sets y pos
		 * ** Parameters: int 
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_y(int);
};

#endif
