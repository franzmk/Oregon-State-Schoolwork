/*********************************************************************
 * ** Program Filename: pizza.h
 * ** Author: Max
 * ** Date: 4/29/19
 * ** Description: Holds all of the function prototypes for pizza.cpp
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Pizza {
	private:
        	string name;
        	int small_cost;
	        int medium_cost;
	        int large_cost;
		int num_ingredients;
		string *ingredients;
	public:
		/*********************************************************************
		 * ** Function: Pizza()
		 * ** Description: Constructor for pizza object, sets default variables
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Object created
		 * ** Post-Conditions: Yes
		 * *********************************************************************/
		Pizza();
		/*********************************************************************
		 * ** Function: ~Pizza()
		 * ** Description: Destructor for pizza object, deletes pointers
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Object created
		 * ** Post-Conditions: Object deleted
		 * *********************************************************************/
		~Pizza();
		/*********************************************************************
		 * ** Function: Pizza
		 * ** Description: Copy constructor
		 * ** Parameters: const Pizza&
		 * ** Pre-Conditions: Object created with object in parameter
		 * ** Post-Conditions: Object copied
		 * *********************************************************************/
		Pizza(const Pizza&);
		/*********************************************************************
		 * ** Function: Assignment operator overload
		 * ** Description: Wehn = used, copies one object to another
		 * ** Parameters: const Pizza&
		 * ** Pre-Conditions: = used
		 * ** Post-Conditions: Object copied
		 * *********************************************************************/
		Pizza& operator=(const Pizza&);
		/*********************************************************************
		 * ** Function: set_name(string) and get_name()
		 * ** Description: Sets name fo pizza and gets name of pizza
		 * ** Parameters: string name
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set or given
		 * *********************************************************************/
		void set_name(string name);
		string get_name();
		/*********************************************************************
		 * ** Function: set_small_cost(int) and get_small_cost()
		 * ** Description: Sets and gets small cost of pizza
		 * ** Parameters: int small_cost
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set or given
		 * *********************************************************************/
		void set_small_cost(int small_cost);
		int get_small_cost();
		/*********************************************************************
		 * ** Function: set_medium_cost(int) and get_medium_cost()
		 * ** Description: Sets and gets medium cost of pizza
		 * ** Parameters: int medium_cost
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set or given
		 * *********************************************************************/
		void set_medium_cost(int medium_cost);
		int get_medium_cost();
		/*********************************************************************
		 * ** Function: set_large_cost(int) and get_large_cost()
		 * ** Description: Sets and gets large cost of pizza
		 * ** Parameters: int large_cost
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set or given
		 * *********************************************************************/
		void set_large_cost(int large_cost);
		int get_large_cost();
		/*********************************************************************
		 * ** Function: set_num_ingredients(int) and get_num_ingredients()
		 * ** Description: Sets and gets num_ingredients of a pizza
		 * ** Parameters: int num_ingredients
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set or given
		 * *********************************************************************/
		void set_num_ingredients(int num_ingredients);
		int get_num_ingredients();
		/*********************************************************************
		 * ** Function: set_ingredients(string*) and get_ingredients
		 * ** Description: Sets and gets ingredients array for a pizza
		 * ** Parameters: string *ingredients
		 * ** Pre-Conditions: Called 
		 * ** Post-Conditions: Set or given
		 * *********************************************************************/
		void set_ingredients(string *ingredients);
		string * get_ingredients();
		/*********************************************************************
		 * ** Function: set_from_file(ifstream)
		 * ** Description: Sets a pizza object from menu.txt
		 * ** Parameters: ifstream &f
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Set 
		 * *********************************************************************/
		void set_from_file(ifstream &);
		/*********************************************************************
		 * ** Function: display_pizza()
		 * ** Description: Prints pizza info to screen
		 * ** Parameters: N/a
		 * ** Pre-Conditions: Called
		 * ** Post-Conditions: Prints
		 * *********************************************************************/
		void display_pizza();
};
