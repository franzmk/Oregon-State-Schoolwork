/******************************************************
 * ** Program: assignment2.cpp
 * ** Author: Max Franz
 * ** Date: 01/20/2019
 * ** Description: Adventure Game
 * ** Input: 1 and 2 only
 * ** Output: Text for the adventure
 * * ******************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	srand(time(NULL));

	int l_or_r;
	int r = rand() % 41; //makes a random number between 0-40
	char again; //this is to check if they enter "y" when asked to play again

	cout << endl;
	cout << "Hello and welcome to Adventure Land! To go left, enter 1, and to go right, enter 2: ";
	cin >> l_or_r;
//the story is completely random and is not the same all the way through, it kinda changes
	if (l_or_r == 1) { //first set of choices

		cout << endl;
		cout << "You have gone left! After traveling to the left you have entered a jungle!" << endl;	
		cout << "Do you enter the jungle (1) or keep traveling along the edge of the jungle (2)?: ";
		cin >> l_or_r;

		if (l_or_r == 1) {

			cout << endl;
			cout << "You have entered the jungle! After entering the jungle, you see a fork in the path!" << endl;
			cout << "Do you go left (1) or right (2)?: ";
			cin >> l_or_r;

			if (l_or_r == 1) {

				cout << endl;
				cout << "You went left! After going to the left, you discover a snake in the middle of the path!" << endl;
				cout << "Do you attack the snake (1) or do you run into the brush to the right (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {
					
					cout << endl;
					cout << "You attacked the snake! After attacking the snake you got " << r << " gold pieces!" << endl;
					
					if (r >= 20) { //random chance of winning is based on the gold you get

						cout << "Congratulations! You got enough gold to win!" << endl;
						cout << "You win!" << endl;
						cout << endl;
//every ending scenario has this code below asking if they want to play again or quit
						cout << "Do you wish to play again? (y/n): ";
						cin >> again;

						if (again == 'y') {
							cout << endl;
							main();
						}

						else {
							exit(0);
						}
					}

					else {
						
						cout << "You didn't get enough gold to win, sorry!" << endl;
						cout << "You lose!" << endl;
						cout << endl;

						cout << "Do you wish to play again? (y/n): ";
						cin >> again;

						if (again == 'y') {
							cout << endl;
							main();
						}

						else {
							exit(0);
						}
					}
				}

				else if (l_or_r == 2) {

					cout << endl;
					cout << "You ran into the brush to the right! Unfortunately, you ran straight off of a cliff!" << endl;
					cout << "You died!" << endl;
					cout << endl;
					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}

			else if (l_or_r == 2) {

				cout << endl;
				cout << "You went to the right! After going to the right you discover an oasis in the opening up ahead!" << endl;
				cout << "Do you get in the water to cool off (1) or do you keep moving past the oasis (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {

					cout << endl;
					cout << "You got in the water to cool off and guess what?! You died!" << endl;
					cout << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}

				else if (l_or_r == 2) {
					
					cout << endl;
					cout << "You kept moving past the oasis! As you pass it you're ambushed by a group of warriors!" << endl;
					cout << "They outnumber you 10 to 1! Unfortunately, they capture you and bring you back to their camp!" << endl;
					cout << "Once there, they roast you over an open fire and you die an agonizing death!" << endl;
					cout << "You lose!" << endl;
					cout << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}
		}

		else if (l_or_r == 2) {

			cout << endl;
			cout << "You continue to travel along the edge of the jungle! As you travel farther, you see a castle in the distance!" << endl;
			cout << "Do you continue to travel along the path (1) or veer off to travel towards the castle (2)?: ";
			cin >> l_or_r;

			if (l_or_r == 1) {

				cout << endl;
				cout << "You continue to travel along the path in front of you! You see a large tree!" << endl;
				cout << "As you get closer you see it's glowing red!" << endl;
				cout << "Do you approach the tree (1) or do you go home (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {
					
					cout << endl;
					cout << "You approach the tree! As you get closer, the tree starts to glow brighter!" << endl;
					cout << "At a certain point it gets too bright and you are blinded!" << endl;
					cout << "Upon losing vision, you lose!" << endl;
					cout << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}

				else if (l_or_r == 2) {

					cout << endl;
					cout << "You go back home!" << endl;
					cout << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}

			else if (l_or_r == 2) {

				cout << endl;
				cout << "You veer off towards the castle! As you approach, the guards atop the wall yell down to you" << endl;
				cout << "\"Approach any closer and we will fire on you traveler!\"" << endl;
				cout << "Do you try to talk your way in to the castle (1) or do you turn around and go home (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {

					cout << endl;
					cout << "You try to convince the guards that you mean no harm, but they're not having it!" << endl;
					cout << "They begin to fire at you, and you try to hide behind cover, but there isn't any!" << endl;
					cout << "You die, which means you lose!" << endl;
					cout << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}

				else if (l_or_r == 2) {

					cout << endl;
					cout << "You go back home!" << endl;
					cout << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}
		}
	} //this is the end of the first side, if they picked 1 as the first choice

//this is the beginning of the second path, if they chose 2 as the first choice
	else if (l_or_r == 2) {

		cout << endl;
		cout << "You have gone right! You have traveled to a small village!" << endl;
		cout << "Do you enter the village (1) or do you continue around it (2)?: ";
		cin >> l_or_r;

		if (l_or_r == 1) {

			cout << endl;
			cout << "You have entered the village! As you enter the village, there's an explosion!" << endl;
			cout << "Do you go investigate the explosion (1) or do you search for somewhere to rest (2)?: ";
			cin >> l_or_r;

			if (l_or_r == 1) {

				cout << endl;
				cout << "You went to investigate the explosion! Upon further investigation, you find that a tavern has blown up!" << endl;
				cout << "Do you go closer to the tavern to investigate (1) or do you go find somewhere else to rest (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {
					
					cout << endl;
					cout << "You got closer to investigate the tavern that blew up! As you get closer you hear something!" << endl;
					cout << "You slow down, but keep inching forward toward the blast zone!" << endl;
					cout << "As you get closer, you realize the noise you hear is the sound of a still-lit fuse!" << endl;
					cout << "Do you try to run away from the bomb that's about to blow up (1) or do you accept your fate (2)?: ";
					cin >> l_or_r;

					if (l_or_r == 1) {
						
						cout << endl;
						cout << "You have a 10\% chance to escape the blast!" << endl;
						cout << endl;

						if (r <= 4) { //winning here is based on random number as well, the chance requirement

							cout << "You survived!" << endl;
							cout << "Congratulations! You win!" << endl;

							cout << "Do you wish to play again? (y/n): ";
							cin >> again;

							if (again == 'y') {
							cout << endl;
							main();
							}

							else {
								exit(0);
							}
						}

						else {
							
							cout << "Sorry! The blast killed you!" << endl;
							cout << "You lose!" << endl;


							cout << "Do you wish to play again? (y/n): ";
							cin >> again;

							if (again == 'y') {
								cout << endl;
								main();
							}

							else {
								exit(0);
							}
						}
					}

					else if (l_or_r == 2) {
						
						cout << endl;
						cout << "You accept your fate and the blast kills you!" << endl;
						cout << "You lose!" << endl;


						cout << "Do you wish to play again? (y/n): ";
						cin >> again;

						if (again == 'y') {
							cout << endl;
							main();
						}

						else {
							exit(0);
						}
					}

				}

				else if (l_or_r == 2) {
					
					cout << endl;
					cout << "You found a tavern to rest in!" << endl;
					cout << "Unfortunately, you died in your sleep due to natural causes!" << endl;
					cout << "You lose!" << endl;

					
					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}

			else if (l_or_r == 2) {

				cout << endl;
				cout << "You went to search for somewhere to rest! You came across a cozy looking inn!" << endl;
				cout << "Do you go inside and ask for a room (1) or do you keep looking (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {
					
					cout << endl;
					cout << "You enter the inn and ask for a room! The clerk doesn't like the way you look though and pulls a shotgun on you!" << endl;
					cout << "The clerk shoots you with a shotgun! And you die!" << endl;
					cout << "You lose!" << endl;

					
					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}

				else if (l_or_r == 2) {
					
					cout << endl;
					cout << "You keep searching, but you can't find anything! Upon returning to the same inn, you are shot with a shotgun! You died!" << endl;
					cout << "You lose!" << endl;


					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}
		}

		else if (l_or_r == 2) {

			cout << endl;
			cout << "You have gone around the village! As you near the far edge of the village, there's an explosion!" << endl;
			cout << "Do you go investigate the explosion in the village (1) or continue past the village (2)?: ";
			cin >> l_or_r;

			if (l_or_r == 1) {

				cout << endl;
				cout << "You investigate the explosion! There's a maniac on the loose killing everyone! You are shot and die!" << endl;
				cout << "Do you struggle to stay alive (1) or do you accept your fate (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {
					
					cout << endl;
					cout << "You struggle to stay alive, and unfortunately you don't make it!" << endl;
					cout << "You lose!" << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}

				else if (l_or_r == 1) {
					
					cout << endl;
					cout << "You accept your fate!" << endl;
					cout << "You lose!" << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}

			else if (l_or_r == 2) {

				cout << endl;
				cout << "You continue past the explosion and see a river come in from your left and a trail to your right with horses tied down!" << endl;
				cout << "Do you take a horse and follow the river to the left (1) or take a horse and follow the trail to the right (2)?: ";
				cin >> l_or_r;

				if (l_or_r == 1) {
					
					cout << endl;
					cout << "You took a horse and followed the river! You found your way back home!" << endl;
					cout << "You win!" << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}

				else if (l_or_r == 2) {
					
					cout << endl;
					cout << "You took a horse and followed the trail! You found your way back home!" << endl;
					cout << "You win!" << endl;

					cout << "Do you wish to play again? (y/n): ";
					cin >> again;

					if (again == 'y') {
						cout << endl;
						main();
					}

					else {
						exit(0);
					}
				}
			}
		}
	}

	else { //this is to check that they enter a 1 or a 2 for the first choice, don't know how I would've implemented this into every single decision point

		cout << endl;
		cout << "You must enter 1 or 2!" << endl;
		main();
	}

	return 0;

} //end, sorry for how long it is
