#include <iostream>
#include <string>

using namespace std;

int convert_r_to_d(char ch) {

	int value = 0;

	switch(ch){
		case 'I': value = 1; break;
		case 'V': value = 5; break;
		case 'X': value = 10; break;
		case 'L': value = 50; break;
		case 'C': value = 100; break;
		case 'D': value = 500; break;
		case 'M': value = 1000; break;
		default: value = -1;
	}
	
	return value;
}

int r_to_d(string roman_num) {

	int total = 0;

	for(int i = 0; i < roman_num.length(); i++) {
		if(convert_r_to_d(roman_num[i]) < convert_r_to_d(roman_num[i+1])){
			total = total - convert_r_to_d(roman_num[i]);
		}
		else {
			total = total + convert_r_to_d(roman_num[i]);
		}
	}
	return total;
}

string d_to_r(int num) {

	string numeral = "";

	while (num != 0) {

		if (num >= 1000) {
			num = num-1000;
			numeral += "M";
		}
		else if (num >= 900) {
			num = num-900;
			numeral += "CM";
		}
		else if (num >= 500) {
			num = num-500;
			numeral += "D";
		}
		else if (num >= 400) {
			num = num-400;
			numeral += "CD";
		}
		else if (num >= 100) {
			num = num-100;
			numeral += "C";
		}
		else if (num >= 90) {
			num = num-90;
			numeral += "XC";
		}
		else if (num >= 50) {
			num = num-50;
			numeral += "L";
		}
		else if (num >= 40) {
			num = num-40;
			numeral += "XL";
		}
		else if (num >= 10) {
			num = num-10;
			numeral += "X";
		}
		else if (num >= 9) {
			num = num-9;
			numeral += "IX";
		}
		else if (num >= 5) {
			num = num-5;
			numeral += "V";
		}
		else if (num >= 4) {
			num = num-4;
			numeral += "IV";
		}
		else {
			num = num-1;
			numeral += "I";
		}
	}

	return numeral;
}

int main() {

	string rn_input = "";
	int num_input = 0;
	int which;
start:
	cout << "Roman Numeral to Decimal (1) or Decimal to Roman Numeral (2)?: ";
	cin >> which;

	if (which == 1) {
		cout << endl;
		cout << "Enter a Roman Numeral: ";
		cin >> rn_input;

		cout << endl;
		cout << "Conversion: " << r_to_d(rn_input) << endl;
	}

	else if (which == 2) {
		cout << endl;
		cout << "Enter a Decimal Number: ";
		cin >> num_input;

		cout << endl;
		cout << "Conversion: " << d_to_r(num_input) << endl;
	}

	else {
		cout << endl;
		cout << "Enter 1 or 2!" << endl;
		goto start;
	}

	return 0;
}
