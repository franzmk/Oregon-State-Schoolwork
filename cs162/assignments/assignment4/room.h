/*********************************************************************
 * ** Program Filename: room.h
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Header file for room class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "event.h"

using namespace std;

class Room {
	private:
		Event *event;
	public:
		/*********************************************************************
		 * ** Function: Room()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Room();
		/*********************************************************************
		 * ** Function: ~Room()
		 * ** Description: default destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		~Room();
		/*********************************************************************
		 * ** Function: bool get_full()
		 * ** Description: returns if room is full or not
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		bool get_full();
		/*********************************************************************
		 * ** Function:void set_full()
		 * ** Description: sets if room is full or not
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_full();
		/*********************************************************************
		 * ** Function: Event * get_event()
		 * ** Description: gets event of a room
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Event * get_event();
		/*********************************************************************
		 * ** Function: void set_event(Event*)
		 * ** Description: sets event in a room
		 * ** Parameters: Event*
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void set_event(Event*);
		/*********************************************************************
		 * ** Function: Room& operator=(const Room&)
		 * ** Description: assignment operator overload
		 * ** Parameters: const Room&
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Room& operator=(const Room&);
};

#endif
