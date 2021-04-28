#include <iostream>
#include <string>

using namespace std;

string get_sentence() {
	string sentence;

	cout << "Enter a sentence:" << endl;
	getline(cin, sentence);

	return sentence;
}

void get_sentence(string &s){
	cout << "Enter a sentence:" << endl;
	getline(cin, s);
}

int main() {
	string sentence;

//	sentence = get_sentence();
	get_sentence(sentence);
	cout << sentence << endl;

	return 0;
}
