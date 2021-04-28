/*
 * Program Filename: menu.cpp
 * Author: Max
 * Date: 4/29/19
 * Description: This is the code file for the menu. It holds all of the function definitions.
 * Input: N/a
 * Output: N/a
 */

#include "menu.h"

Menu::Menu() {
	num_pizzas = 0;
	pizzas = NULL;
}

Menu& Menu::operator=(const Menu &old_obj) {
	if(this != &old_obj) {
		delete [] pizzas;

		num_pizzas = old_obj.num_pizzas;
		
		pizzas = new Pizza[num_pizzas];
		for(int i = 0; i < num_pizzas; i++) {
			pizzas[i] = old_obj.pizzas[i];
		}
	}
	return *this;
}

Menu::Menu(const Menu &old_obj) {
	this->num_pizzas = old_obj.num_pizzas;

	this->pizzas = new Pizza[num_pizzas];
	for(int i = 0; i < num_pizzas; i++) {
		this->pizzas[i] = old_obj.pizzas[i];
	}
}

void Menu::set_num_pizza() {
	ifstream f;

	do {
		f.open("menu.txt");
	} while(!f.is_open());

	string temp;
	while(getline(f, temp)) {
		num_pizzas++;
	}
	num_pizzas -= 1;

	f.close();
}

int Menu::get_num_pizza() {
	return num_pizzas;
}

void Menu::set_pizzas() {
	pizzas = new Pizza[num_pizzas];

	ifstream f;
	do {
		f.open("menu.txt");
	} while(!f.is_open());
	for(int i = 0; i < num_pizzas; i++) {
		Pizza p;
		p.set_from_file(f);
		pizzas[i] = p;
	}
	f.close();
}

Menu Menu::search_pizza_by_cost(int upper_bound) {
	Menu temp = *this;
	
	for(int i = 0; i < temp.get_num_pizza(); i++) {
		if(temp.pizzas[i].get_small_cost() > upper_bound) {
			temp.pizzas[i].set_small_cost(-1);
		}
		if(temp.pizzas[i].get_medium_cost() > upper_bound) {
			temp.pizzas[i].set_medium_cost(-1);
		}
		if(temp.pizzas[i].get_large_cost() > upper_bound) {
			temp.pizzas[i].set_large_cost(-1);
		}
	}

	return temp;
}

Menu Menu::search_pizza_by_ingredients_to_include(string *ingredients, int num_ingredients) {
	Menu temp = *this;

	int num, index = 0;
	for(int i = 0; i < temp.get_num_pizza(); i++) {
		num = 0;
		string *ing = temp.pizzas[i].get_ingredients();
		for(int j = 0; j < num_ingredients; j++) {
			for(int k = 0; k < temp.pizzas[i].get_num_ingredients(); k++) {
				if(ing[k] == ingredients[j]) {
					num++;
					break;
				}
			}
		}
		if(num == num_ingredients) {
			temp.pizzas[index] = pizzas[i];
			index += 1;
		}
	}

	temp.num_pizzas = index;

	return temp;
}

Menu Menu::search_pizza_by_ingredients_to_exclude(string *ingredients, int num_ingredients) {
	Menu temp = *this;

	int num, index = 0;
	for(int i = 0; i < temp.get_num_pizza(); i++) {
		num = 0;
		string *ing = temp.pizzas[i].get_ingredients();
		for(int j = 0; j < num_ingredients; j++) {
			for(int k = 0; k < temp.pizzas[i].get_num_ingredients(); k++) {
				if(ing[k] == ingredients[j]) {
					num++;
					break;
				}
			}
		}
		if(num != num_ingredients) {
			temp.pizzas[index] = pizzas[i];
			index += 1;
		}
	}

	temp.num_pizzas = index;

	return temp;
}

void Menu::add_to_menu(Pizza pizza_to_add) {
	num_pizzas += 1;
	Pizza *temp = new Pizza[num_pizzas];
	for(int i = 0; i < num_pizzas; i++) {
		if(i != num_pizzas - 1) {
			temp[i] = pizzas[i];
		}
	}
	temp[num_pizzas - 1] = pizza_to_add;
	delete [] pizzas;
	pizzas = temp;
}

void Menu::remove_from_menu(int index_of_pizza_on_menu) {
	Pizza *temp = new Pizza[num_pizzas];
	for(int i = 0; i < num_pizzas; i++) {
		if(index_of_pizza_on_menu != i) {
			temp[i] = pizzas[i];
		}
	}
	for(int i = index_of_pizza_on_menu; i < num_pizzas - 1; i++) {
		temp[i] = temp[i + 1];
	}
	num_pizzas -= 1;
	delete [] pizzas;
	pizzas = temp;
}

Pizza * Menu::get_pizzas() {
	return pizzas;
}

Menu::~Menu() {
	if(pizzas != NULL) {
		delete [] pizzas;
		pizzas = NULL;
	}
}
