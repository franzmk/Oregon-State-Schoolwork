/*********************************************************************
 * ** Program Filename: zoo.h
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Header file for zoo class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"
#include "monkey.h"
#include "meerkat.h"
#include "seaotter.h"

class Zoo {
	private:
		int bank;
		string zoo_name;

		Monkey *monk;
		int num_monkeys;

		Meerkat *kats;
		int num_meerkats;

		Seaotter *otts;
		int num_seaotters;

		int num_animals;
		int num_adults;
		int num_babies;

		int week_num;
	public:
		/*********************************************************************
		 * ** Function: Zoo()
		 * ** Description: default constructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object declared
		 * ** Post-Conditions: object created
		 * *********************************************************************/
		Zoo();
		/*********************************************************************
		 * ** Function: ~Zoo()
		 * ** Description: destructor
		 * ** Parameters: N/a
		 * ** Pre-Conditions: object out of scope
		 * ** Post-Conditions: correct
		 * *********************************************************************/
		~Zoo();
		/*********************************************************************
		 * ** Function: start()
		 * ** Description: starts the zoo, gets zoo name
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void start();
		/*********************************************************************
		 * ** Function: week_check()
		 * ** Description: checks the bank and if the player wants to go another week
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		bool week_check();
		/*********************************************************************
		 * ** Function: age()
		 * ** Description: ages all animals by 1 week
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void age();
		/*********************************************************************
		 * ** Function: special_event()
		 * ** Description: runs a random special event
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void special_event();
		/*********************************************************************
		 * ** Function: weekly_revenue()
		 * ** Description: collects weekly revenue from all animals
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void weekly_revenue();
		/*********************************************************************
		 * ** Function: buy_animals()
		 * ** Description: lets the user buy animals if they want to
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void buy_animals();
		/*********************************************************************
		 * ** Function: buy_feed()
		 * ** Description: buys the feed required for how many animals the user has
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void buy_feed();
		/*********************************************************************
		 * ** Function: display()
		 * ** Description: displays all important information about the zoo at end of week
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: runs
		 * *********************************************************************/
		void display();
		/*********************************************************************
		 * ** Function: update_monk(Monkey*, int)
		 * ** Description: updates the monkey array with new monkeys
		 * ** Parameters: Monkey*, int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: updates array
		 * *********************************************************************/
		void update_monk(Monkey*, int);
		/*********************************************************************
		 * ** Function: update_kats(Meerkat*, int)
		 * ** Description: updates the meerkat array with new meerkats
		 * ** Parameters: Meerkat*, int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: updates array
		 * *********************************************************************/
		void update_kats(Meerkat*, int);
		/*********************************************************************
		 * ** Function: update_otts(Seaotter*, int)
		 * ** Description: updates the sea otter array with new sea otters
		 * ** Parameters: Seaotter*, int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: updates array
		 * *********************************************************************/
		void update_otts(Seaotter*, int);
		/*********************************************************************
		 * ** Function: adult_baby_animals()
		 * ** Description: gets the number of adult and baby animals
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: gets number of adult and baby animals
		 * *********************************************************************/
		void adult_baby_animals();
};

#endif
