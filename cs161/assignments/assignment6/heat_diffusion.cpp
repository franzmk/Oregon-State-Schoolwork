/*********************************************************************
 * ** Program Filename: heat_diffusion.cpp
 * ** Author: 
 * ** Date: 3/17/19
 * ** Description: diffuses heat over wire or plate
 * ** Input: k, rho, c, time, some temperatures, etc
 * ** Output: heat diffusing over wire or plate
 * *********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include "helper.hpp"

using namespace std;

/*********************************************************************
 * ** Function: stability_check_w
 * ** Description: checks the stability of the inputs for wire from user
 * ** Parameters: k, delta_t, delta_x, c, rho
 * ** Pre-Conditions: numbers are input by user
 * ** Post-Conditions: it works
 * *********************************************************************/ 

bool stability_check_w(float k, float delta_t, float delta_x, float c, float rho) {
	float stability = 0, top = 0, bot = 0;
	
	top = (k * delta_t);
	bot = pow(delta_x, 2.0) * c * rho;
	stability = abs(top/bot);
	
	if (stability < 0.5) return true;
	else return false;
	
}

/*********************************************************************
 * ** Function: input_wire
 * ** Description: takes inputs for the wire properties
 * ** Parameters: k, rho, c, init_temp, wire_length, sections, num_intervals
 * ** Pre-Conditions: program runs
 * ** Post-Conditions: numbers are placed
 * *********************************************************************/ 

void input_wire(float &k, float &rho, float &c, float &init_temp, float &wire_length, int &sections, int &num_intervals) {
	cout << "What is the thermal conductivity of your material?: ";
	cin >> k;

	cout << "What is the density of your material?: ";
	cin >> rho;
	
	cout << "What is the heat capacity of your material?: ";
	cin >> c;

	cout << "What is the initial temperature (in F)?: ";
	cin >> init_temp;

	cout << "What is the length of your wire?: ";
	cin >> wire_length;

	cout << "How many sections are there?: ";
	cin >> sections;

	cout << "How many time intervals?: ";
	cin >> num_intervals;
	cout << endl;
}

/*********************************************************************
 * ** Function: delta_wire
 * ** Description: calculates the delta variables for the wire
 * ** Parameters: wire_length, sections, delta_x, num_intervals, time_sim, delta_t
 * ** Pre-Conditions: program got to this point
 * ** Post-Conditions: deltas are calculated
 * *********************************************************************/ 

void delta_wire(float wire_length, int sections, float &delta_x, int num_intervals, float time_sim, float &delta_t) {
	
	delta_x = wire_length / (float)sections;

	delta_t = time_sim / (float)num_intervals;
}

/*********************************************************************
 * ** Function: print_w
 * ** Description: prints the wire as heat diffuses over it
 * ** Parameters: u[] and sections
 * ** Pre-Conditions: u[] has been calculated
 * ** Post-Conditions: prints u[]
 * *********************************************************************/

void print_w(float u[], int sections) {
	fileWriter fw("heat.dat");
	for(int i = 0; i < sections; i++) {
		fw << u[i];
		cout << setw(8) << u[i] << " ";
	}
	cout << endl;
}

/*********************************************************************
 * ** Function: calculate_wire
 * ** Description: calculates the values for the wire
 * ** Parameters: k, rho, c, init_temp, delta_x, delta_t, sections, num_intervals, l_temp, r_temp
 * ** Pre-Conditions: wire was selected
 * ** Post-Conditions: program runs
 * *********************************************************************/

void calculate_wire(float k, float rho, float c, float init_temp, float delta_x, float delta_t, int sections, int num_intervals, float l_temp, float r_temp) {
	float* u1 = new float[sections];
	float* u2 = new float[sections];
	for(int x = 0; x < sections; x++) {
		u1[x] = init_temp;
		u2[x] = init_temp;
	}
	u1[0] = l_temp;
	u1[sections-1] = r_temp;
	u2[0] = l_temp;
	u2[sections-1] = r_temp;
	for(int i = 0; i < num_intervals - 1; i++) {
		for(int j = 1; j < sections - 1; j++) {
			float top = (delta_t * k * (u1[j+1] - (2 * u1[j]) + u1[j-1]));
			float bot = (pow(delta_x, 2.0) * c * rho);
			float total = (top / bot) + u1[j];
			u2[j] = total;
		}
		for(int y = 0; y < sections; y++) {
			u1[y] = u2[y];
		}
		print_w(u2, sections);
		cout << endl;
	}
	delete [] u1;
	delete [] u2;
}

/*********************************************************************
 * ** Function: wire
 * ** Description: runs the whole program when wire is selected
 * ** Parameters: n/a
 * ** Pre-Conditions: wire is selected
 * ** Post-Conditions: program runs
 * *********************************************************************/

void wire() {
	float k = 0, rho = 0, c = 0, time_sim = 0.01675, init_temp = 0, wire_length = 0, delta_x = 0, delta_t = 0, l_temp = 0, r_temp = 100;;
	int sections = 0, num_intervals = 0;
	bool stable = false;

	input_wire(k, rho, c, init_temp, wire_length, sections, num_intervals);
	
	delta_wire(wire_length, sections, delta_x, num_intervals, time_sim, delta_t);

	stable = stability_check_w(k, delta_t, delta_x, c, rho);

	if(stable)
		calculate_wire(k, rho, c, init_temp, delta_x, delta_t, sections, num_intervals, l_temp, r_temp);

	else {
		cout << "Those numbers aren't stable!" << endl;
		cout << "Start over!" << endl;
		exit(1);
	}
}

/*********************************************************************
 * ** Function: input_plate
 * ** Description: takes the inputs for the plate
 * ** Parameters: k, rho, c, init_temp, plate_height, plate_width, sections, num_intervals
 * ** Pre-Conditions: plate was selected
 * ** Post-Conditions: inputs are recorded
 * *********************************************************************/

void input_plate(float &k, float &rho, float &c, float &init_temp, int &plate_height, int &plate_width, int &sections, int &num_intervals) {
	cout << "What is the thermal conductivity of your plate?: ";
	cin >> k;

	cout << "What is the density of your plate?: ";
	cin >> rho;
	
	cout << "What is the heat capacity of your plate?: ";
	cin >> c;

	cout << "What is the initial temperature (in F)?: ";
	cin >> init_temp;

	cout << "What is the height of your plate?: ";
	cin >> plate_height;

	cout << "What is the width of your plate?: ";
	cin >> plate_width;

	cout << "How many sections are there?: ";
	cin >> sections;

	cout << "How many time intervals?: ";
	cin >> num_intervals;
	cout << endl;
}

/*********************************************************************
 * ** Function: delta_plate
 * ** Description: the deltas for the plate are calculated
 * ** Parameters: plate_height, plate_width, sections, delta_x, delta_y, num_intervals, time_sim, delta_t
 * ** Pre-Conditions: all variables have content and is called
 * ** Post-Conditions: deltas are calculated
 * *********************************************************************/

void delta_plate(int plate_height, int plate_width, int sections, float &delta_x, float &delta_y, int num_intervals, float time_sim, float &delta_t) {
	delta_x = (float)plate_width / (float)sections;
	delta_y = delta_x;

	delta_t = time_sim / (float)num_intervals;
}

/*********************************************************************
 * ** Function: stability_check_p
 * ** Description: checks the stability for the inputs given for plate
 * ** Parameters: delta_t, delta_x, delta_y, k, rho, c
 * ** Pre-Conditions: program has run and inputs were collected
 * ** Post-Conditions: is or isn't stable
 * *********************************************************************/

bool stability_check_p(float delta_t, float delta_x, float delta_y, float k, float rho, float c) {
	float stability = 0, top = 0, bot = 0;

	top = delta_x * delta_y * rho * c;
	bot = 4.0 * k;
	stability = top / bot;

	if(delta_t <= stability) return true;
	else return false;
}

/*********************************************************************
 * ** Function: clear_plate
 * ** Description: deletes all arrays and frees memory
 * ** Parameters: u1, u2, sections
 * ** Pre-Conditions: plate has been calculated and program works
 * ** Post-Conditions: memory is freed
 * *********************************************************************/

void clear_plate(float** u1, float** u2, int sections) {
	for(int i = 0; i < sections; i++) {
		delete [] u1[i];
		delete [] u2[i];
	}
	delete [] u1;
	delete [] u2;
}

/*********************************************************************
 * ** Function: fill_plate
 * ** Description: plate arrays are filled with initial values
 * ** Parameters: u1, u2, init_temp, sections, lr_col_temp, tb_row_temp
 * ** Pre-Conditions: variables have contents
 * ** Post-Conditions: arrays are filled
 * *********************************************************************/

void fill_plate(float** u1, float** u2, float init_temp, int sections, float lr_col_temp, float tb_row_temp) {
	for(int i = 0; i < sections; i++) {
		u1[i] = new float[sections];
		u2[i] = new float[sections];
		for(int j = 0; j < sections; j++) {
			u1[i][j] = init_temp;
			u2[i][j] = init_temp;
		}
	}
	for(int i = 0; i < sections; i++) {
		u1[i][0] = tb_row_temp;
		u1[i][sections - 1] = tb_row_temp;
		u2[i][0] = tb_row_temp;
		u2[i][sections - 1] = tb_row_temp;
		for(int j = 0; j < sections; j++) {
			u1[0][j] = lr_col_temp;
			u1[sections - 1][j] = lr_col_temp;
			u2[0][j] = lr_col_temp;
			u2[sections - 1][j] = lr_col_temp;
		}
	}
}

/*********************************************************************
 * ** Function: print_plate
 * ** Description: u2 is printed to the screen
 * ** Parameters: u2, sections
 * ** Pre-Conditions: u2 is calculated
 * ** Post-Conditions: u2 is printed
 * *********************************************************************/

void print_plate(float** u2, int sections) {
	fileWriter fw("heat2.dat");
	for(int i = 0; i < sections; i++) {
		for(int j = 0; j < sections; j++) {
			fw << u2[i][j];
			cout << setw(10) << u2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*********************************************************************
 * ** Function: calculate_plate
 * ** Description: plate values are calculated
 * ** Parameters: k, rho, c, init_temp, delta_x, delta_y, delta_t, sections, num_intervals, lr_col_temp, tb_row_temp
 * ** Pre-Conditions: stable and inputs collected
 * ** Post-Conditions: plate is calculated
 * *********************************************************************/

void calculate_plate(float k, float rho, float c, float init_temp, float delta_x, float delta_y, float delta_t, int sections, int num_intervals, float lr_col_temp, float tb_row_temp) {
	float** u1 = new float*[sections];
	float** u2 = new float*[sections];

	fill_plate(u1, u2, init_temp, sections, lr_col_temp, tb_row_temp);

	for(int num = 1; num < num_intervals; num++) {
		for(int i = 1; i < sections - 1; i++) {
			for(int j = 1; j < sections - 1; j++) {
				float a = ((u1[i+1][j] - (2 * u1[i][j]) + u1[i-1][j])) / (pow(delta_x, 2.0));
				float b = ((u1[i][j+1] - (2 * u1[i][j]) + u1[i][j-1])) / (pow(delta_y, 2.0));
				float top = delta_t * k * (a + b);
				float bot = rho * c;
				float total = (top / bot) + u1[i][j];
				u2[i][j] = total;
			}
		}
		for(int i = 0; i < sections; i++) {
			for(int j = 0; j < sections; j++) {
				u1[i][j] = u2[i][j];
			}
		}
		print_plate(u2, sections);
	}
	clear_plate(u1, u2, sections);
}

/*********************************************************************
 * ** Function: plate
 * ** Description: calculates plate if plate selected
 * ** Parameters: n/a
 * ** Pre-Conditions: plate is selected
 * ** Post-Conditions: plate is calculated
 * *********************************************************************/

void plate() {
	float k = 0, rho = 0, c = 0, time_sim = 0.001675, init_temp = 0;
	float delta_x = 0, delta_y = 0, delta_t = 0, lr_col_temp = 100, tb_row_temp = 100;
	int plate_height = 0, plate_width = 0, sections = 0, num_intervals = 0;
	bool stable = false;

	input_plate(k, rho, c, init_temp, plate_height, plate_width, sections, num_intervals);

	delta_plate(plate_height, plate_width, sections, delta_x, delta_y, num_intervals, time_sim, delta_t);

	stable = stability_check_p(delta_t, delta_x, delta_y, k, rho, c);

	if(stable)
		calculate_plate(k, rho, c, init_temp, delta_x, delta_y, delta_t, sections, num_intervals, lr_col_temp, tb_row_temp);
	else {
		cout << "Those numbers aren't stable!" << endl;
		cout << "Start over!" << endl;
		exit(1);
	}
}

/*********************************************************************
 * ** Function: main
 * ** Description: asks is user wants to diffuse wire or plate
 * ** Parameters: n/a
 * ** Pre-Conditions: program compiles
 * ** Post-Conditions: wire or plate run
 * *********************************************************************/

int main() {
	string which = "";

	cout << "Do you want to diffuse a 'wire' or a 'plate': ";
	getline(cin, which);

	if (which == "Wire" || which == "wire") {
		wire();
	}

	else if (which == "Plate" || which == "plate") {
		plate();
	}

	else {
		cout << "Wrong input!" << endl;
		exit(1);
	}

	return 0;
}
