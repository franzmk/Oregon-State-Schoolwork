#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void get_string(string *input) {
	cout << "Enter a string: ";
	getline(cin, *input);
}

void set_replace_string(string &the_string, string *input) {
	for(int i = 0; i < the_string.length(); i++) {
		if(the_string[i] != ' ') {
			the_string[i] = '-';
		}
	}
}

int get_search_replace(string input, string &the_string) {
	char search = ' ';
	int times = 0;
	cout << "Enter a character to search for: ";
	cin >> search;
	for (int i = 0; i < input.length(); i++) {
		if(input[i] == search) {
			the_string[i] = search;
			times++;
		}
	}
	return times;
}

int main() {
	string *input = new string;
	get_string(input);
	string the_string = *input;
	set_replace_string(the_string, input);
	cout << "Characters replaced: " << get_search_replace(*input, the_string) << endl;
	cout << "Output: " << the_string << endl;
	delete input;

	return 0;
}
