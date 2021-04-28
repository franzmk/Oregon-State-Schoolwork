/*
** Program Filename: word_freq.cpp
** Author: 
** Date: 3/3/19
** Description: This program takes a sentence or a paragraph as an input, then asks for how ever many words you're going to search for in that sentence or paragraph, then takes the input for the words you're searching for, then outputs the number of times that search word is in the sentence or paragraph.
** Input: Sentence/paragraph, number of search words, search words
** Output: Number of times each search word appears in the sentence/paragraph
*********************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;

/*********************************************************************
 * ** Function: get_sentence
 * ** Description: This function takes a sentence or paragraph as an input
 * ** Parameters: char* words
 * ** Pre-Conditions: words was initialized on the heap in main
 * ** Post-Conditions: user enters a sentence or paragraph
 * *********************************************************************/ 

void get_sentence(char* words) {
	cout << "Enter a sentence or paragraph: ";
	
	cin.clear();
	cin.getline(words, 256);
}

/*********************************************************************
 * ** Function: compare
 * ** Description: this function compares every word in the words array to the search word and outputs the number of times they match
 * ** Parameters: char* words, string search_word, int num_words
 * ** Pre-Conditions: all of those variables have contents and ompare is called
 * ** Post-Conditions: times is output
 * *********************************************************************/ 

int compare(char* words, string search_word, int num_words) {
	int times = 0, spaces = 0;
	char* start = words; //start now holds words and is at the first character location in memory
	char const * searchWord = search_word.c_str(); //assigns searchWord as a constant char to hold search_word after being typed to a c-string
	char* temp = new char[256];
	char* end;
	for(int i = 0; i < strlen(words); i++) { //loops through the length of words to find how many spaces there are
		if(words[i] == ' ') {
			spaces++;
		}
	}

	//All words before last word
	for(int j = 0; j < spaces; j++) { //loops spaces number of times and then one time extra for the last word
		end = strchr(start, ' '); //sets and to the first space, and is set to the next space every time for loop runs
		strncpy(temp, start, end-start); //temp is set to whatever characters are between end and start
		if(!strcmp(temp, searchWord)) { //if the characters of temp and searchWord are equal, times increases by 1
			times++;
		}
		start = end + 1; //start is set to the next spot in memory
		memset(temp, '\0', 256); //temp is reset to hold the null terminator as the last character
	}

	//Last word check
	strncpy(temp, end + 1, words + (int)strlen(words) - end); //this copies the very last word in the char array words to temp
	if(!strcmp(temp, searchWord)) { //same comparison as above
		times++;
	}

	delete [] temp;

	return times; //times is returned
}

/*********************************************************************
 * ** Function: to_lower
 * ** Description: this function takes char* words as a parameter and turns all characters to their lower case equivalent or a space if they aren't between a-z
 * ** Parameters: char* words
 * ** Pre-Conditions: words has something in it and the function is called in main
 * ** Post-Conditions: words is now all lower case
 * *********************************************************************/ 

void to_lower(char* words) {
	for (int i = 0; i < strlen(words); i++) {
		words[i] = tolower(words[i]); //if the character in words is uppercase, it is set to lowercase
		if(words[i] < 'a' || words[i] > 'z') //if the character at spot i isn't a letter, it gets set to a space
			words[i] = ' ';
	}
}

/*********************************************************************
 * ** Function: search_sentence
 * ** Description: this function takes words as a parameter and asks for how many search words you want and then the search words you want and calls compare for however many search words there are and prints how many times each search word appears
 * ** Parameters: char* words
 * ** Pre-Conditions: words has something in it and search_sentence is called
 * ** Post-Conditions: program works
 * *********************************************************************/ 

void search_sentence(char* words) {
	int num_words = 0;
	string input;
	cout << "How many words are you searching for?: ";
	cin >> num_words; //number of search words
	cin.ignore();

	string* search_words = new string[num_words]; //static string array allocated on the heap

	cout << endl;
	for (int i = 0; i < num_words; i++) { //fills the search_word[i] to whatever search word you want
		cout << "Enter search word number " << i+1 << ": ";
		getline(cin, search_words[i]);
	}

	cout << endl;
	for(int i = 0; i < num_words; i++) { //runs num_words times
		cout << "The word '" << search_words[i] << "' appears " << compare(words, search_words[i], num_words) << " time(s)." << endl;
	}

	delete [] search_words;
}

/*********************************************************************
 * ** Function: main
 * ** Description: calls all functions and creates words array
 * ** Parameters: N/a
 * ** Pre-Conditions: none
 * ** Post-Conditions: program works
 * *********************************************************************/ 

int main() {
	char* words = new char[256];

	get_sentence(words);

	to_lower(words);

	search_sentence(words);

	delete [] words;

	return 0;
}
