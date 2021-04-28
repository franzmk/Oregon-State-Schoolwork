/*********************************************************************
 * ** Program Filename: seaotter.cpp
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Driver file for seaotter.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "seaotter.h"

Seaotter::Seaotter() : Animal(0, "Unnamed", 5000, 2500) {
}

Seaotter::Seaotter(string name) : Animal(0, name, 5000, 2500) { 
}

Seaotter::Seaotter(const Seaotter &old_obj) : Animal(old_obj.get_age(), old_obj.get_name(), old_obj.get_cost(), old_obj.get_sick_cost()) {
}

Seaotter& Seaotter::operator=(const Seaotter &old_obj) {	
	set_age(old_obj.get_age());
	set_name(old_obj.get_name());
	set_cost(old_obj.get_cost());
	set_sick_cost(old_obj.get_sick_cost());

	return *this;
}

int Seaotter::revenue() {
	if(get_age() <= 5) {
		return 500;
	}
	else return 250;
}

Seaotter::~Seaotter() {
}
