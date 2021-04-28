/*********************************************************************
 * ** Program Filename: event.h
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Header file for abstract event class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Event {
	public:
		/*********************************************************************
		 * ** Function: virtual void percept() = 0
		 * ** Description: abstract version of percept function
		 * ** Parameters: N/a
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual void percept() = 0;
		/*********************************************************************
		 * ** Function: virtual void encounter() = 0
		 * ** Description: abstract version of encounter function
		 * ** Parameters: int&
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual void encounter(int&) = 0;
		/*********************************************************************
		 * ** Function: virtual ~Event() = default
		 * ** Description: abstract version of destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual ~Event() = default;
		/*********************************************************************
		 * ** Function: virtual char get_symbol() = 0
		 * ** Description: abstract version of get_symbol function
		 * ** Parameters: N/a
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual char get_symbol() = 0;
		/*********************************************************************
		 * ** Function: virtual void set_symbol(char) = 0
		 * ** Description: abstract version of set_symbol function
		 * ** Parameters: char
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual void set_symbol(char) = 0;
		/*********************************************************************
		 * ** Function: virtual int get_x() = 0
		 * ** Description: abstract version of get_x function
		 * ** Parameters: N/a
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual int get_x() = 0;
		/*********************************************************************
		 * ** Function: virtual int get_y() = 0
		 * ** Description: abstract version of get_y function
		 * ** Parameters: N/a
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual int get_y() = 0;
		/*********************************************************************
		 * ** Function: virtual void set_x(int) = 0
		 * ** Description: abstract version of set_x function
		 * ** Parameters: int
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual void set_x(int) = 0;
		/*********************************************************************
		 * ** Function: virtual void set_y(int) = 0
		 * ** Description: abstract version of set_y function
		 * ** Parameters: int
		 * ** Pre-Conditions: defined in classes
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		virtual void set_y(int) = 0;
};

#endif
