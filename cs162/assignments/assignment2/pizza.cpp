/*********************************************************************
 * ** Program Filename: pizza.cpp
 * ** Author: Max
 * ** Date: 4/29/19
 * ** Description: Holds all of the function definitions for pizza.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "pizza.h"

Pizza::Pizza() {
	name = "";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;
}

Pizza::Pizza(const Pizza& old_obj) {
	name = old_obj.name;
	small_cost = old_obj.small_cost;
	medium_cost = old_obj.medium_cost;
	large_cost = old_obj.large_cost;

	num_ingredients = old_obj.num_ingredients;
	ingredients = new string[num_ingredients];
	for(int i = 0; i < num_ingredients; i++) {
		ingredients[i] = old_obj.ingredients[i];
	}
}

Pizza& Pizza::operator=(const Pizza& old_obj) {
	if(this != &old_obj) {
		delete [] ingredients;

		name = old_obj.name;
		small_cost = old_obj.small_cost;
		medium_cost = old_obj.medium_cost;
		large_cost = old_obj.large_cost;

		num_ingredients = old_obj.num_ingredients;
		ingredients = new string[num_ingredients];
		for(int i = 0; i < num_ingredients; i++) {
			ingredients[i] = old_obj.ingredients[i];
		}
	}
	return *this;
}

void Pizza::set_name(string name) {
	this->name = name;
}

string Pizza::get_name() {
	return name;
}

void Pizza::set_num_ingredients(int num_ingredients) {
	this->num_ingredients = num_ingredients;
}

int Pizza::get_num_ingredients() {
	return num_ingredients;
}

void Pizza::set_small_cost(int small_cost) {
	this->small_cost = small_cost;
}

int Pizza::get_small_cost() {
	return small_cost;
}

void Pizza::set_medium_cost(int medium_cost) {
	this->medium_cost = medium_cost;
}

int Pizza::get_medium_cost() {
	return medium_cost;
}

void Pizza::set_large_cost(int large_cost) {
	this->large_cost = large_cost;
}

int Pizza::get_large_cost() {
	return large_cost;
}

void Pizza::set_ingredients(string *ingredients) {
	this->ingredients = ingredients;
}

string * Pizza::get_ingredients() {
	return ingredients;
}

void Pizza::set_from_file(ifstream &f) {
	f >> name;
	f >> small_cost;
	f >> medium_cost;
	f >> large_cost;
	f >> num_ingredients;
	ingredients = new string[num_ingredients];
	for (int i = 0; i < num_ingredients; i++) {
		f >> ingredients[i];
	}
}

void Pizza::display_pizza() {
	cout << "Pizza: " << name << endl;
	cout << "Prices: " << "S $" << small_cost << " M $" << medium_cost << " L $" << large_cost << endl;
	cout << "Toppings: ";
	for(int i = 0; i < num_ingredients; i++) {
		cout << ingredients[i] << " ";
	}
	cout << endl;

	/*ofstream fout;
	do {
		fout.open("output.txt");
	} while(!fout.is_open());

	fout << "Pizza: " << name << endl;
	fout << "Prices: " << "S $" << small_cost << " M $" << medium_cost << " L $" << large_cost << endl;
	fout << "Toppings: ";
	for(int i = 0; i < num_ingredients; i++) {
		fout << ingredients[i] << " ";
	}
	fout << endl;
	cout << "File successfully created" << endl;*/
}

Pizza::~Pizza() {
	if(ingredients != NULL) {
		delete [] ingredients;
		ingredients = NULL;
	}
}
