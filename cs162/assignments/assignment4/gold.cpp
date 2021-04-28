/*********************************************************************
 * ** Program Filename: gold.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Driver file for gold class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "gold.h"

Gold::Gold() {
	symbol = 'G';
	x = 0;
	y = 0;
}

void Gold::percept() {
	cout << "You see a glimmer nearby." << endl;
}

void Gold::encounter(int &type) {
	cout << endl;
	cout << "You found the gold!" << endl;
	cout << "Quickly! Make your way back to the exit if you want to win!" << endl;
	cout << endl;
	type = 3;
}

char Gold::get_symbol() {
	return symbol;
}

void Gold::set_symbol(char symbol) {
	this->symbol = symbol;
}

int Gold::get_x() {
	return x;
}

int Gold::get_y() {
	return y;
}

void Gold::set_x(int x) {
	this->x = x;
}

void Gold::set_y(int y) {
	this->y = y;
}

Gold::~Gold() {}
