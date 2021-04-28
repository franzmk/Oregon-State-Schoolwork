/*********************************************************************
 * ** Program Filename: animal.cpp
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Driver file for animal.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "animal.h"

Animal::Animal() {
	age = 0;
	name = "";
	cost = 0;
	sick_cost = 0;
}

Animal::Animal(int age, string name, int cost, int sick_cost) {
	this->age = age;
	this->name = name;
	this->cost = cost;
	this->sick_cost = sick_cost;
}

Animal::Animal(const Animal &old_obj) {
	age = old_obj.age;
	name = old_obj.name;
	cost = old_obj.cost;
	sick_cost = old_obj.sick_cost;
}

Animal& Animal::operator=(const Animal &old_obj) {
	if(this != &old_obj) {
		age = old_obj.age;
		name = old_obj.name;
		cost = old_obj.cost;
		sick_cost = old_obj.sick_cost;
	}
	return *this;
}

Animal& Animal::operator++() {
	++age;
	return *this;
}

Animal& Animal::operator++(int) {
	Animal old(*this);
	++(*this);
	return old;
}

int Animal::get_age() const{
	return age;
}

string Animal::get_name() const{
	return name;
}

int Animal::get_cost() const{
	return cost;
}

int Animal::get_sick_cost() const{
	return sick_cost;
}

void Animal::set_age(int age) {
	this->age = age;
}

void Animal::set_name(string name) {
	this->name = name;
}

void Animal::set_cost(int cost) {
	this->cost = cost;
}

void Animal::set_sick_cost(int sick_cost) {
	this->sick_cost = sick_cost;
}

Animal::~Animal() {

}
