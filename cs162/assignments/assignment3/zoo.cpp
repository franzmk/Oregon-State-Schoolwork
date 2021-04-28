/*********************************************************************
 * ** Program Filename: zoo.cpp
 * ** Author: Max
 * ** Date: 5/12/19
 * ** Description: Driver file for zoo.h
 * ** Input: N/a
 * ** Output: N/a
 * *********************************************************************/

#include "zoo.h"

Zoo::Zoo() {
	bank = 100000;
	zoo_name = "";

	monk = NULL;
	num_monkeys = 0;

	kats = NULL;
	num_meerkats = 0;

	otts = NULL;
	num_seaotters = 0;

	num_animals = 0;
	num_adults = 0;
	num_babies = 0;

	week_num = 0;
}

void Zoo::start() {
	string temp;
	cout << "Welcome! What would you like the name of your zoo to be?: ";
	getline(cin, temp);
	zoo_name = temp;
	cout << endl;
	cout << "Welcome to " << zoo_name << "!" << endl;
	cout << endl;
}

bool Zoo::week_check() {
	if(bank <= 0) {
		cout << "Sorry! You've gone bankrupt!" << endl;
		return false;
	}

	string temp;
	cout << "Would you like to continue to the next week? (Y/N) ";
	cin >> temp;

	if(temp == "Y") {
		return true;
	}
	else return false;
}

void Zoo::age() {
	if(num_animals != 0) {
		if(num_monkeys != 0) {
			for(int i = 0; i < num_monkeys; i++) {
				monk[i]++;
			}
		}
		if(num_meerkats != 0) {
			for(int i = 0; i < num_meerkats; i++) {
				kats[i]++;
			}
		}
		if(num_seaotters != 0) {
			for(int i = 0; i < num_seaotters; i++) {
				otts[i]++;
			}
		}
		cout << "All of your animals aged by 1 week!" << endl;
	}
	else {
		cout << "You have no animals to age!" << endl;
		cout << endl;
	}
	num_animals = num_monkeys + num_meerkats + num_seaotters;
}

void Zoo::special_event() {
	srand(time(NULL));
	int event = (rand() % 4) + 1;

	if(num_animals != 0) {
		if(event == 1) {
			int type = (rand() % 3) + 1;
			if(type == 1) {
				if(num_monkeys != 0) {
					cout << "A monkey got sick!" << endl;
					int an = rand() % (num_monkeys + 1);
					int price;
					if(monk[an].get_age() <= 5) {
						cout << "It's a baby!" << endl;
						price = monk[an].get_sick_cost() * 2;
					}
					else {
						cout << "It's an adult!" << endl;
						price = monk[an].get_sick_cost();
					}
					cout << "It's gonna cost you $" << price << " to take care of that monkey!" << endl;
					if(price < bank) {
						cout << "You have enough money for it!" << endl;
						bank -= price;
						cout << "Your bank account now reads: $" << bank << endl;
					}
					else {
						cout << "You dont have enough money to save the monkey!" << endl;
						cout << "The monkey, named " << monk[an].get_name() << ", has died!" << endl;
						Monkey *temp = new Monkey[num_monkeys];
						for(int i = 0; i < num_monkeys; i++) {
							if(an != i) {
								temp[i] = monk[i];
							}
						}
						for(int i = an; i < num_monkeys - 1; i++) {
							temp[i] = temp[i + 1];
						}
						num_monkeys -= 1;
						delete [] monk;
						monk = temp;
					}
				}
			}
			if(type == 2) {
				if(num_meerkats != 0) {
					cout << "A meerkat got sick!" << endl;
					int an = rand() % (num_meerkats + 1);
					int price;
					if(kats[an].get_age() <= 5) {
						cout << "It's a baby!" << endl;
						price = kats[an].get_sick_cost() * 2;
					}
					else {
						cout << "It's an adult!" << endl;
						price = kats[an].get_sick_cost();
					}
					cout << "It's gonna cost you $" << price << " to take care of that meerkat!" << endl;
					if(price < bank) {
						cout << "You have enough money for it!" << endl;
						bank -= price;
						cout << "Your bank account now reads: $" << bank << endl;
					}
					else {
						cout << "You dont have enough money to save the meerkat!" << endl;
						cout << "The meerkat, named " << kats[an].get_name() << ", has died!" << endl;
						Meerkat *temp = new Meerkat[num_meerkats];
						for(int i = 0; i < num_meerkats; i++) {
							if(an != i) {
								temp[i] = kats[i];
							}
						}
						for(int i = an; i < num_meerkats - 1; i++) {
							temp[i] = temp[i + 1];
						}
						num_meerkats -= 1;
						delete [] kats;
						kats = temp;
					}
				}
			}
			if(type == 3) {
				if(num_seaotters != 0) {
					cout << "A sea otter got sick!" << endl;
					int an = rand() % (num_seaotters + 1);
					int price;
					if(otts[an].get_age() <= 5) {
						cout << "It's a baby!" << endl;
						price = otts[an].get_sick_cost() * 2;
					}
					else {
						cout << "It's an adult!" << endl;
						price = otts[an].get_sick_cost();
					}
					cout << "It's gonna cost you $" << price << " to take care of that sea otter!" << endl;
					if(price < bank) {
						cout << "You have enough money for it!" << endl;
						bank -= price;
						cout << "Your bank account now reads: $" << bank << endl;
					}
					else {
						cout << "You dont have enough money to save the sea otter!" << endl;
						cout << "The sea otter, named " << otts[an].get_name() << ", has died!" << endl;
						Seaotter *temp = new Seaotter[num_seaotters];
						for(int i = 0; i < num_seaotters; i++) {
							if(an != i) {
								temp[i] = otts[i];
							}
						}
						for(int i = an; i < num_seaotters - 1; i++) {
							temp[i] = temp[i + 1];
						}
						num_seaotters -= 1;
						delete [] otts;
						otts = temp;
					}
				}
			}
			cout << endl;
		}
		if(event == 2) {
			int type = (rand() % 3) + 1;
			if(type == 1) {
				if(num_monkeys != 0) {
					int an = rand() % (num_monkeys + 1);
					if(monk[an].get_age() >= 52) {
						cout << "Your monkey " << monk[an].get_name() << " is giving birth!" << endl;
						Monkey *monk_temp = new Monkey[1];
						string m_name;
						cout << "What would you like to name your new monkey?: ";
						cin >> m_name;
						monk_temp[0] = Monkey(m_name);
						num_monkeys += 1;
						update_monk(monk_temp, 1);
					}
					else cout << "A monkey tried to give birth...it wasn't successful." << endl;
				}
			}
			if(type == 2) {
				if(num_meerkats != 0) {
					int an = rand() % (num_meerkats + 1);
					if(kats[an].get_age() >= 52) {
						cout << "Your meerkat " << kats[an].get_name() << " is giving birth!" << endl;
						Meerkat *meer_temp = new Meerkat[5];
						for(int i = 0; i < 5; i++) {
							string k_name;
							cout << "What would you like to name your new meerkat?: ";
							cin >> k_name;
							meer_temp[i] = Meerkat(k_name);
						}
						num_meerkats += 5;
						update_kats(meer_temp, 5);
					}
					else cout << "A meerkat tried to give birth...it wasn't successful." << endl;
				}
			}
			if(type == 3) {
				if(num_seaotters != 0) {
					int an = rand() % (num_seaotters + 1);
					if(otts[an].get_age() >= 52) {
						cout << "Your sea otter " << otts[an].get_name() << " is giving birth!" << endl;
						Seaotter *sea_temp = new Seaotter[2];
						for(int i = 0; i < 2; i++) {
							string s_name;
							cout << "What would you like to name your new sea otter?: ";
							cin >> s_name;
							sea_temp[i] = Seaotter(s_name);
						}
						num_seaotters += 2;
						update_otts(sea_temp, 2);
					}
					else cout << "A sea otter tried to give birth...it wasn't successful." << endl;
				}
			}
			cout << endl;
		}
		if(event == 3) {
			cout << "A boom in zoo attendance has occured!" << endl;
			for(int i = 0; i < num_monkeys; i++) {
				bank += monk[i].bonus_revenue();
			}
			cout << "You made a few extra dollars!" << endl;
			cout << endl;
		}
		if(event == 4) {
			cout << "Nothing special happened!" << endl;
			cout << endl;
		}
		num_animals = num_monkeys + num_meerkats + num_seaotters;
	}
	else cout << "You have no animals! No special event can occur!" << endl;
}

void Zoo::weekly_revenue() {
	if(num_animals != 0) {
		for(int i = 0; i < num_monkeys; i++) {
			bank += monk[i].revenue();
		}
		for(int i = 0; i < num_meerkats; i++) {
			bank += kats[i].revenue();
		}
		for(int i = 0; i < num_seaotters; i++) {
			bank += otts[i].revenue();
		}
		cout << "You've received your weekly income!" << endl;
		cout << "Your bank account now reads: $" << bank << endl;
		cout << endl;
	}
	else {
		cout << "You have no animals to collect revenue for!" << endl;
		cout << endl;
	}
	num_animals = num_monkeys + num_meerkats + num_seaotters;
}

void Zoo::update_monk(Monkey *monk_temp, int num) {
	Monkey *temp = new Monkey[num_monkeys-num];
	for(int i = 0; i < num_monkeys-num; i++) {
		temp[i] = monk[i];
	}
	delete [] monk;
	monk = new Monkey[num_monkeys];
	int j;
	for(j = 0; j < num_monkeys-num; j++) {
		monk[j] = temp[j];
	}
	for(int i = j; i < num; i++) {
		monk[i] = monk_temp[i];
	}

	delete [] temp;
	delete [] monk_temp;
}

void Zoo::update_kats(Meerkat *meer_temp, int num) {
	Meerkat *temp = new Meerkat[num_meerkats-num];
	for(int i = 0; i < num_meerkats-num; i++) {
		temp[i] = kats[i];
	}
	delete [] kats;
	kats = new Meerkat[num_meerkats];
	int j;
	for(j = 0; j < num_meerkats-num; j++) {
		kats[j] = temp[j];
	}
	for(int i = j; i < num; i++) {
		kats[i] = meer_temp[i];
	}

	delete [] temp;
	delete [] meer_temp;
}

void Zoo::update_otts(Seaotter *sea_temp, int num) {
	Seaotter *temp = new Seaotter[num_seaotters-num];
	for(int i = 0; i < num_seaotters-num; i++) {
		temp[i] = otts[i];
	}
	delete [] otts;
	otts = new Seaotter[num_seaotters];
	int j;
	for(j = 0; j < num_seaotters-num; j++) {
		otts[j] = temp[j];
	}
	for(int i = j; i < num; i++) {
		otts[i] = sea_temp[i];
	}

	delete [] temp;
	delete [] sea_temp;
}

void Zoo::buy_animals() {
	string type, buy;
	int num;
	cout << "Would you like to buy any animals this week? (Y/N): ";
	cin >> buy;

	if(buy == "Y") {
		cout << "Which type of animal would you like to buy? (monkey/meerkat/sea_otter): ";
		cin >> type;

		if(type == "monkey") {
			cout << "How many monkeys would you like to buy? (1/2): ";
			cin >> num;

			Monkey *monk_temp = new Monkey[num];
			for(int i = 0; i < num; i++) {
				string m_name;
				cout << "What do you want to name your monkey?: ";
				cin >> m_name;
				monk_temp[i] = Monkey(m_name);
				monk_temp[i].set_age(52);
				bank -= monk_temp[i].get_cost();
			}
			cout << "Total spent on monkeys: $" << monk_temp[0].get_cost() * num << endl;
			num_monkeys += num;
			update_monk(monk_temp, num);
		}
		if(type == "meerkat") {	
			cout << "How many meerkats would you like to buy? (1/2): ";
			cin >> num;

			Meerkat *meer_temp = new Meerkat[num];
			for(int i = 0; i < num; i++) {
				string k_name;
				cout << "What do you want to name your meerkat?: ";
				cin >> k_name;
				meer_temp[i] = Meerkat(k_name);
				meer_temp[i].set_age(52);
				bank -= meer_temp[i].get_cost();
			}
			cout << "Total spent on meerkats: $" << meer_temp[0].get_cost() * num << endl;
			num_meerkats += num;
			update_kats(meer_temp, num);
		}
		if(type == "sea_otter") {	
			cout << "How many sea otters would you like to buy? (1/2): ";
			cin >> num;

			Seaotter *sea_temp = new Seaotter[num];
			for(int i = 0; i < num; i++) {
				string s_name;
				cout << "What do you want to name your sea otter?: ";
				cin >> s_name;
				sea_temp[i] = Seaotter(s_name);
				sea_temp[i].set_age(52);
				bank -= sea_temp[i].get_cost();
			}
			cout << "Total spent on sea otters: $" << sea_temp[0].get_cost() * num << endl;
			num_seaotters += num;
			update_otts(sea_temp, num);
		}
	}
	num_animals = num_monkeys + num_meerkats + num_seaotters;
}

void Zoo::buy_feed() {
	srand(time(NULL));

	num_animals = num_monkeys + num_meerkats + num_seaotters;

	cout << "You need to buy feed for your current animals!" << endl;
	
	int feed_cost = 0;
	if(week_num == 0) {
		feed_cost = num_animals * 40;
	}
	else {
		feed_cost = num_animals * ((40 * 0.913) + 40);
	}

	bank -= feed_cost;
	
	cout << "Cost for feed: $" << feed_cost << endl;
	cout << "After buying feed for all of your current animals, you have $" << bank << " in the bank!" << endl;
	cout << endl;
}

void Zoo::adult_baby_animals() {
	num_adults = 0;
	num_babies = 0;
	for(int i = 0; i < num_monkeys; i++) {
		if(monk[i].get_age() <= 5) {
			num_babies += 1;
		}
		if(monk[i].get_age() >= 52) {
			num_adults += 1;
		}
	}
	for(int i = 0; i < num_meerkats; i++) {
		if(kats[i].get_age() <= 5) {
			num_babies += 1;
		}
		if(kats[i].get_age() >= 52) {
			num_adults += 1;
		}
	}
	for(int i = 0; i < num_seaotters; i++) {
		if(otts[i].get_age() <= 5) {
			num_babies += 1;
		}
		if(otts[i].get_age() >= 52) {
			num_adults += 1;
		}
	}
}

void Zoo::display() {
	num_animals = num_monkeys + num_meerkats + num_seaotters;
	adult_baby_animals();
	cout << "You currently have " << num_animals << " total animals; specifically " << num_monkeys << " monkeys, " << num_meerkats << " meerkats, and " << num_seaotters << " sea otters." << endl;
	cout << "You currently have " << num_adults << " adult animals, " << num_babies << " baby animals, and " << num_animals - (num_adults + num_babies) << " adolescent animals." << endl;
	cout << "Your bank account currently reads: $" << bank << endl;
	cout << "-------------------------------------------------------------" << endl;
	week_num++;
}

Zoo::~Zoo() {
	if(monk != NULL) {
		delete [] monk;
		monk = NULL;
	}
	if(kats != NULL) {
		delete [] kats;
		kats = NULL;
	}
	if(otts != NULL) {
		delete [] otts;
		otts = NULL;
	}
}
