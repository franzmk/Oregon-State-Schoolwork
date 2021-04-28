/*********************************************************************
 * ** Program Filename: room.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Driver file for room class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "room.h"

Room::Room() {
	event = NULL;
}

Room::~Room() {
	if(event != NULL) {
		delete event;
		event = NULL;
	}
}

Event * Room::get_event() {
	return event;
}

void Room::set_event(Event *event) {
	if(this->event != NULL) {
		delete this->event;
		this->event = event;
	}
	else this->event = event;
}

Room& Room::operator=(const Room &old) {
	if(this != &old) {
		//delete event;
		event = NULL;
		event = old.event;
	}
	return *this;
}
