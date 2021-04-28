/*********************************************************************
 * ** Program Filename: restaurant.cpp
 * ** Author: Max
 * ** Date: 4/29/19
 * ** Description: File that holds all function definitions for restaurant.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "restaurant.h"

Restaurant::Restaurant() {
	menu.set_num_pizza();
	menu.set_pizzas();
	num_employees = 0;
	employees = NULL;
	week = NULL;
	orders = NULL;
	name = "";
	phone = "";
	address = "";
	num_orders = 0;
}

Restaurant::Restaurant(const Restaurant &old_obj) {
	name = old_obj.name;
	phone = old_obj.phone;
	address = old_obj.address;

	num_employees = old_obj.num_employees;
	employees = new employee[num_employees];
	for(int i = 0; i < num_employees; i++) {
		employees[i] = old_obj.employees[i];
	}

	week = new hours[7];
	for(int i = 0; i < 7; i++) {
		week[i] = old_obj.week[i];
	}
}

Restaurant& Restaurant::operator=(const Restaurant &old_obj) {
	if(this != &old_obj) {
		delete [] employees;
		delete [] week;

		name = old_obj.name;
		phone = old_obj.phone;
		address = old_obj.address;

		num_employees = old_obj.num_employees;
		employees = new employee[num_employees];
		for(int i = 0; i < num_employees; i++) {
			employees[i] = old_obj.employees[i];
		}

		week = new hours[7];
		for(int i = 0; i < 7; i++) {
			week[i] = old_obj.week[i];
		}
	}

	return *this;
}

void Restaurant::load_data() {
	ifstream f1;
	do {
		f1.open("restaurant_info.txt");
	} while(!f1.is_open());

	getline(f1, name);
	getline(f1, phone);
	getline(f1, address);

	week = new hours[7];
	for(int i = 0; i < 7; i++) {
		f1 >> week[i].day >> week[i].open_hour >> week[i].close_hour;
	}

	f1.close();

	ifstream f2;
	do {
		f2.open("employee.txt");
	} while(!f2.is_open());

	string temp;
	while(getline(f2, temp)) {
		num_employees++;
	}
	num_employees -= 1;

	f2.close();

	ifstream f3;
	do {
		f3.open("employee.txt");
	} while(!f3.is_open());

	employees = new employee[num_employees];
	for(int i = 0; i < num_employees; i++) {
		f3 >> employees[i].id >> employees[i].password >> employees[i].first_name >> employees[i].last_name;
	}

	f3.close();

	ifstream f4;
	do {
		f4.open("orders.txt");
	} while(!f4.is_open());
	
	int index = 0;
	orders = new string[40];
	while(!f4.eof()) {
		getline(f4, orders[index]);
		index += 1;
	}
	num_orders = index;

	f4.close();
}

void Restaurant::change_hours() {
	cout << endl;
	string change_day, open_change, close_change;
	int i = 0;
	cout << "Which day would you like to change the hours for? ";
	cin.clear();
	cin.ignore();
	getline(cin, change_day);
	for(i = 0; i < 7; i++) {
		if(change_day == week[i].day) {
			break;
		}
	}

	cout << "What should the opening time be? ";
	cin.clear();
	getline(cin, open_change);
	cout << "What should the closing time be? ";
	cin.clear();
	getline(cin, close_change);
	
	week[i].open_hour = open_change;
	week[i].close_hour = close_change;
	
	cout << "Updated schedule: " << endl;
	view_hours();

	ofstream f;
	do {
		f.open("restaurant_info.txt", ios::trunc);
	} while(!f.is_open());

	f << name << endl;
	f << address << endl;
	f << phone << endl;
	for(int i = 0; i < 7; i++) {
		f << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
	}
	f.close();
	cout << endl;
}

void Restaurant::view_orders() {
	cout << endl;
	for(int i = 0; i < num_orders; i++) {
		cout << orders[i] << endl;
	}
	cout << endl;
}

void Restaurant::remove_orders() {
	view_orders();

	int index = 0;
	cout << "Which order would you like to remove? ";
	cin >> index;

	index -= 1;

	num_orders--;
	for(int i = index; i < num_orders; i++) {
		orders[i] = orders[i+1];
	}

	view_orders();
}

void Restaurant::add_to_menu() {
	view_menu();

	string name;
	int small_cost, medium_cost, large_cost, num_ingredients;
	string *ing;
	Pizza p;
	cin.clear();
	cin.ignore();
	cout << "What is the name of the pizza you want to add? ";
	getline(cin, name);
	p.set_name(name);
	cout << "What is the small cost? ";
	cin >> small_cost;
	p.set_small_cost(small_cost);
	cout << "What is the medium cost? ";
	cin >> medium_cost;
	p.set_medium_cost(medium_cost);
	cout << "What is the large cost? ";
	cin >> large_cost;
	p.set_large_cost(large_cost);
	cout << "How many ingredients in your pizza? ";
	cin >> num_ingredients;
	p.set_num_ingredients(num_ingredients);

	ing = new string[num_ingredients];
	for(int i = 0; i < num_ingredients; i++) {
		cout << "Ingredient " << i + 1 << ": ";
		cin >> ing[i];
	}
	p.set_ingredients(ing);

	menu.add_to_menu(p);

	view_menu();
}

void Restaurant::remove_from_menu() {
	view_menu();

	int index = 0;
	cout << "Which item would you like to remove from the menu? ";
	cin >> index;

	index -= 1;

	menu.remove_from_menu(index);

	cout << "Updated menu: " << endl;
	view_menu();
}

void Restaurant::view_menu() {
	cout << endl;
	Pizza *temp = menu.get_pizzas();
	for (int i = 0; i < menu.get_num_pizza(); i++) {
		cout << i + 1 << ": " << temp[i].get_name() << " " << temp[i].get_small_cost() << " " << temp[i].get_medium_cost() << " " << temp[i].get_large_cost() << " ";
		for(int j = 0; j < temp[i].get_num_ingredients(); j++) {
			string *ing = temp[i].get_ingredients();
			cout << ing[j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Restaurant::view_hours() {
	cout << endl;
	for (int i = 0; i < 7; i++) {
		cout << week[i].day << " " << week[i].open_hour << " " << week[i].close_hour << endl;
	}
	cout << endl;
}

void Restaurant::view_address() {
	cout << endl;
	cout << address << endl;
	cout << endl;
}

void Restaurant::view_phone() {
	cout << endl;
	cout << phone << endl;
	cout << endl;
}

void Restaurant::search_menu_by_price() {
	Menu temp;
	temp = menu;
	int num = 0;
	cout << "What is your maximum budget? $";
	cin >> num;

	menu = temp.search_pizza_by_cost(num);

	place_order();
}

void Restaurant::search_by_ingredients() {
	Menu temp;
	temp = menu;

	int option;
	cout << "Would you like to search by ingredients to Include (1) or to Exclude (2)? ";
	cin >> option;

	int num_ing;
	string *ing;
	if(option == 1) {
		cout << "How many ingredients would you like to include? ";
		cin >> num_ing;
		ing = new string[num_ing];
		for(int i = 0; i < num_ing; i++) {
			cout << "Ingredient " << i + 1 << ": ";
			cin >> ing[i];
		}
		menu = temp.search_pizza_by_ingredients_to_include(ing, num_ing);

		place_order();
	}
	if(option == 2) {
		cout << "How many ingredients would you like to exclude? ";
		cin >> num_ing;
		ing = new string[num_ing];
		for(int i = 0; i < num_ing; i++) {
			cout << "Ingredient " << i + 1 << ": ";
			cin >> ing[i];
		}
		menu = temp.search_pizza_by_ingredients_to_exclude(ing, num_ing);

		place_order();
	}

	delete [] ing;
}

void Restaurant::update_orders() {	
	ifstream f4;
	do {
		f4.open("orders.txt");
	} while(!f4.is_open());
	
	delete [] orders;
	orders = new string[40];

	int index = 0;
	while(!f4.eof()) {
		getline(f4, orders[index]);
		index += 1;
	}
	num_orders = index;

	f4.close();
}

void Restaurant::place_order() {
	view_menu();

	string choice;
	cout << "Would you like to place an order off of this selection? (Y/N) ";
	cin >> choice;

	int index = 0;
	if(choice == "Y" || choice == "y") {
		Pizza *p = new Pizza[40];
		Pizza *temp = menu.get_pizzas();
		for(int i = 0; i < menu.get_num_pizza(); i++) {
			if(temp[i].get_small_cost() != -1) {
				p[index] = temp[i];
				cout << "(" << index + 1 << ")" << "Small " << temp[i].get_name() << " - $" << temp[i].get_small_cost() << endl;
				index += 1;
			}
			if(temp[i].get_medium_cost() != -1) {
				p[index] = temp[i];
				cout << "(" << index + 1 << ")" << "Medium " << temp[i].get_name() << " - $" << temp[i].get_medium_cost() << endl;
				index += 1;
			}
			if(temp[i].get_large_cost() != -1) {
				p[index] = temp[i];
				cout << "(" << index + 1 << ")" << "Large " << temp[i].get_name() << " - $" << temp[i].get_large_cost() << endl;
				index += 1;
			}
		}
		
		string *tem = new string[40];
		int index = 0;
		do {
			cout << endl;
			int choice;
			cout << "Please select an option from above. If you want to cancel, enter '0'. If you want to proceed to checkout, enter '111'" << endl;
			
			cout << "Your selection: ";
			cin >> choice;

			if(choice == 111) {
				break;
			}
			if(choice == 0) return;
			
			else {
				string size;
				cout << "Size: ";
				cin >> size;
			
				string num;
				cout << "How many " << p[choice - 1].get_name() << "? ";
				cin >> num;

				tem[index] = p[choice-1].get_name();
				tem[index+1] = size;
				tem[index+2] = num;

				index += 1;
			}
		} while(true);

		ofstream f;
		do {
			f.open("orders.txt" , ios::app);
		} while(!f.is_open());
		
		string name, cc, phone_num;
		cout << "Please provide the following information: " << endl;
		cout << "Customer name: ";
		cin.clear();
		cin.ignore();
		getline(cin, name);
		cout << "Credit card number: ";
		cin.clear();
		cin.ignore();
		getline(cin, cc);
		cout << "Phone number: ";
		cin.clear();
		cin.ignore();
		getline(cin, phone_num);

		num_orders += 1;

		f << num_orders << " " << name << " " << cc << " " << phone_num << " ";
		for(int i = 0; i < index; i++) {
			f << tem[i] << " " << tem[i+1] << " " << tem[i+2] << endl;
		}

		delete [] tem;
		delete [] p;

		cout << "Thank you! Your order number is: " << num_orders << endl;

		f.close();

		update_orders();
	}
}

int Restaurant::choose_e() {
	int choice = 10;
	
	cout << "1. Change hours" << endl;
	cout << "2. View orders" << endl;
	cout << "3. Remove order" << endl;
	cout << "4. Add Item to Menu" << endl;
	cout << "5. Remove Item from Menu" << endl;
	cout << "6. View Menu" << endl;
	cout << "7. View Hours" << endl;
	cout << "8. View Address" << endl;
	cout << "9. View Phone" << endl;
	cout << "10. Log Out" << endl;

	cout << "Selection: ";
	cin >> choice;

	return choice;
}

int Restaurant::choose_c() {
	int choice = 8;

	cout << "1. View Menu" << endl;
	cout << "2. Search by Cost" << endl;
	cout << "3. Search by Ingredients" << endl;
	cout << "4. Place Order" << endl;
	cout << "5. View Hours" << endl;
	cout << "6. View Address" << endl;
	cout << "7. View Phone" << endl;
	cout << "8. Log Out" << endl;
	
	cout << "Selection: ";
	cin >> choice;

	return choice;
}

void Restaurant::options_c() {
	int choice = choose_c();

	if(choice == 1) {
		view_menu();
		options_c();
	}
	if(choice == 2) {
		search_menu_by_price();
		options_c();
	}
	if(choice == 3) {
		search_by_ingredients();
		options_c();
	}
	if(choice == 4) {
		place_order();
		options_c();
	}
	if(choice == 5) {
		view_hours();
		options_c();
	}
	if(choice == 6) {
		view_address();
		options_c();
	}
	if(choice == 7) {
		view_phone();
		options_c();
	}
	if(choice == 8) {
		cin.clear();
		cin.ignore();
		start();
	}
}

void Restaurant::options_e() {
	int choice = choose_e();

	if(choice == 1) {
		change_hours();
		options_e();
	}
	if(choice == 2) {
		view_orders();
		options_e();
	}
	if(choice == 3) {
		remove_orders();
		options_e();
	}
	if(choice == 4) {
		add_to_menu();
		options_e();
	}
	if(choice == 5) {
		remove_from_menu();
		options_e();
	}
	if(choice == 6) {
		view_menu();
		options_e();
	}
	if(choice == 7) {
		view_hours();
		options_e();
	}
	if(choice == 8) {
		view_address();
		options_e();
	}
	if(choice == 9) {
		view_phone();
		options_e();
	}
	if(choice == 10) {
		cin.clear();
		cin.ignore();
		start();
	}
}

bool Restaurant::check_id(string login) {
	for(int i = 0; i < login.size(); i++) {
		if (!(login.at(i) >= '0' && login.at(i) <= '9')) {
			cout << "Login ID must be only integers!" << endl;
			return false;
		}
	}
	return true;
}

void Restaurant::login(string id, string password) {
	bool logged_in = false;
	int login_id = atoi(id.c_str());

	for(int i = 0; i < num_employees; i++) {
		if(login_id == employees[i].id && password == employees[i].password) {
			cout << "You have successfully logged in!" << endl;
			cout << "Welcome " << employees[i].first_name << " " << employees[i].last_name << "!" << endl;
			cout << endl;
			logged_in = true;
			break;
		}
	}

	if(logged_in == false) {
		cout << "Password or Login ID incorrect!" << endl;
		credentials();
	}
	if(logged_in == true) {
		options_e();
	}
}

void Restaurant::credentials() {
	string id = "", password = "";
	do {
		cout << "Please enter your ID Number: ";
		getline(cin, id);
		cout << "Please enter your password: ";
		getline(cin, password);
		cout << endl;
	} while(!check_id(id));

	login(id, password);
}

void Restaurant::start() {
	cout << endl;
	cout << "Welcome to " << name << "!" << endl;
	string choice = "";
	cout << "Are you a customer (C) or employee (E) or would you like to quit (Q)? ";
	getline(cin, choice);
	cout << endl;
	
	if (choice == "C" || choice == "c") {
		options_c();
	}
	else if (choice == "E" || choice == "e") {
		credentials();
	}
	else return;
}

Restaurant::~Restaurant() {
	if(employees != NULL) {
		delete [] employees;
		employees = NULL;
	}
	if(week != NULL) {
		delete [] week;
		week = NULL;
	}
	if(orders != NULL) {
		delete [] orders;
		orders = NULL;
	}
}
