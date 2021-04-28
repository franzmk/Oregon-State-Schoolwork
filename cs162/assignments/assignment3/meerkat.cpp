/*********************************************************************
 * ** Program Filename: meerkat.cpp
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Driver file for meerkat.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "meerkat.h"

Meerkat::Meerkat() : Animal(0, "Unnamed", 500, 250) {
}

Meerkat::Meerkat(string name) : Animal(0, name, 500, 250) {
}

Meerkat::Meerkat(const Meerkat &old_obj) : Animal(old_obj.get_age(), old_obj.get_name(), old_obj.get_cost(), old_obj.get_sick_cost()) {
}

Meerkat& Meerkat::operator=(const Meerkat &old_obj) {	
	set_age(old_obj.get_age());
	set_name(old_obj.get_name());
	set_cost(old_obj.get_cost());
	set_sick_cost(old_obj.get_sick_cost());

	return *this;
}

int Meerkat::revenue() {
	if(get_age() <= 5) {
		return 50;
	}
	else return 25;
}

Meerkat::~Meerkat() {
}
