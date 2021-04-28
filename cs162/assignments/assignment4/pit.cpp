/*********************************************************************
 * ** Program Filename: pit.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Driver file for pit class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "pit.h"

Pit::Pit() {
	symbol = 'P';
	x = 0;
	y = 0;
}

void Pit::percept() {
	cout << "You feel a breeze." << endl;
}

void Pit::encounter(int &type) {
	cout << endl;
	cout << "You've entered a room with a pit and fallen to your death!" << endl;
	cout << "Game over!" << endl;
	cout << endl;
	type = 2;
}

char Pit::get_symbol() {
	return symbol;
}

void Pit::set_symbol(char symbol) {
	this->symbol = symbol;
}

int Pit::get_x() {
	return x;
}

int Pit::get_y() {
	return y;
}

void Pit::set_x(int x) {
	this->x = x;
}

void Pit::set_y(int y) {
	this->y = y;
}

Pit::~Pit() {}
