/*
 * Program Filename: magic.h
 * Author: Max
 * Date: 4/12/19
 * Description: This header file contains all of the structs and function prototypes used in the magic.cpp and main.cpp files
 * Input: N/a
 * Output: N/a
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <typeinfo>

using namespace std;

//structs
struct wizard {
	string name;
	int id;
	string password;
        string position_title; 
	float beard_length;
};
struct spellbook {
	string title;
	string author;
	int num_pages;
        int edition;
	int num_spells;
	float avg_success_rate;
	struct spell *s;
};
struct spell {
	string name;
	float success_rate;
	string effect; 
};

//function prototypes
spellbook * create_spellbooks(int);
void get_spellbook_data(spellbook *, int, std::ifstream &); 
spell * create_spells(int);
void get_spell_data(spell *, int, std::ifstream &); 
void delete_info(wizard *, spellbook *, int);
void check_num_args(int);
void check_files(char**, string &, string &);
void login(string, wizard **, int &, int &);
bool check_id(string);
void login_details(int &, string &);
void check_login(int, string, wizard *, int, int &);
void print_wiz(wizard *, int);
void sort(wizard *, int, int, string);
wizard * create_wiz(string, int &);
void page_sort(wizard *, int, spellbook *);
void effect_sort(wizard *, int, spellbook *);
void sr_sort(wizard *, int, spellbook *);
