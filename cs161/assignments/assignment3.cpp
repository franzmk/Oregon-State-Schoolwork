/*********************************************************************
 * ** Program Filename: assignment3.cpp
 * ** Author: Max Franz
 * ** Date: 2/3/19
 * ** Description: Basically Black Jack
 * ** Input:
 * ** Output:
 * *********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <typeinfo>

using namespace std;

/*********************************************************************
 * ** Function: drawCard()
 * ** Description: This function generates a new card value between 1-11.
 * ** Parameters: No parameters
 * ** Pre-Conditions:
 * ** Post-Conditions:
 * *********************************************************************/

int drawCard() {
	srand(time(NULL));
	int card = rand() % 11 + 1;
	return card;
}

/*********************************************************************
 * ** Function: winCheck()
 * ** Description: This function returns however much money the user won or lost based on there total and the dealer total.
 * ** Parameters: x, total, bet, and value 
 * ** Pre-Conditions: All parameters have a value before using this function
 * ** Post-Conditions: Value has something in it 
 * *********************************************************************/

int winCheck(int x, int total, int bet) {
	int value = 0;
	switch(x) {
		case 1: value = total + bet * 2; break; //win
		case 2: value = total; break; //loss
		case 3: value = total + bet; break; //tie
		case 4: value = total; break; //bust
		default: value = total;
	}
	return value;
}

/*********************************************************************
 * ** Function: check21()
 * ** Description: Checks if the total card value given as a num is over 21 or not
 * ** Parameters: num
 * ** Pre-Conditions: 
 * ** Post-Conditions:
 * *********************************************************************/

bool check21(int num) {
	if (num > 21) {
		return true;
	}
	else {
		return false;
	}
}

/*********************************************************************
 * ** Function: checkBal()
 * ** Description: Checks if the user has a bank of $1 or more
 * ** Parameters: bal
 * ** Pre-Conditions:
 * ** Post-Conditions:
 * *********************************************************************/

bool checkBal(int bal) {
	if (bal >= 1) {
		return true;
	}
	else {
		return false;
	}
}

/*********************************************************************
 * ** Function: main()
 * ** Description: This is the entire game
 * ** Parameters: Everything
 * ** Pre-Conditions: Working compiler
 * ** Post-Conditions: A game of Twenty One
 * *********************************************************************/

int main() {

	srand(time(NULL)); //seeds the random number

	int players, money = 0, bid;
	bool playing = true, pBust = false, dBust = false;
	//the rules
	cout << endl;
	cout << "Rules: " << endl;
	cout << "If the player busts, the player automatically loses their bet, and the dealer doesn’t need to play against that player." << endl;
	cout << "If the dealer busts, the player automatically wins their bet." << endl;
	cout << "If the dealer ties with the player, then the player doesn’t win or lose their bet." << endl;
	cout << "If the player’s bet is more than their bank, then you need to continue to re-prompt for a new bet until a good value is given." << endl;
	cout << "If a player’s bank is 0, they get skipped." << endl;
	cout << "If all players’ banks are 0, then the game is automatically over!" << endl;
	cout << "After all players take a turn against the dealer, then the players can collectively cash out or play again." << endl;
	cout << endl;
	cout << "How many players are playing? (1-4): ";
	cin >> players; //takes num 1-4 as input
	if (players > 4 || players < 1) { //if input isnt 1-4 then the game exits
		cout << "Number of players must be between 1-4!" << endl;
		cout << "Exiting now..." << endl;
		exit(0);
	}

	int bank[players]; //this is the banking system, keeps track of the players balance

	for (int i = 1; i <= players; i++) { //runs for however many players there are

		cout << endl;
		cout << "Player " << i << ", how much money do you have to start? (Integer only): $";
		cin >> money;
		if (money > 4200000 || money <= 0 || typeid(money) != typeid(int)) { //if the starting money is great than $4.2 million or less than $0 or the wrong type, the game exits
			cout << "Can't do that." << endl;
			cout << "Exiting now..." << endl;
			exit(0);
		}

		bank[i-1] = money; //their bank slot gets whatever they input

	}

	while (playing == true) { //this checks that everyone has more than $0
		for (int i = 1; i <= players; i++) {

			bool play = true, pTurn = true, twentyOne = false, dTurn = true, pBust = false, dBust = false;
			int card_value = 0, total_value = 0, dCard = 0, dTotal = 0;
			char again = ' ';

			if (bank[i-1] <= 0) { //this checks if a player has $0 at the start of their turn, if they do they get skipped
				cout << "Player " << i << ", you're out of money! Next player!" << endl;
				cout << endl;
				play = false;
				pTurn = false;
				dTurn = false;
				pBust = true;
				dBust = true;
			}
			else {
				cout << endl;
				cout << "Player " << i << ", " << "your balance is $" << bank[i-1] << ", how much do you want to bid?: $";
				cin >> bid;
				if(bid > bank[i-1] || bid < 0 || typeid(bid) != typeid(int)) { //if they bid more than they have in their bank, if they bid less than 0, or if they enter a different type, game exits
					cout << "That's not allowed." << endl;
					cout << "Exiting now..." << endl;
					exit(0);
				}
				bank[i-1] = bank [i-1] - bid; //their bid is subtracted from their total bank
				cout << "Your new balance: $" << bank[i-1] << endl; //new balance is printed
			}

			while (play == true) { //while the player is playing, this is true
				if (pTurn == true) { //when its player turn, this is true
					cout << endl;
					card_value = drawCard();
					total_value += card_value;
					sleep(0.5); //this waits between card delivery to increase randomness
					cout << "Player " << i << ", you got " << card_value << ". Your total is " << total_value << "." << endl;
					twentyOne = check21(total_value); //this checks if the player has 21 or higher
					if (twentyOne == false) { //if they havent busted, they get to play again if they so choose
						cout << "Do you want to hit? (y/n): ";
						cin >> again;
						if (again == 'y') { //if they want to play again, it remains the players turn, if not pturn is set to false
							play = true;
							pTurn = true;
						}
						else { // if they don't want to go again, pturn is set to false and dealer goes
							play = false;
							pTurn = false;
							cout << endl;
							cout << "The dealer goes now." << endl;
						}
					}
					else { //if the player busts then the dealer is skipped and you lose your bet, next player goes
						cout << "You busted. You lose your bet." << endl;
						bank[i-1] = winCheck(4, bank[i-1], bid);
						cout << "Your balance is now $" << bank[i-1] << " and your turn is over." << endl;
						play = false;
						dTurn = false;
						pBust = true;
						pTurn = false;
					}
				}
				else {
					break; //breaks out of loop to go to dealer or to next player
				}
			}

			//dealer goes
			
			while (dTurn == true && pBust == false) { //if the player didn't bust and it is the dealer's turn, dealer goes
				if (dTotal <= 17) { //dealer will stop at 17
					dCard = drawCard();
					dTotal += dCard; //dealer gets card
					sleep(1); //dealer waits 1 second in between card delivery to increase randomness
					cout << "The dealer drew a " << dCard << " for a total of " << dTotal << "." << endl;
					if (check21(dTotal) == false) { //if the dealer has 21 or less, it remains their turn
						dTurn = true;
					}
					else { //if the dealer busts, player wins and goes to next player
						cout << "The dealer busted. You win." << endl;
						bank[i-1] = winCheck(1, bank[i-1], bid);
						cout << "Your balance is now $" << bank[i-1] << " and your turn is over." << endl;
						dBust = true;
						dTurn = false;
					}
				}
				else {
					break; //breaks out of while loop after dealers turn

				}
			}

			if (dBust == false && pBust == false) { //if neither the player nor the dealer busted, goes into total checks
				if (total_value > dTotal) { //if the player wins
					cout << endl;
					cout << "You beat the dealer with a " << total_value << ", they had a " << dTotal << "." << endl;
					bank[i-1] = winCheck(1, bank[i-1], bid);
					cout << "Your balance is now $" << bank[i-1] << " and your turn is over." << endl;
				}
				else if (total_value < dTotal) { //if the dealer wins
					cout << endl;
					cout << "The dealer beat you with a " << dTotal << ", you had a " << total_value << "." << endl;
					bank[i-1] = winCheck(2, bank[i-1], bid);
					cout << "Your balance is now $" << bank[i-1] << " and your turn is over." << endl;
				}
				else if (total_value == dTotal) { //if the player and dealer tie
					cout << endl;
					cout << "You and the dealer tied, both with a " << total_value << "." << endl;
					bank[i-1] = winCheck(3, bank[i-1], bid);
					cout << "Your balance is now $" << bank[i-1] << " and your turn is over." << endl;
				}
			}

			else { //if either the player or dealer busted, those checks are skipped and it's the next players turn
				cout << endl;
				cout << "Next player!" << endl;
			}
		}

	int x = 0;
	for (int j = 1; j <= players; j++) { //checks each players balance after all players have gone, if player balance is zero x increases
		cout << "Player " << j << "'s balance is $" << bank[j-1] << "." << endl;
		if (bank[j-1] <= 0)
			x++;
	}
	if (x == players) { //if every player has $0, then the game exits
		cout << "Game over. Everyone's balance is $0 or lower!" << endl;
		playing = false;
		exit(0);
	}

	char ask; //if at least one player doesn't have $0, then they can keep playing
	cout << "Did you all want to keep playing? (y/n): ";
	cin >> ask;
	if (ask == 'y') {
		playing = true;
	}
	else { //if they want to exit or cash out, game exits and playing is set to false
		cout << "You all cashed out! Game over!" << endl;
		playing = false;
	}

	}
	cout << "Game ended." << endl; //game ends
	return 0;
} //end
