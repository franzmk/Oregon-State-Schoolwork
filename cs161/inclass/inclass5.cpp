#include <iostream>
#include <string>

using namespace std;

int main() {

	int i;
	float f;
	string s;
	bool error;

	do {
		error = false;
		cout << "Integer: ";
	//	cin >> i;
		getline(cin, s);

		for(int i = 0; i< s.size(); i++) {
			if (!(s.at(i) >= '0' && s.at(i) <= '9')) {
				cout << "Error!" << endl;
				error = true;
				break;
			}
		}
	}while(error);

	//i = atoi(s.c_str());
	cout << i << endl;
	cout << "Float: ";
	cin >> f;
	cout << "float: " << f << endl;

	cout << "Name: ";
//	cin >> s;
	getline(cin, s);
	getline(cin, s);
	cout << "string length: " << s.length() << endl;
	cout << "first letter in name: " << s.at(0) << endl;

	return 0;
}
