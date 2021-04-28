/*********************************************************************
 * ** Program Filename: player.h
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Header file for player class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "pit.h"
#include "bat.h"
#include "gold.h"

using namespace std;

class Player {
	private:
		int x_pos;
		int y_pos;
		int rope_x;
		int rope_y;
		bool has_gold;
		int num_arrows;
		bool wumpus_status;
		bool debug_mode;
		int grid;
		bool alive;
		bool wumpus_awake;
		vector<vector<Room> > Cave;
	public:
		/*********************************************************************
		 * ** Function: Player(int, bool)
		 * ** Description: constructor for player class
		 * ** Parameters: int, bool
		 * ** Pre-Conditions: called 
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		Player(int, bool);
		/*********************************************************************
		 * ** Function: fill()
		 * ** Description: master fill function, calls individual functions to fill Cave
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void fill();
		/*********************************************************************
		 * ** Function: fill_wumpus()
		 * ** Description: places wumpus event in a room within Cave vector
		 * ** Parameters: N/a 
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void fill_wumpus();
		/*********************************************************************
		 * ** Function: fill_pits()
		 * ** Description: places pit events in rooms within Cave vector
		 * ** Parameters: N/a 
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void fill_pits();
		/*********************************************************************
		 * ** Function: fill_bats()
		 * ** Description: places bat events in rooms within Cave vector
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void fill_bats();
		/*********************************************************************
		 * ** Function: fill_gold()
		 * ** Description: places gold event in room within Cave vector
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void fill_gold();
		/*********************************************************************
		 * ** Function: place_player()
		 * ** Description: places player in a room with no event in Cave vector
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void place_player();
		/*********************************************************************
		 * ** Function: print_grid()
		 * ** Description: prints game board in grid form
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void print_grid();
		/*********************************************************************
		 * ** Function: check_nearby()
		 * ** Description: checks all immediate nearby rooms of player
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void check_nearby();
		/*********************************************************************
		 * ** Function: take_input()
		 * ** Description: takes movement or arrow input
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void take_input();
		/*********************************************************************
		 * ** Function: check_pos()
		 * ** Description: checks the room the player is currently in for events
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void check_pos();
		/*********************************************************************
		 * ** Function: check_status()
		 * ** Description: checks if player has won, died, or lost
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		bool check_status();
		/*********************************************************************
		 * ** Function: shoot_arrow(int)
		 * ** Description: arrow shooting function
		 * ** Parameters: int
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void shoot_arrow(int);
		/*********************************************************************
		 * ** Function: wumpus_move()
		 * ** Description: enabled if arrow misses, 75% chance for wumpus to move into an empty room
		 * ** Parameters: N/a
		 * ** Pre-Conditions: called
		 * ** Post-Conditions: works
		 * *********************************************************************/ 
		void wumpus_move();
};

#endif
