/*********************************************************************
 * ** Program Filename: player.cpp
 * ** Author: Max
 * ** Date: 5/25/19
 * ** Description: Driver file for player class
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "player.h"

Player::Player(int grid_size, bool debug) {
	x_pos = 0;
	y_pos = 0;
	rope_x = 0;
	rope_y = 0;
	has_gold = false;
	num_arrows = 3;
	wumpus_status = true;
	debug_mode = debug;
	grid = grid_size;
	alive = true;
	wumpus_awake = false;
	Cave = vector<vector<Room> >(grid_size, vector<Room> (grid_size));
}

void Player::fill_wumpus() {
	srand(time(NULL));
	int x, y;
	do {
		x = rand() % grid;
		y = rand() % grid;
	} while(Cave[x][y].get_event() != NULL);
	Cave[x][y].set_event(new Wumpus());
	Cave[x][y].get_event()->set_x(x);
	Cave[x][y].get_event()->set_y(y);
}

void Player::fill_pits() {
	srand(time(NULL));
	int x, y;
	for(int i = 0; i < 2; i++) {
		do {
			x = rand() % grid;
			y = rand() % grid;
		} while(Cave[x][y].get_event() != NULL);
		Cave[x][y].set_event(new Pit());
		Cave[x][y].get_event()->set_x(x);
		Cave[x][y].get_event()->set_y(y);
	}
}

void Player::fill_bats() {
	srand(time(NULL));
	int x, y;
	for(int i = 0; i < 2; i++) {
		do {
			x = rand() % grid;
			y = rand() % grid;
		} while(Cave[x][y].get_event() != NULL);
		Cave[x][y].set_event(new Bat());
		Cave[x][y].get_event()->set_x(x);
		Cave[x][y].get_event()->set_y(y);
	}
}

void Player::fill_gold() {
	srand(time(NULL));
	int x, y;
	do {
		x = rand() % grid;
		y = rand() % grid;
	} while(Cave[x][y].get_event() != NULL);
	Cave[x][y].set_event(new Gold());
	Cave[x][y].get_event()->set_x(x);
	Cave[x][y].get_event()->set_y(y);
}

void Player::place_player() {
	srand(time(NULL));
	do {
		x_pos = rand() % grid;
		y_pos = rand() % grid;
	} while(Cave[x_pos][y_pos].get_event() != NULL);
	rope_x = x_pos;
	rope_y = y_pos;
}

void Player::fill() {
	fill_wumpus();
	fill_pits();
	fill_bats();
	fill_gold();
	
	place_player();
}

void Player::print_grid() {
	cout << "+";
	for(int i = 0; i < grid; i++) {
		cout << "----+";
	}
	cout << endl;
	for(int y = 0; y < grid; y++) {
		for(int x = 0; x < grid; x++) {
			int checked = 0, symb = 0, x_num = 0, event_x;
			if(Cave[x][y].get_event() != NULL) event_x = Cave[x][y].get_event()->get_x();
			if(debug_mode == true) {
				for(int i = 0; i < grid; i++) {
					if(x == x_pos && y == y_pos && checked == 0 && x_num == x_pos) {
						cout << "| * |";
						checked = 1;
						x_num++;
					}
					else if(Cave[x][y].get_event() != NULL && symb == 0 && x_num == event_x) {
						cout << "| " << Cave[x][y].get_event()->get_symbol() << " |";
						symb = 1;
						x_num++;
					}
					else {
						cout << "|   |";
						x_num++;
					}
				}
			}
			else {
				for(int i = 0; i < grid; i++) {
					if(x == x_pos && y == y_pos && checked == 0 && x_num == x_pos) {
						cout << "| * |";
						checked = 1;
						x_num++;
					}
					else {
						cout << "|   |";
						x_num++;
					}
				}
			}
			cout << endl;
		}
		cout << "+";
		for(int i = 0; i < grid; i++) {
			cout << "----+";
		}
		cout << endl;
	}
}

void Player::check_nearby() {
	cout << endl;
	if(y_pos - 1 < grid && y_pos - 1 != grid && y_pos - 1 >= 0) {//up
		if(Cave[x_pos][y_pos-1].get_event() != NULL) {
			Cave[x_pos][y_pos-1].get_event()->percept();
		}
	}
	if(y_pos + 1 < grid && y_pos + 1 != grid && y_pos + 1 >= 0) {//down
		if(Cave[x_pos][y_pos+1].get_event() != NULL) {
			Cave[x_pos][y_pos+1].get_event()->percept();
		}
	}
	if(x_pos + 1 < grid && x_pos + 1 != grid && x_pos + 1 >= 0) {//right
		if(Cave[x_pos+1][y_pos].get_event() != NULL) {
			Cave[x_pos+1][y_pos].get_event()->percept();
		}
	}
	if(x_pos - 1 < grid && x_pos - 1 != grid && x_pos - 1 >= 0) {//left
		if(Cave[x_pos-1][y_pos].get_event() != NULL) {
			Cave[x_pos-1][y_pos].get_event()->percept();
		}
	}
	cout << endl;
}

void Player::shoot_arrow(int dir) {
	num_arrows -= 1;
	
	if(dir == 1) { //up
		for(int i = 1; i <= 3; i++) {
			if(y_pos - i >= 0) {
				if(Cave[x_pos][y_pos - i].get_event() != NULL) {
					if(Cave[x_pos][y_pos - i].get_event()->get_symbol() == 'W') {
						cout << "You hit and killed the Wumpus!" << endl;
						wumpus_status = false;
						Cave[x_pos][y_pos - i].set_event(NULL);
						break;
					}
					else if(i == 3) cout << "You didn't hit the Wumpus and it's now awake!" << endl;
				}
			}
			else cout << "You're arrow hit the wall of the cave and the Wumpus is now awake!" << endl;
		}
	}
	if(dir == 2) { //left
		for(int i = 1; i <= 3; i++) {
			if(x_pos - i >= 0) {
				if(Cave[x_pos - i][y_pos].get_event() != NULL) {
					if(Cave[x_pos - i][y_pos].get_event()->get_symbol() == 'W') {
						cout << "You hit and killed the Wumpus!" << endl;
						wumpus_status = false;
						Cave[x_pos - i][y_pos].set_event(NULL);
						break;
					}
					else if(i == 3) cout << "You didn't hit the Wumpus and it's now awake!" << endl;
				}
			}
			else cout << "You're arrow hit the wall of the cave and the Wumpus is now awake!" << endl;
		}
	}
	if(dir == 3) { //down
		for(int i = 1; i <= 3; i++) {
			if(y_pos + i < grid) {
				if(Cave[x_pos][y_pos + i].get_event() != NULL) {
					if(Cave[x_pos][y_pos + i].get_event()->get_symbol() == 'W') {
						cout << "You hit and killed the Wumpus!" << endl;
						wumpus_status = false;
						Cave[x_pos][y_pos + i].set_event(NULL);
						break;
					}
					else if(i == 3) cout << "You didn't hit the Wumpus and it's now awake!" << endl;
				}
			}
			else cout << "You're arrow hit the wall of the cave and the Wumpus is now awake!" << endl;
		}
	}
	if(dir == 4) { //right
		for(int i = 1; i <= 3; i++) {
			if(x_pos + i < grid) {
				if(Cave[x_pos + i][y_pos].get_event() != NULL) {
					if(Cave[x_pos + i][y_pos].get_event()->get_symbol() == 'W') {
						cout << "You hit and killed the Wumpus!" << endl;
						wumpus_status = false;
						Cave[x_pos + i][y_pos].set_event(NULL);
						break;
					}
					else if(i == 3) cout << "You didn't hit the Wumpus and it's now awake!" << endl;
				}
			}
			else cout << "You're arrow hit the wall of the cave and the Wumpus is now awake!" << endl;
		}
	}
}

void Player::wumpus_move() {
	srand(time(NULL));
	int move_chance = (rand() % 100) + 1;
	int move_dir = (rand() % 4) + 1;
	if(wumpus_awake == true) {
		for(int y = 0; y < grid; y++) {
			for(int x = 0; x < grid; x++) {
				if(Cave[x][y].get_event() != NULL) {
					if(Cave[x][y].get_event()->get_symbol() == 'W') {	
						if(move_chance < 75) {
							if(move_dir == 1) {
								if(Cave[x][y-1].get_event() == NULL) {
									Cave[x][y-1] = Cave[x][y];
									Cave[x][y].set_event(NULL);
								}
							}
							if(move_dir == 2) {
								if(Cave[x][y+1].get_event() == NULL) {
									Cave[x][y+1] = Cave[x][y];
									Cave[x][y].set_event(NULL);
								}
							}
							if(move_dir == 3) {
								if(Cave[x-1][y].get_event() == NULL) {
									Cave[x-1][y] = Cave[x][y];
									Cave[x][y].set_event(NULL);
								}
							}
							if(move_dir == 4) {
								if(Cave[x+1][y].get_event() == NULL) {
									Cave[x+1][y] = Cave[x][y];
									Cave[x][y].set_event(NULL);
								}
							}
						}
					}
				}
			}
		}
	}
}

void Player::take_input() {
	if(num_arrows > 0) cout << "You have " << num_arrows << " arrows remaining! Use them wisely!" << endl;
	else {
		cout << "You have no arrows left!" << endl;
		cout << "You lose!" << endl;
	}

	string input;
	cout << "Input: ";
	getline(cin, input);

	if(input == " w" && num_arrows > 0) {
		cout << "You shot an arrow to the North!" << endl;
		shoot_arrow(1);
	}
	if(input == " a" && num_arrows > 0) {
		cout << "You shot an arrow to the West!" << endl;
		shoot_arrow(2);
	}
	if(input == " s" && num_arrows > 0) {
		cout << "You shot an arrow to the South!" << endl;
		shoot_arrow(3);
	}
	if(input == " d" && num_arrows > 0) {
		cout << "You shot an arrow to the East!" << endl;
		shoot_arrow(4);
	}
	if(input == "w") {
		y_pos -= 1;
	}
	if(input == "a") {
		x_pos -= 1;
	}
	if(input == "s") {
		y_pos += 1;
	}
	if(input == "d") {
		x_pos += 1;
	}
}

void Player::check_pos() {
	srand(time(NULL));
	if(Cave[x_pos][y_pos].get_event() != NULL) {
		int type = 0;
		Cave[x_pos][y_pos].get_event()->encounter(type);
		if(type == 1) { //wumpus
			alive = false;
			return;
		}
		if(type == 2) { //pit
			alive = false;
			return;
		}
		if(type == 3) { //gold
			Cave[x_pos][y_pos].set_event(NULL);
			has_gold = true;
		}
		if(type == 4) { //bat
			//int x = x_pos;
			//int y = y_pos;
			x_pos = rand() % grid;
			y_pos = rand() % grid;
			check_pos();
			//Cave[x_pos][y_pos] = Cave[x][y];
			//Cave[x][y].set_event(NULL);
		}
	}
}

bool Player::check_status() {
	if(x_pos == rope_x && y_pos == rope_y && has_gold == true && wumpus_status == false) {
		cout << endl;
		cout << "You found the gold, killed the Wumpus, and made it back to the escape rope!" << endl;
		cout << "You win!" << endl;
		cout << endl;
		return false;
	}
	if(num_arrows == 0) {
		cout << endl;
		cout << "You're out of arrows! Game over!" << endl;
		cout << endl;
		return false;
	}
	if(alive == true) return true;
	else return false;
}
