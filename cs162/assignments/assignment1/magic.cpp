/*Program Filename: magic.cpp
 * Author: Max
 * Date: 4/12/19
 * Description: This is the function file for the magic program. It holds every necessary function and runs them accordingly when called. It does all the sorting and logging in and spellbook creating and such.
 * Input: N/a
 * Output: N/a
 */

#include "magic.h"

using namespace std;

/*********************************************************************
 * ** Function: check_num_args
 * ** Description: This function checks to make sure there are two command line arguments given when executing
 * ** Parameters: int argc
 * ** Pre-Conditions: Program has been executed
 * ** Post-Conditions: Rest of program runs
 * *********************************************************************/

void check_num_args(int argc) {
	if(argc != 3) {
		cout << "You must enter two command line arguments!" << endl;
		exit(0);
	}
}

/*********************************************************************
 * ** Function: check_files
 * ** Description: This function checks to make sure the two file names given as command line arguments actually exist and can be opened.
 * ** Parameters: char** argv, string &file1, string &file2
 * ** Pre-Conditions: Two command line arguments given
 * ** Post-Conditions: Files open
 * *********************************************************************/

void check_files(char** argv, string &file1, string &file2) {
	file1 = argv[1];
	file2 = argv[2];
	
	ifstream f1;
	f1.open(file1.c_str(), ios::in);
	ifstream f2;
	f2.open(file2.c_str(), ios::in);
	if(f1.is_open() && f2.is_open()) {
		cout << "Files successfully loaded!" << endl;
		f1.close();
		f2.close();
	}
	else {
		cout << "One or more files don't exist or opened incorrectly!" << endl;
		f1.close();
		f2.close();
		exit(0);
	}
}

/*********************************************************************
 * ** Function: create_wiz
 * ** Description: This function creates the array full of all of the wizards given in the wizards.txt file
 * ** Parameters: string file1, int &num_wizards
 * ** Pre-Conditions: Correct wizards.txt file is given in correct format
 * ** Post-Conditions: wiz is filled with wizards
 * *********************************************************************/

wizard * create_wiz(string file1, int &num_wizards) {
	string num_w;
	ifstream f1;

	do {
		f1.open(file1.c_str(), ios::in);
	} while(!f1.is_open());

	getline(f1, num_w);
	num_wizards = atoi(num_w.c_str());

	wizard *wiz = new wizard[num_wizards];

	for(int i = 0; i < num_wizards; i++) {
		f1 >> wiz[i].name >> wiz[i].id >> wiz[i].password >> wiz[i].position_title >> wiz[i].beard_length;
	}

	f1.close();

	return wiz;
}

/*********************************************************************
 * ** Function: check_id
 * ** Description: This function checks to make sure that the user ID input by the user is all integers, if not it asks again
 * ** Parameters: string login
 * ** Pre-Conditions: login is given
 * ** Post-Conditions: Loding ID is ints or not ints
 * *********************************************************************/

bool check_id(string login) {
	for(int i = 0; i < login.size(); i++) {
		if (!(login.at(i) >= '0' && login.at(i) <= '9')) {
			cout << "Login ID must be only integers!" << endl;
			return false;
		}
	}
	return true;
}

/*********************************************************************
 * ** Function: login_details
 * ** Description: This function takes two inputs of the user ID and the user password
 * ** Parameters: int &login_id, string &password
 * ** Pre-Conditions: login ID is ints and given and password is given
 * ** Post-Conditions: credentials that foloow the correct format are given
 * *********************************************************************/

void login_details(int &login_id, string &password) {
	string login;
	do {
		cout << "Please enter your Login ID: ";
		getline(cin, login);
		cout << "Please enter your Password: ";
		getline(cin, password);
	} while(!check_id(login));
	
	login_id = atoi(login.c_str());
}

/*********************************************************************
 * ** Function: check_login
 * ** Description: This function checks the credentials given by the user against all of the credentials in the wizard.txt file
 * ** Parameters: int login_id, string password, wizard *wiz, int num_wizards, int &wiz_index
 * ** Pre-Conditions: valid credentials are given and wiz array is full of correct wizards
 * ** Post-Conditions: user logged in or not
 * *********************************************************************/

void check_login(int login_id, string password, wizard *wiz, int num_wizards, int &wiz_index) {
	bool logged_in = false;

	for(int i = 0; i < num_wizards; i++) {
		if(login_id == wiz[i].id && password == wiz[i].password) {
			cout << "You have successfully logged in!" << endl;
			logged_in = true;
			wiz_index = i;
			break;
		}
	}

	if(logged_in == false) {
		cout << "Password or Login ID incorrect!" << endl;
		login_details(login_id, password);
		check_login(login_id, password, wiz, num_wizards, wiz_index);
	}
}

/*********************************************************************
 * ** Function: print_wiz
 * ** Description: This function prints the information about the wizard or user who has logged in correctly
 * ** Parameters: wizard *wiz, int wiz_index
 * ** Pre-Conditions: user has successfully logged in
 * ** Post-Conditions: all information printed out correctly, move to sorting
 * *********************************************************************/

void print_wiz(wizard *wiz, int wiz_index) {
	cout << endl;
	cout << "Welcome " << wiz[wiz_index].name << endl;
	cout << "ID: " << wiz[wiz_index].id << endl;
	cout << "Status: " << wiz[wiz_index].position_title << endl;
	cout << "Beard Length: " << wiz[wiz_index].beard_length << endl;
}

/*********************************************************************
 * ** Function: login
 * ** Description: This is the main login function, calls all of the necessary functions to get the user properly logged in
 * ** Parameters: string file1, wizard **wiz, int &wiz_index, int &num_wizards
 * ** Pre-Conditions: program is executed correctly
 * ** Post-Conditions: user is logged in successfully
 * *********************************************************************/

void login(string file1, wizard **wiz, int &wiz_index, int &num_wizards) {
	int login_id;
	string password;
	
	wizard *wizard = create_wiz(file1, num_wizards);

	*wiz = wizard;

	login_details(login_id, password);
	
	check_login(login_id, password, *wiz, num_wizards, wiz_index);

	print_wiz(*wiz, wiz_index);
}

/*********************************************************************
 * ** Function: choose
 * ** Description: This function is the choosing functionality of the sorting system further below
 * ** Parameters: N/a
 * ** Pre-Conditions: User has logged in and is about to sort spells
 * ** Post-Conditions: Choice is given to main sorting function
 * *********************************************************************/

int choose() {
	int choice = 4;
	cout << endl;
	cout << "Which option would you like to choose?" << endl;
	cout << "Sort spellbooks by number of pages (Press 1)" << endl;
	cout << "Group spells by their effect (Press 2)" << endl;
	cout << "Sort spellbooks by average success rate (Press 3)" << endl;
	cout << "Quit (Press 4)" << endl;
	cin >> choice;
	
	return choice;

}

/*********************************************************************
 * ** Function: create_spells
 * ** Description: This function creates the arrays for the spells within each spellbook in the spellbooks.txt file
 * ** Parameters: int num_spells
 * ** Pre-Conditions: spellbooks are being created and about to sort
 * ** Post-Conditions: spell arrays created
 * *********************************************************************/

spell * create_spells(int num_spells) {
	spell *spells = new spell[num_spells];
	return spells;
}

/*********************************************************************
 * ** Function: get_spell_data
 * ** Description: This function fills each spell array within each spellbook struct within the spellbook array
 * ** Parameters: spell *s, int num_spells, ifstream &f2
 * ** Pre-Conditions: spell arrays are created
 * ** Post-Conditions: spell arrays are filled
 * *********************************************************************/

void get_spell_data(spell *s, int num_spells, ifstream &f2) {
	for(int i = 0; i < num_spells; i++) {
		f2 >> s[i].name >> s[i].success_rate >> s[i].effect;
	}
}

/*********************************************************************
 * ** Function: get_spellbook_data
 * ** Description: This function creates the spellbook array and fills it with all the necessary information
 * ** Parameters: spellbook *spells, int num_books, ifstream &f2
 * ** Pre-Conditions: user is about to sort spells/spellbooks
 * ** Post-Conditions: spellbook array filled correctly
 * *********************************************************************/

void get_spellbook_data(spellbook *spells, int num_books, ifstream &f2) {
	float sr = 0, avg_sr = 0;
	for(int i = 0; i < num_books; i++) {
		sr = 0;
		f2 >> spells[i].title >> spells[i].author >> spells[i].num_pages >> spells[i].edition >> spells[i].num_spells;
		spells[i].s = create_spells(spells[i].num_spells);
		get_spell_data(spells[i].s, spells[i].num_spells, f2);
		for(int j = 0; j < spells[i].num_spells; j++) {
			sr += spells[i].s[j].success_rate;
		}
		avg_sr = sr / float(spells[i].num_spells);
		spells[i].avg_success_rate = avg_sr;
	}
}

/*********************************************************************
 * ** Function: print_or_file_page
 * ** Description: This function gives the user the option to print information to the screen or to save it to a file
 * ** Parameters: spellbook *temp, int num_books
 * ** Pre-Conditions: user has selected to sort the books by number of pages
 * ** Post-Conditions: books are correctly printed or saved to a file
 * *********************************************************************/

void print_or_file_page(spellbook *temp, int num_books) {
	int choice = 1;
	cout << endl;
	cout << "How would you like the information recorded?" << endl;
	cout << "Print to screen (Press 1)" << endl;
	cout << "Print to file (Press 2)" << endl;
	cin >> choice;

	if(choice == 1) {
		cout << endl;
		for(int i = 0; i < num_books; i++) {
			cout << temp[i].title << " " << temp[i].num_pages << endl;
		}
	}
	else {
		string file_name;
		cout << "Name of file: ";
		cin >> file_name;
		ofstream fout;
		do {
			fout.open(file_name.c_str(), ios::out | ios::trunc);
		} while(!fout.is_open());
		for(int i = 0; i < num_books; i++) {
			fout << temp[i].title << " " << temp[i].num_pages << endl;
		}
		cout << "File successfully created!" << endl;
		fout.close();
	}
}

/*********************************************************************
 * ** Function: print_or_file_effect
 * ** Description: This function will print to screen or save to file an array of spells that have been sorted according to the users' status.
 * ** Parameters: spellbook *temp, int num_books
 * ** Pre-Conditions: user selected to print/save spells by effect
 * ** Post-Conditions: spells are printed/saved in order of effect
 * *********************************************************************/

void print_or_file_effect(spellbook *temp, int num_books) {
	int choice = 1;
	cout << endl;
	cout << "How would you like the information recorded?" << endl;
	cout << "Print to screen (Press 1)" << endl;
	cout << "Print to file (Press 2)" << endl;
	cin >> choice;

	if(choice == 1) {
		cout << endl;
		for(int i = 0; i < num_books; i++) {
			for(int j = 0; j < temp[i].num_spells; j++) {
				cout << temp[i].s[j].effect << " " << temp[i].s[j].name << endl;
			}
		}
	}
	else {
		string file_name;
		cout << "Name of file: ";
		cin >> file_name;
		ofstream fout;
		do {
			fout.open(file_name.c_str(), ios::out | ios::trunc);
		} while(!fout.is_open());
		for(int i = 0; i < num_books; i++) {
			for(int j = 0; j < temp[i].num_spells; j++) {
				fout << temp[i].s[j].effect << " " << temp[i].s[j].name << endl;
			}
		}
		cout << "File successfully created!" << endl;
		fout.close();
	}
}

/*********************************************************************
 * ** Function: print_or_file_sr
 * ** Description: This function will ask the user to print/save the order of spellbooks based on average success rate.
 * ** Parameters: spellbook *temp, int num_books
 * ** Pre-Conditions: the user selected to print/save spellbooks in average success rate order
 * ** Post-Conditions: spellbooks are printed/saved in average success rate order
 * *********************************************************************/

void print_or_file_sr(spellbook *temp, int num_books) {
	int choice = 1;
	cout << endl;
	cout << "How would you like the information recorded?" << endl;
	cout << "Print to screen (Press 1)" << endl;
	cout << "Print to file (Press 2)" << endl;
	cin >> choice;

	if(choice == 1) {
		cout << endl;
		for(int i = 0; i < num_books; i++) {
			cout << temp[i].title << " " << temp[i].avg_success_rate << endl;
		}
	}
	else {
		string file_name;
		cout << "Name of file: ";
		cin >> file_name;
		ofstream fout;
		do {
			fout.open(file_name.c_str(), ios::out | ios::trunc);
		} while(!fout.is_open());
		for(int i = 0; i < num_books; i++) {
			fout << temp[i].title << " " << temp[i].avg_success_rate << endl;
		}
		cout << "File successfully created!" << endl;
		fout.close();
	}
}

/*********************************************************************
 * ** Function: page_sort
 * ** Description: This function sorts the spellbooks in order of number of pages
 * ** Parameters: wizard *wiz, int wiz_index, spellbook *spells, int num_books
 * ** Pre-Conditions: user selected to sort the spellbooks by page number
 * ** Post-Conditions: user is prompted to print sorted spellbooks to screen or to save them
 * *********************************************************************/

void page_sort(wizard *wiz, int wiz_index, spellbook *spells, int num_books) {
	spellbook *page = spells;
	for(int i = 0; i < num_books; i++) {
		for(int j = 0; j < num_books - 1; j++) {
			if(page[j].num_pages > page[j+1].num_pages) {
				spellbook temp = page[j];
				page[j] = page[j+1];
				page[j+1] = temp;
			}
		}
	}

	print_or_file_page(page, num_books);
}

/*********************************************************************
 * ** Function: create_temp_list
 * ** Description: This function creates a temprorary list of all spells used for sorting
 * ** Parameters: int numb_spells, spellbook *spells, int num_books
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: list of all spells created
 * *********************************************************************/

spell * create_temp_list(int numb_spells, spellbook *spells, int num_books) {
	int index = 0;
	spell *spell_list_temp = new spell[numb_spells];

	for(int i = 0; i < num_books; i++) {
		for(int j = 0; j < spells[i].num_spells; j++) {
			spell_list_temp[index] = spells[i].s[j];
			index++;
		}
	}

	return spell_list_temp;
}

/*********************************************************************
 * ** Function: count_temp_list
 * ** Description: This function counts however many of each spell effect there are in the list of all spells
 * ** Parameters: int numb_spells, spell *spell_list_temp, int &bubbles, int &memory_losses, int &fires, int &poisons, int &deaths
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: correct number of each spell effect recorded
 * *********************************************************************/

void count_temp_list(int numb_spells, spell *spell_list_temp, int &bubbles, int &memory_losses, int &fires, int &poisons, int &deaths) {
	for(int i = 0; i < numb_spells; i++) {
		if(spell_list_temp[i].effect == "bubble") {
			bubbles++;
		}
		if(spell_list_temp[i].effect == "memory_loss") {
			memory_losses++;
		}
		if(spell_list_temp[i].effect == "fire") {
			fires++;
		}
		if(spell_list_temp[i].effect == "poison") {
			poisons++;
		}
		if(spell_list_temp[i].effect == "death") {
			deaths++;
		}
	}
}

/*********************************************************************
 * ** Function: create_bubble
 * ** Description: This function creates an array of spells and holds all of the spells under the bubble effect
 * ** Parameters: int bubbles, spell *spell_list_temp, int numb_spells
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: adds all bubble spells to the bubble array
 * *********************************************************************/

spell * create_bubble(int bubbles, spell *spell_list_temp, int numb_spells) {
	spell *bubble = new spell[bubbles];

	int index2 = 0;
	for(int i = 0; i < numb_spells; i++) {
		if(spell_list_temp[i].effect == "bubble") {
			bubble[index2] = spell_list_temp[i];
			index2++;
		}
	}

	return bubble;
}

/*********************************************************************
 * ** Function: create_memory_loss
 * ** Description: This function creates an array of spells and holds all of the spells under the memory loss effect
 * ** Parameters: int memory_losses, spell *spell_list_temp, int numb_spells
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: adds all memory loss spells to the memory loss array
 * *********************************************************************/

spell * create_memory_loss(int memory_losses, spell *spell_list_temp, int numb_spells) {
	spell *memory_loss = new spell[memory_losses];

	int index2 = 0;
	for(int i = 0; i < numb_spells; i++) {
		if(spell_list_temp[i].effect == "memory_loss") {
			memory_loss[index2] = spell_list_temp[i];
			index2++;
		}
	}

	return memory_loss;
}

/*********************************************************************
 * ** Function: create_fire
 * ** Description: This function creates an array of spells and holds all of the spells under the fire effect
 * ** Parameters: int fires, spell *spell_list_temp, int numb_spells
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: adds all fire spells to the fire array
 * *********************************************************************/

spell * create_fire(int fires, spell *spell_list_temp, int numb_spells) {
	spell *fire = new spell[fires];

	int index2 = 0;
	for(int i = 0; i < numb_spells; i++) {
		if(spell_list_temp[i].effect == "fire") {
			fire[index2] = spell_list_temp[i];
			index2++;
		}
	}

	return fire;
}

/*********************************************************************
 * ** Function: create_poison
 * ** Description: This function creates an array of spells and holds all of the spells under the poison effect
 * ** Parameters: int poisons, spell *spell_list_temp, int numb_spells
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: adds all poison spells to the poison array
 * *********************************************************************/

spell * create_poison(int poisons, spell *spell_list_temp, int numb_spells) {
	spell *poison = new spell[poisons];

	int index2 = 0;
	for(int i = 0; i < numb_spells; i++) {
		if(spell_list_temp[i].effect == "poison") {
			poison[index2] = spell_list_temp[i];
			index2++;
		}
	}

	return poison;
}

/*********************************************************************
 * ** Function: create_death
 * ** Description: This function creates an array of spells and holds all of the spells under the death effect
 * ** Parameters: int deaths, spell *spell_list_temp, int numb_spells
 * ** Pre-Conditions: user has logged in and begun sorting
 * ** Post-Conditions: adds all death spells to the death array
 * *********************************************************************/

spell * create_death(int deaths, spell *spell_list_temp, int numb_spells) {
	spell *death = new spell[deaths];

	int index2 = 0;
	for(int i = 0; i < numb_spells; i++) {
		if(spell_list_temp[i].effect == "death") {
			death[index2] = spell_list_temp[i];
			index2++;
		}
	}

	return death;
}

/*********************************************************************
 * ** Function: print_or_file_effect_student
 * ** Description: This function creates the correct array based on if the user is a student or not and then gives the user the option to print or save the outcome
 * ** Parameters: int numb_spells, int poisons, int bubbles, int memory_losses, int fires, spell *bubble, spell *memory_loss, spell *fire
 * ** Pre-Conditions: user has selected to sort by effect and is a student
 * ** Post-Conditions: prints or saves outcome correctly
 * *********************************************************************/

void print_or_file_effect_student(int numb_spells, int poisons, int deaths, int bubbles, int memory_losses, int fires, spell *bubble, spell *memory_loss, spell *fire) {
	int choice = 1;
	cout << endl;
	cout << "How would you like the information recorded?" << endl;
	cout << "Print to screen (Press 1)" << endl;
	cout << "Print to file (Press 2)" << endl;
	cin >> choice;	

	int num = numb_spells - (poisons + deaths);
	spell *temp = new spell[num];
	int index3 = 0;
	for(int i = 0; i < bubbles; i++) {
		temp[index3] = bubble[i];
		index3++;
	}
	for(int i = 0; i < memory_losses; i++) {
		temp[index3] = memory_loss[i];
		index3++;
	}
	for(int i = 0; i < fires; i++) {
		temp[index3] = fire[i];
		index3++;
	}	

	if(choice == 1) {
		cout << endl;
		for(int i = 0; i < num; i++) {
			cout << temp[i].effect << " " << temp[i].name << endl;
		}
	}
	else {
		string file_name;
		cout << "Name of file: ";
		cin >> file_name;
		ofstream fout;
		do {
			fout.open(file_name.c_str(), ios::out | ios::trunc);
		} while(!fout.is_open());
		for(int i = 0; i < num; i++) {
			fout << temp[i].effect << " " << temp[i].name << endl;
		}
		cout << "File successfully created!" << endl;
		fout.close();
	}

	delete [] temp;
	temp = NULL;
}

/*********************************************************************
 * ** Function: print_or_file_effect_not_student
 * ** Description: This function creates an array of spells based on if the user is not a student and then prints/saves the outcome correctly
 * ** Parameters: int numb_spells, int bubbles, int memory_losses, int fires, int poisons, int deaths, spell *bubble, spell *memory_loss, spell *fire, spell *poison, spell *death
 * ** Pre-Conditions: user has selected to sort by effect
 * ** Post-Conditions: outcome is printed/saved correctly
 * *********************************************************************/

void print_or_file_effect_not_student(int numb_spells, int bubbles, int memory_losses, int fires, int poisons, int deaths, spell *bubble, spell *memory_loss, spell *fire, spell *poison, spell *death) {
	int choice = 1;
	cout << endl;
	cout << "How would you like the information recorded?" << endl;
	cout << "Print to screen (Press 1)" << endl;
	cout << "Print to file (Press 2)" << endl;
	cin >> choice;

	spell *temp = new spell[numb_spells];
	int index3 = 0;
	for(int i = 0; i < bubbles; i++) {
		temp[index3] = bubble[i];
		index3++;
	}
	for(int i = 0; i < memory_losses; i++) {
		temp[index3] = memory_loss[i];
		index3++;
	}
	for(int i = 0; i < fires; i++) {
		temp[index3] = fire[i];
		index3++;
	}
	for(int i = 0; i < poisons; i++) {
		temp[index3] = poison[i];
		index3++;
	}
	for(int i = 0; i < deaths; i++) {
		temp[index3] = death[i];
		index3++;
	}

	if (choice == 1) {
		cout << endl;
		for(int i = 0; i < numb_spells; i++) {
			cout << temp[i].effect << " " << temp[i].name << endl;
		}
	}
	else {
		string file_name;
		cout << "Name of file: ";
		cin >> file_name;
		ofstream fout;
		do {
			fout.open(file_name.c_str(), ios::out | ios::trunc);
		} while(!fout.is_open());
		for(int i = 0; i < numb_spells; i++) {
			fout << temp[i].effect << " " << temp[i].name << endl;
		}
		cout << "File successfully created!" << endl;
		fout.close();
	}

	delete [] temp;
	temp = NULL;
}

/*********************************************************************
 * ** Function: delete_lists
 * ** Description: This function deletes all of the temporary lists used to sort the spells by effect if the user chooses it
 * ** Parameters: spell *spell_list_temp, spell *bubble, spell *memory_loss, spell *fire, spell *poison, spell *death
 * ** Pre-Conditions: user has chosen to sort by effect and program did so successfully
 * ** Post-Conditions: all lists deleted correctly
 * *********************************************************************/

void delete_lists(spell *spell_list_temp, spell *bubble, spell *memory_loss, spell *fire, spell *poison, spell *death) {
	delete [] spell_list_temp;
	delete [] bubble;
	delete [] memory_loss;
	delete [] fire;
	delete [] poison;
	delete [] death;
	spell_list_temp = NULL;
	bubble = NULL;
	memory_loss = NULL;
	fire = NULL;
	poison = NULL;
	death = NULL;
}

/*********************************************************************
 * ** Function: effect_sort
 * ** Description: This function is the driver function for when the user chooses to sort spells by effect, it runs the show
 * ** Parameters: wizard *wiz, int wiz_index, spellbook *spells, int num_books
 * ** Pre-Conditions: the user has logged in and has chosen to sort spells by effect
 * ** Post-Conditions: spells have been sorted by effect correctly and outcome was print3ed/saved correctly
 * *********************************************************************/

void effect_sort(wizard *wiz, int wiz_index, spellbook *spells, int num_books) {
	int numb_spells = 0, bubbles = 0, memory_losses = 0, fires = 0, poisons = 0, deaths = 0;

	for(int i = 0; i < num_books; i++) {
		numb_spells += spells[i].num_spells;
	}

	spell *spell_list_temp = create_temp_list(numb_spells, spells, num_books);

	count_temp_list(numb_spells, spell_list_temp, bubbles, memory_losses, fires, poisons, deaths);

	spell *bubble = create_bubble(bubbles, spell_list_temp, numb_spells);
	spell *memory_loss = create_memory_loss(memory_losses, spell_list_temp, numb_spells);
	spell *fire = create_fire(fires, spell_list_temp, numb_spells);
	spell *poison = create_poison(poisons, spell_list_temp, numb_spells);
	spell *death = create_death(deaths, spell_list_temp, numb_spells);
	
	if(wiz[wiz_index].position_title == "Student") {
		print_or_file_effect_student(numb_spells, poisons, deaths, bubbles, memory_losses, fires, bubble, memory_loss, fire);
	}
	else {
		print_or_file_effect_not_student(numb_spells, bubbles, memory_losses, fires, poisons, deaths, bubble, memory_loss, fire, poison, death);
	}

	delete_lists(spell_list_temp, bubble, memory_loss, fire, poison, death);
}

/*********************************************************************
 * ** Function: sr_sort
 * ** Description: This function sorts the spellbooks based on their average success rate
 * ** Parameters: wizard *wiz, int wiz_index, spellbook *spells, int num_books
 * ** Pre-Conditions: user has chosen to sort spellbooks by their average success rate
 * ** Post-Conditions: spells are sorted by average success rate and user is prompted to print/save the outcome
 * *********************************************************************/

void sr_sort(wizard *wiz, int wiz_index, spellbook *spells, int num_books) {
	spellbook *sr = spells;
	for(int i = 0; i < num_books; i++) {
		for(int j = 0; j < num_books - 1; j++) {
			if(sr[j].avg_success_rate < sr[j+1].avg_success_rate) {
				spellbook temp = sr[j];
				sr[j] = sr[j+1];
				sr[j+1] = temp;
			}
		}
	}

	print_or_file_sr(sr, num_books);
}

/*********************************************************************
 * ** Function: create_spellbooks
 * ** Description: This function creates an array for however many spellbooks their are
 * ** Parameters: int num_books
 * ** Pre-Conditions: user has logged in and is about to sort spells/spellbooks
 * ** Post-Conditions: array successfully create
 * *********************************************************************/

spellbook * create_spellbooks(int num_books) {
	spellbook *spells = new spellbook[num_books];
	return spells;
}

/*********************************************************************
 * ** Function: delete_info
 * ** Description: This function deletes all of the main arrays
 * ** Parameters: wizard *wiz, int num_wizards, spellbook *spells, int num_books
 * ** Pre-Conditions: the entire program has run correctly and the arrays need to be deleted now
 * ** Post-Conditions: arrays deleted
 * *********************************************************************/

void delete_info(wizard *wiz, int num_wizards, spellbook *spells, int num_books) {
	delete [] wiz;
	wiz = NULL;
	for(int i = 0; i < num_books; i++) {
		delete [] spells[i].s;
	}
	delete [] spells;
	spells = NULL;
}

/*********************************************************************
 * ** Function: sort_again
 * ** Description: This function prompts the user to choose which sorting option they want to do
 * ** Parameters: wizard *wiz, int wiz_index, int num_wizards, spellbook *spells, int num_books
 * ** Pre-Conditions: the user has logged in and is about to sort
 * ** Post-Conditions: user has selected an option 
 * *********************************************************************/

bool sort_again(wizard *wiz, int wiz_index, int num_wizards, spellbook *spells, int num_books) {
	int choice = choose();
	if(choice == 1) {
		page_sort(wiz, wiz_index, spells, num_books);
	}
	else if(choice == 2) {
		effect_sort(wiz, wiz_index, spells, num_books);
	}
	else if(choice == 3) {
		sr_sort(wiz, wiz_index, spells, num_books);
	}
	else {
		return false;
	}
	return true;
}

/*********************************************************************
 * ** Function: sort
 * ** Description: This function is the main function for sorting the spells/spellbooks
 * ** Parameters: wizard *wiz, int wiz_index, int num_wizards, string file2
 * ** Pre-Conditions: user has logged in
 * ** Post-Conditions: spellbooks/spells have been sorted
 * *********************************************************************/

void sort(wizard *wiz, int wiz_index, int num_wizards, string file2) {
	int num_books;
	bool x = true;
	string num_book;
	ifstream f2;
	do {
		f2.open(file2.c_str(), ios::in);
	} while(!f2.is_open());

	getline(f2, num_book);
	num_books = atoi(num_book.c_str());

	spellbook *spells = create_spellbooks(num_books);

	get_spellbook_data(spells, num_books, f2);

	f2.close();

	do {
		x = sort_again(wiz, wiz_index, num_wizards, spells, num_books);
	} while(x);

	delete_info(wiz, num_wizards, spells, num_books);
}
