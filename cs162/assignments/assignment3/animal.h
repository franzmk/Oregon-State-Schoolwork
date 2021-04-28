/*********************************************************************
 * ** Program Filename: animal.h
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Header file for the animal class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Animal {
	private:
		int age;
		string name;
		int cost;
		int sick_cost;
	public:
		/*********************************************************************
		 * ** Function: int get_age() const
		 * ** Description: returns the age of the current animal
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int get_age() const;
		/*********************************************************************
		 * ** Function: void set_age(int)
		 * ** Description: sets the age of the current animal
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: age set
		 * *********************************************************************/
		void set_age(int);
		/*********************************************************************
		 * ** Function: string get_name() const
		 * ** Description: returns the age of the current animal
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		string get_name() const;
		/*********************************************************************
		 * ** Function: void set_name(string)
		 * ** Description: sets the name of the current animal
		 * ** Parameters: string
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: name set
		 * *********************************************************************/
		void set_name(string);
		/*********************************************************************
		 * ** Function: int get_cost() const
		 * ** Description: returns the cost of the current animal
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int get_cost() const;
		/*********************************************************************
		 * ** Function: void set_cost(int)
		 * ** Description: sets the cost of the current animal
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: cost set
		 * *********************************************************************/
		void set_cost(int);
		/*********************************************************************
		 * ** Function: int get_sick_cost() const
		 * ** Description: returns the sick cost of the current animal
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: returned
		 * *********************************************************************/
		int get_sick_cost() const;
		/*********************************************************************
		 * ** Function: void set_sick_cot(int)
		 * ** Description: sets the sick cost of the current animal
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: sick cost set
		 * *********************************************************************/
		void set_sick_cost(int);
		/*********************************************************************
		 * ** Function: Animal()
		 * ** Description: default constructor for animal class
		 * ** Parameters: N/a
		 * ** Pre-Conditions: animal object declared
		 * ** Post-Conditions: animal object created
		 * *********************************************************************/
		Animal();
		/*********************************************************************
		 * ** Function: Animal(int, string, int, int)
		 * ** Description: 4-parameter constructor for animal class
		 * ** Parameters: int age, string name, int cost, int sick_cost
		 * ** Pre-Conditions: animal object declared
		 * ** Post-Conditions: animal object created
		 * *********************************************************************/
		Animal(int age, string name, int cost, int sick_cost);
		/*********************************************************************
		 * ** Function: Animal(const Animal&)
		 * ** Description: copy constructor for animal class
		 * ** Parameters: const Animal& 
		 * ** Pre-Conditions: animal object declared
		 * ** Post-Conditions: animal object created
		 * *********************************************************************/
		Animal(const Animal&);
		/*********************************************************************
		 * ** Function: Animal& operator=(const Animal&)
		 * ** Description: assignment operator overload
		 * ** Parameters: const Animal&
		 * ** Pre-Conditions: animal object assigned to other animal object
		 * ** Post-Conditions: copied correctly
		 * *********************************************************************/
		Animal& operator=(const Animal&);
		/*********************************************************************
		 * ** Function: Animal& operator++()
		 * ** Description: ++ operator overload
		 * ** Parameters: N/a
		 * ** Pre-Conditions: animal_object++
		 * ** Post-Conditions: correct
		 * *********************************************************************/
		Animal& operator++();
		/*********************************************************************
		 * ** Function: Animal& operator++(int)
		 * ** Description: ++ operator overload
		 * ** Parameters: int
		 * ** Pre-Conditions: animal_object++
		 * ** Post-Conditions: correct
		 * *********************************************************************/
		Animal& operator++(int);
		/*********************************************************************
		 * ** Function: ~Animal()
		 * ** Description: destructor for animal class
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope
		 * ** Post-Conditions: object deleted
		 * *********************************************************************/
		~Animal();
};

#endif
