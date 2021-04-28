/*********************************************************************
 * ** Program Filename: restaurant.h
 * ** Author: Max
 * ** Date: 4/29/19
 * ** Description: Function prototypes and struct definition for restaurant.cpp
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "menu.h"

//structs
struct employee {
        int id;
        string password;
        string first_name;
	string last_name;
};

struct hours {
	string day;
        string open_hour;
        string close_hour;
};

class Restaurant {
	private:
        	Menu menu;
        	employee* employees;
	        hours* week;
		string* orders;
	        string name;
		string phone;
		string address;
		int num_employees;
		int num_orders;
	public:
		/*********************************************************************
		 * ** Function: Restaurant()
		 * ** Description: Default constructor, sets variables
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Object created
		 * ** Post-Conditions: Variables set
		 * *********************************************************************/ 
		Restaurant();
		/*********************************************************************
		 * ** Function: ~Restaurant()
		 * ** Description: Destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Object created
		 * ** Post-Conditions: Memory freed
		 * *********************************************************************/ 
		~Restaurant();
		/*********************************************************************
		 * ** Function: Copy Constructor
		 * ** Description: Copies one object to another when object is created
		 * ** Parameters: const Restaurant&
		 * ** Pre-Conditions: Object created with object as parameter
		 * ** Post-Conditions: Coped
		 * *********************************************************************/ 
		Restaurant (const Restaurant &);
		/*********************************************************************
		 * ** Function: Assignment operator overload
		 * ** Description: When = used, object copied
		 * ** Parameters: const Restaurant &
		 * ** Pre-Conditions: Objected created then set to another object
		 * ** Post-Conditions: Copied
		 * *********************************************************************/ 
		Restaurant& operator=(const Restaurant &);
		/*********************************************************************
		 * ** Function: load_data()
		 * ** Description: Loads data from all files for restaurant info, employees, and the orders
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set
		 * *********************************************************************/ 
		void load_data();
		/*********************************************************************
		 * ** Function: start()
		 * ** Description: Lets the user choose if they're a customer, employee, or want to quit
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: 
		 * *********************************************************************/ 
		void start();
		/*********************************************************************
		 * ** Function: credentials()
		 * ** Description: Gets user and password if user selected they were an employee
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Credentials collected
		 * *********************************************************************/ 
		void credentials();
		/*********************************************************************
		 * ** Function: check_id(string)
		 * ** Description: Checks if the id given is all numbers, if not calls credentials()
		 * ** Parameters: string id
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: retruns true or false
		 * *********************************************************************/ 
		bool check_id(string);
		/*********************************************************************
		 * ** Function: options_e()
		 * ** Description: Gives options for an employee who has signed in
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Option chosen
		 * *********************************************************************/ 
		void options_e();
		/*********************************************************************
		 * ** Function: choose_e()
		 * ** Description: Takes an input from the user on which option they want to choose
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called 
		 * ** Post-Conditions: Returns an int
		 * *********************************************************************/ 
		int choose_e();
		/*********************************************************************
		 * ** Function: options_c()
		 * ** Description: Lists options for the customer
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Option chosen
		 * *********************************************************************/ 
		void options_c();
		/*********************************************************************
		 * ** Function: choose_c()
		 * ** Description: Takes an input from the user on which optipon they want to choose
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Returns an int
		 * *********************************************************************/ 
		int choose_c();
		/*********************************************************************
		 * ** Function: login()
		 * ** Description: Takes an id and password and checks them against employees from employee.txt
		 * ** Parameters: string id, string password
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Logs employee in
		 * *********************************************************************/ 
		void login(string id, string password);
		/*********************************************************************
		 * ** Function: view_menu()
		 * ** Description: Prints menu to screen
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Printed
		 * *********************************************************************/ 
		void view_menu();
		/*********************************************************************
		 * ** Function: view_hours()
		 * ** Description: Prints hours to screen
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Printed
		 * *********************************************************************/ 
		void view_hours();
		/*********************************************************************
		 * ** Function: view_address()
		 * ** Description: Prints address to screen
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Printed
		 * *********************************************************************/ 
		void view_address();
		/*********************************************************************
		 * ** Function: view_phone()
		 * ** Description: Prints phone number to screen
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Printed
		 * *********************************************************************/ 
		void view_phone();
		/*********************************************************************
		 * ** Function: search_menu_by_price()
		 * ** Description: Searches the menu by a given price and sets the menu to that restriction
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: New menu made
		 * *********************************************************************/ 
		void search_menu_by_price();
		/*********************************************************************
		 * ** Function: search_by_ingredients()
		 * ** Description: Searches the menu by certain ingredients to include or exclude
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: New menu made
		 * *********************************************************************/ 
		void search_by_ingredients();
		/*********************************************************************
		 * ** Function: place_order()
		 * ** Description: Places an order based off of the current menu
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Order placed
		 * *********************************************************************/ 
		void place_order();
		/*********************************************************************
		 * ** Function: update_orders()
		 * ** Description: Updates the orders array after an order is placed
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Updates orders array
		 * *********************************************************************/ 
		void update_orders();
		/*********************************************************************
		 * ** Function: change_hours()
		 * ** Description: Changes the hours for a certain day of the week
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Hours changed
		 * *********************************************************************/ 
		void change_hours();
		/*********************************************************************
		 * ** Function: add_to_menu()
		 * ** Description: Adds a pizza to the menu
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Pizza added to the menu
		 * *********************************************************************/ 
		void add_to_menu();
		/*********************************************************************
		 * ** Function: remove_from_menu()
		 * ** Description: Removes a pizza from the menu
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Pizza removed from the menu
		 * *********************************************************************/ 
		void remove_from_menu();
		/*********************************************************************
		 * ** Function: view_orders()
		 * ** Description: Prints current orders to the screen
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Printed
		 * *********************************************************************/ 
		void view_orders();
		/*********************************************************************
		 * ** Function: remove_orders()
		 * ** Description: Removes a specified order from the orders array
		 * ** Parameters: N/a 
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Order removed
		 * *********************************************************************/ 
		void remove_orders();
};
