/*********************************************************************
 * ** Program Filename: wumpus.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Driver file for wumpus class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "wumpus.h"

Wumpus::Wumpus() {
	symbol = 'W';
	alive = true;
	x = 0;
	y = 0;
}

void Wumpus::percept() {
	cout << "You smell a terrible stench." << endl;
}

void Wumpus::encounter(int &type) {
	cout << endl;
	cout << "The Wumpus woke up and ate you!" << endl;
	cout << "Game over!" << endl;
	cout << endl;
	type = 1;
}

char Wumpus::get_symbol() {
	return symbol;
}

void Wumpus::set_symbol(char symbol) {
	this->symbol = symbol;
}

int Wumpus::get_x() {
	return x;
}

int Wumpus::get_y() {
	return y;
}

void Wumpus::set_x(int x) {
	this->x = x;
}

void Wumpus::set_y(int y) {
	this->y = y;
}

Wumpus::~Wumpus() {}
