/*
 * Program Filename: menu.h
 * Author: Max
 * Date: 4/29/19
 * Description: This is the header file for menu. It holds the class definition and all function prototypes.
 * Input: N/a
 * Output: N/a
 */

#include "pizza.h"

class Menu {
	private:
        	int num_pizzas;
        	Pizza* pizzas;
	public:
		/*********************************************************************
		 * ** Function: Menu()
		 * ** Description: This is the default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Object created
		 * ** Post-Conditions: Default variables
		 * *********************************************************************/ 
		Menu();
		/*********************************************************************
		 * ** Function: ~Menu()
		 * ** Description: This si the destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Objects pointers deleted
		 * ** Post-Conditions: Yes
		 * *********************************************************************/ 
		~Menu();
		/*********************************************************************
		 * ** Function: Assignment Operator Overload
		 * ** Description: Replaces = to deep copy object
		 * ** Parameters: const Menu&
		 * ** Pre-Conditions: Use = 
		 * ** Post-Conditions: Copied
		 * *********************************************************************/ 
		Menu& operator=(const Menu&);
		/*********************************************************************
		 * ** Function: Copy Constructor
		 * ** Description: Copies one object to another
		 * ** Parameters: const Menu&
		 * ** Pre-Conditions: Copy object
		 * ** Post-Conditions: Object copied
		 * *********************************************************************/ 
		Menu(const Menu&);
		/*********************************************************************
		 * ** Function: set_num_pizza()
		 * ** Description: Sets the number of pizzas read from menu
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set properly
		 * *********************************************************************/ 
		void set_num_pizza();
		/*********************************************************************
		 * ** Function: set_pizzas()
		 * ** Description: Sets pizzas object array
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set properly
		 * *********************************************************************/ 
		void set_pizzas();
		/*********************************************************************
		 * ** Function: get_num_pizza()
		 * ** Description: Gets number of pizzas
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Returns value
		 * *********************************************************************/ 
		int get_num_pizza();
		/*********************************************************************
		 * ** Function: get_pizzas()
		 * ** Description: Returns pizzas object array
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Returns pointer to object array
		 * *********************************************************************/ 
		Pizza * get_pizzas();
		/*********************************************************************
		 * ** Function: search_pizza_by_cost(int)
		 * ** Description: Searches pizza array with a max number, returns new menu
		 * ** Parameters: upper_bound
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: New menu
		 * *********************************************************************/ 
		Menu search_pizza_by_cost(int upper_bound);
		/*********************************************************************
		 * ** Function: search_pizza_by_ingredients_to_include(string*, int)
		 * ** Description: Searches pizzas array and records ones with certain ingredients
		 * ** Parameters: ingredients, num_ingredients
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: New menu
		 * *********************************************************************/ 
		Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
		/*********************************************************************
		 * ** Function: search_pizza_by_ingredients_to_exclude(string*, int)
		 * ** Description: Searches pizza array and records ones without certain ingredients
		 * ** Parameters: ingredients, num_ingredients
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: New menu
		 * *********************************************************************/ 
		Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
		/*********************************************************************
		 * ** Function: add_to_menu(Pizza)
		 * ** Description: Adds a pizza to the menu
		 * ** Parameters: pizza_to_add
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Pizza added to menu
		 * *********************************************************************/ 
		void add_to_menu(Pizza pizza_to_add);
		/*********************************************************************
		 * ** Function: remove_from_menu(int)
		 * ** Description: Removes a pizza from the menu at a certain index
		 * ** Parameters: index_of_pizza_on_menu
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Pizza removed from menu
		 * *********************************************************************/ 
		void remove_from_menu(int index_of_pizza_on_menu);
};

