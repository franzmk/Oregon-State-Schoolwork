/*********************************************************************
 * ** Program Filename: prog.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Application file that holds main function
 * ** Input: Grid size and debug mode true/false
 * ** Output: N/a
 * *********************************************************************/

#include "player.h"

/*********************************************************************
 * ** Function: go
 * ** Description: Checks command line arguments for game
 * ** Parameters: int argc, char** argv, int &grid_size, bool &debug
 * ** Pre-Conditions: called
 * ** Post-Conditions: works correctly
 * *********************************************************************/ 

void go(int argc, char** argv, int &grid_size, bool &debug) {
	if(argc != 3) {
		cout << "Not enough command line arguments!" << endl;
		cout << "Exiting..." << endl;
		return;
	}

	else {
		grid_size = atoi(argv[1]);
		string temp = argv[2];
		if(temp == "true") {
			debug = true;
		}
	}

	if(grid_size < 4) {
		cout << "Grid size too small, must be greater than 4!" << endl;
		cout << "Exiting..." << endl;
		return;
	}
}

/*********************************************************************
 * ** Function: main
 * ** Description: main function, runs program
 * ** Parameters: int argc, char** argv
 * ** Pre-Conditions: program is run
 * ** Post-Conditions: calls all functions
 * *********************************************************************/ 

int main(int argc, char** argv) {
	int grid_size = 0;
	bool debug = false;
	
	go(argc, argv, grid_size, debug);
	
	Player p(grid_size, debug);

	p.fill();

	do {
		p.print_grid();

		p.check_nearby();
		
		p.take_input();

		p.wumpus_move();

		p.check_pos();
	} while(p.check_status());

	return 0;
}
