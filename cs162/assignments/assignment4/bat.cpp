/*********************************************************************
 * ** Program Filename: bat.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Driver file for bat class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "bat.h"

Bat::Bat() {
	symbol = 'B';
	x = 0;
	y = 0;
}

void Bat::percept() {
	cout << "You hear wings flapping." << endl;
}

void Bat::encounter(int &type) {
	cout << endl;
	cout << "It's a bat! The bat picked you up!" << endl;
	cout << "You're being moved to another room!" << endl;
	cout << endl;
	type = 4;
}

char Bat::get_symbol() {
	return symbol;
}

void Bat::set_symbol(char symbol) {
	this->symbol = symbol;
}

int Bat::get_x() {
	return x;
}

int Bat::get_y() {
	return y;
}

void Bat::set_x(int x) {
	this->x = x;
}

void Bat::set_y(int y) {
	this->y = y;
}

Bat::~Bat() {}
