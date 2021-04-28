/*********************************************************************
 * ** Program Filename: monkey.cpp
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Driver file for monkey.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "monkey.h"

Monkey::Monkey() : Animal(0, "Unnamed", 15000, 7500) {
}

Monkey::Monkey(string name) : Animal(0, name, 15000, 7500) { 
}

Monkey::Monkey(const Monkey &old_obj) : Animal(old_obj.get_age(), old_obj.get_name(), old_obj.get_cost(), old_obj.get_sick_cost()) {
}

Monkey& Monkey::operator=(const Monkey &old_obj) {	
	set_age(old_obj.get_age());
	set_name(old_obj.get_name());
	set_cost(old_obj.get_cost());
	set_sick_cost(old_obj.get_sick_cost());

	return *this;
}

int Monkey::revenue() {
	if(get_age() <= 5) {
		return 3000;
	}
	else return 1500;
}

int Monkey::bonus_revenue() {
	srand(time(NULL));

	int x = ((rand() % 401) + 300);
	if(get_age() <= 5) {
		return x * 2;
	}
	else return x;
}

Monkey::~Monkey() {}
