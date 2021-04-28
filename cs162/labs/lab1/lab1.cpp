#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "./mult_div.h"

using namespace std;

void check_num_args(int argc) {
	if (argc != 3) {
		cout << "You must enter two command line arguments!" << endl;
		exit(1);
	}
}

void check_vals(int &rows, int &cols) {
	if (rows == 0 || cols == 0) {
		cout << "One of your command line arguments is invalid!" << endl;
		cout << "Please re-enter them here!" << endl;
		cout << endl;
		cout << "Number of rows?: ";
		cin >> rows;
		cout << "Number of columns?: ";
		cin >> cols;
		check_vals(rows, cols);
	}
}

mult_div_values** create_table(int m, int n) {
	mult_div_values** table = new mult_div_values*[m];
	for (int i = 0; i < m; i++) {
		table[i] = new mult_div_values[n];
	}

	return table;
}

void set_mult_values(mult_div_values **table, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			table[i][j].mult = (i + 1) * (j + 1);
		}
	}
}

void set_div_values(mult_div_values **table, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			table[i][j].div = float((float(i) + 1.00)) / float((float(j) + 1.00));
		}
	}
}

void delete_table(mult_div_values **table, int m) {
	for(int i = 0; i < m; i++) {
		delete [] table[i];
	}
	delete [] table;
}

void print(mult_div_values **table, int m, int n) {
	cout << endl;
	cout << "Multiplication Table:" << endl;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << setw(4) << table[i][j].mult << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Division Table:" << endl;

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << setw(5) << setprecision(2) << fixed << table[i][j].div << " ";
		}
		cout << endl;
	}
	again();
}

void go() {
	int rows = 0, cols = 0;
	cout << "Number of rows?: ";
	cin >> rows;
	cout << "Number of columns?: ";
	cin >> cols;

	check_vals(rows, cols);

	mult_div_values **table = create_table(rows, cols);

	set_mult_values(table, rows, cols);

	set_div_values(table, rows, cols);

	print(table, rows, cols);

	delete_table(table, rows);
}

void again() {
	int choice = 0;
	cout << endl;
	cout << "Do you want to calculate another matrix?: (1 = yes / 2 = no) ";
	cin >> choice;

	if(choice == 1) {
		go();
	}
	else exit(1);
}
