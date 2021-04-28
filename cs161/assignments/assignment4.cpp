/*********************************************************************
 * ** Program Filename:assignment4.cpp
 * ** Author: mfra8
 * ** Date: 2/17/19
 * ** Description: This program calculates expenses and reimbursements based on data that's entered for business reports.
 * ** Input: Inputs include number of days on the trip, departure time, arrival time, airfare prices, registration prices for conferences or seminars, rental car or taxi, total spent on rental car, gas costs, miles driven, car type, parking fees, taxi costs per day, hotel fees, breakfast fees, lunch fees, and dinner fees.
 * ** Output: Total expenses and total reimbursements
 * *********************************************************************/
//CHANGE ALL TYPES TO STRING
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

/*********************************************************************
 * ** Function: car_fees 
 * ** Description: Calculates the total expense and total reimbursement for the rental car 
 * ** Parameters: car_type, days_of_trip, miles_driven, car_price, car_gas_price, total_expense, and total_reimbursement
 * ** Pre-Conditions: Each parameter have a value
 * ** Post-Conditions: Total expense and total reimbursement have been changed and next function calls
 * *********************************************************************/

void car_fees(int car_type, int days_of_trip, float miles_driven, float car_price, float car_gas_price, float &total_expense, float &total_reimbursement) {
	float car_rental_fee = 0.00, car_gas = 0.00;
	
	switch(car_type) {
		case 1: car_rental_fee = 20, car_gas = 0.24; break; //sedan
		case 2: car_rental_fee = 25, car_gas = 0.27; break; //suv
		case 3: car_rental_fee = 30, car_gas = 0.32; break; //van
		case 4: car_rental_fee = 50, car_gas = 0.45; break; //convertible
	}

	total_expense += car_price + car_gas_price;
	total_reimbursement += (car_rental_fee * days_of_trip) + (car_gas * miles_driven);
}

/*********************************************************************
 * ** Function: error_checker
 * ** Description: Checks if the input proved is a number with or without a decimal point
 * ** Parameters: input
 * ** Pre-Conditions: input be a string that is then typecasted to an integer or a float after it passes the error checker
 * ** Post-Conditions: return true or false
 * *********************************************************************/

bool error_checker(string input) {
	if(input.at(0) == '0')
		return false;
	else {
		for(int i = 0; i < input.size(); i++) {
		        if (!(input.at(i) == '.' || input.at(i) >= '0' && input.at(i) <= '9')) {
		                cout << "Error!" << endl;
		                return false;
		        }
		}
		return true;
	}
}

/*********************************************************************
 * ** Function: days
 * ** Description: Asks how many days the user was on a trip for and collects that data into the days_of_trip variable
 * ** Parameters: days_of_trip
 * ** Pre-Conditions: user enters a number
 * ** Post-Conditions: a number is stored and next function calls
 * *********************************************************************/

void days(int &days_of_trip) {
	string days = "";
	cout << endl;
	do{
		do{
			cout << "Enter the number of days on your trip: ";
			cin >> days;
		}while(!error_checker(days));
		days_of_trip = atoi(days.c_str());
	}while(!(days_of_trip > 0));

	cout << endl;
}

/*********************************************************************
 * ** Function: departure
 * ** Description: asks for and stores the departure time of the user on the first day of their business trip
 * ** Parameters: departure_time
 * ** Pre-Conditions: user enters a number like 'xx.xx'
 * ** Post-Conditions: a number is stored and next function calls
 * *********************************************************************/

void departure(double &departure_time) {
	string departure = "";
	cout<< "This program is utilizing a 24 hour clock." << endl;
	do{
		do{
			cout << "Enter the time of your departure on the first day: ";
			cin >> departure;
		}while(!error_checker(departure));
		departure_time = atof(departure.c_str());
	}while(!(departure_time > 0.00 && departure_time <= 23.59));
}

/*********************************************************************
 * ** Function: arrival
 * ** Description: asks for and stores the arrival time of the user on the last day of their business trip
 * ** Parameters: arrival_time
 * ** Pre-Conditions: user enters a number like 'xx.xx'
 * ** Post-Conditions: a number is stored and next function calls
 * *********************************************************************/

void arrival(double &arrival_time) {
	string arrival = "";
	do{
		do{
			cout << "Enter the time of your arrival on the last day: ";
			cin >> arrival;
		}while(!error_checker(arrival));
		arrival_time = atof(arrival.c_str());
	}while(!(arrival_time > 0 && arrival_time <= 23.59));
	cout << endl;
}

/*********************************************************************
 * ** Function: air_reg
 * ** Description: the airfare of the users flight and the cost of any registration fees are collected here
 * ** Parameters: total_expense and total_reimbursement
 * ** Pre-Conditions: the user enters numbers like 'xx.xx'
 * ** Post-Conditions: the numbers are added to total_expense and total_reimbursement and next function calls
 * *********************************************************************/

void air_reg(float &total_expense, float &total_reimbursement) {
	string air = "", reg = "";
	float airfare = 0.00, registration_fees = 0.00;
	do{
		cout << "What was the cost of airfare?: $";
		cin >> air;
	}while(!error_checker(air));
	airfare = atof(air.c_str());
	do{
		cout << "What was the cost of registration fees for seminars or meetings?: $";
		cin >> reg;
	}while(!error_checker(reg));
	registration_fees = atof(reg.c_str());

	total_expense += airfare + registration_fees;
	total_reimbursement += airfare + registration_fees;

	cout << endl;
}

/*********************************************************************
 * ** Function: another_one
 * ** Description: this program runs after the entire program has finished and asks the user if they want to calculate another business expense report
 * ** Parameters: none
 * ** Pre-Conditions: the program finishes successfully
 * ** Post-Conditions: the program starts again and next function calls
 * *********************************************************************/

bool another_one() {
	char again = ' ';
	
	cout << endl;
	cout << "Do you want to calculate another business expense report? (y/n): ";
	cin >> again;

	if (again == 'y') 
		return true;
	
	else
		return false;
	cout << endl;
}

/*********************************************************************
 * ** Function: parking_fees
 * ** Description: if the user rented a car, parking fees for however many days they were on the trip are collected and added to the totals
 * ** Parameters: days_of_trip, total_expense, and total_reimbursement
 * ** Pre-Conditions: the user rented a car
 * ** Post-Conditions: totals are added to total_expense and total_reimbursement and next function calls
 * *********************************************************************/

void parking_fee(int days_of_trip, float &total_expense, float &total_reimbursement) {
	string p_cost = "";
	float parking_cost = 0.00;
	cout << endl;
	for(int i = 1; i <= days_of_trip; i++) {
		do{
			cout << "Enter parking fees for day " << i << ": $";
			cin >> p_cost;
		}while(!error_checker(p_cost));
		parking_cost = atof(p_cost.c_str());
		if(parking_cost >= 6.00) {
			total_expense += parking_cost;
			total_reimbursement += 6.00;
		}
		else {
			total_expense += parking_cost;
			total_reimbursement += parking_cost;
		}
	}
}

/*********************************************************************
 * ** Function: car
 * ** Description: This function asks the user for the total cost of their rental car, how much they spent on gas, the type of car they rented, and however many miles they drove. It then calculates everything car related by calling car_fees and then calculates parking fees by calling that function. It is 23 lines because I thought it was unnecessary to put rental_price, gas_price, car_type, or miles in their own function.
 * ** Parameters: days_of_trip, total_expense, and total_reimbursement
 * ** Pre-Conditions: the user rented a car
 * ** Post-Conditions: car_fees and parking_fees are called, and everything is successfully added to total_expense and total_reimbursement and next function calls
 * *********************************************************************/

void car(int days_of_trip, float &total_expense, float &total_reimbursement) {
	string rent_price = "", gas_cost = "", type = "",  mile = "";
	float rental_price = 0.00, gas_price = 0.00, miles = 0.00;
	int car_type = 0;
	cout << endl;
	do{
		cout << "Enter total amount spent on rental car: $";
		cin >> rent_price;
	}while(!error_checker(rent_price));
	rental_price = atof(rent_price.c_str());
	do{
		cout << "Enter total amount spent on gas: $";
		cin >> gas_cost;
	}while(!error_checker(gas_cost));
	gas_price = atof(gas_cost.c_str());
	do{
		cout << "Which type of car did you rent? \n 1. Sedan \n 2. SUV \n 3. Van \n 4. Convertible" << endl;
		cin >> type;
	}while(!error_checker(type));
	car_type = atoi(type.c_str());
	do{
		cout << "Enter the total miles driven, in miles: ";
		cin >> mile;
	}while(!error_checker(mile));
	miles = atof(mile.c_str());

	car_fees(car_type, days_of_trip, miles, rental_price, gas_price, total_expense, total_reimbursement);

	parking_fee(days_of_trip, total_expense, total_reimbursement);
}

/*********************************************************************
 * ** Function: taxi
 * ** Description: If the user didn't rent a car and took a taxi everywhere, this calculates reimbursement based on taxi costs every day of the trip
 * ** Parameters: days_of_trip, total_expense, and total_reimbursement
 * ** Pre-Conditions: the user took a taxi
 * ** Post-Conditions: numbers are added to total_expense and total_reimbursement successfully and next function calls
 * *********************************************************************/

void taxi(int days_of_trip, float &total_expense, float &total_reimbursement) {
	string t_price = "";
	float taxi_price = 0.00;
	cout << endl;
	for(int i = 1; i <= days_of_trip; i++) {
		do{
			cout << "Enter the taxi costs on day " << i << ": $";
			cin >> t_price;
		}while(!error_checker(t_price));
		taxi_price = atof(t_price.c_str());
		if(taxi_price >= 10.00) {
			total_expense += taxi_price;
			total_reimbursement += 10.00;
		}
		else {
			total_expense += taxi_price;
			total_reimbursement += taxi_price;
		}
	}
}

/*********************************************************************
 * ** Function: rent_or_taxi
 * ** Description: lets the user decided if they rented a car or used a taxi
 * ** Parameters: days_of_trip, total_expense, and total_reimbursement
 * ** Pre-Conditions: all previous functions worked, user enters a number 1-4
 * ** Post-Conditions: whichever option they chose should call and next function calls
 * *********************************************************************/

void rent_or_taxi (int days_of_trip, float &total_expense, float &total_reimbursement) {
	int which = 0;
	string w = "";
	do{
		do{
			cout << "Did you rent a car (1) or take a taxi (2)?: ";
			cin >> w;
		}while(!error_checker(w));
		which = atoi(w.c_str());
	}while(which != 1 && which != 2);
	if (which == 1) 
		car(days_of_trip, total_expense, total_reimbursement);
	else if (which == 2)
		taxi(days_of_trip, total_expense, total_reimbursement);
}

/*********************************************************************
 * ** Function: hotel
 * ** Description: asks the user for their hotel fees and calculates what gets reimbursed and what doesn't
 * ** Parameters: days_of_trip, total_expense, and total_reimbursement
 * ** Pre-Conditions: all previous functions worked
 * ** Post-Conditions: worked correctly and next function calls
 * *********************************************************************/

void hotel(int days_of_trip, float &total_expense, float &total_reimbursement) {
	string h_price = "";
	float hotel_price = 0.00;
	cout << endl;
	for(int i = 1; i < days_of_trip; i++) {
		do{
			cout << "Enter the hotel fee for night " << i << ": $";
			cin >> h_price;
		}while(!error_checker(h_price));
		hotel_price = atof(h_price.c_str());
		if(hotel_price >= 90.00) {
			total_expense += hotel_price;
			total_reimbursement += 90.00;
		}
		else {
			total_expense += hotel_price;
			total_reimbursement += hotel_price;
		}
	}
}

/*********************************************************************
 * ** Function: breakfast
 * ** Description: calculates breakfast prices and adds them to total_expense and total_reimbursement
 * ** Parameters: total_expense and total_reimbursement
 * ** Pre-Conditions: meal_calculator worked
 * ** Post-Conditions: added to total_expense and total_reimbursement successfully and next function calls
 * *********************************************************************/

void breakfast(float &total_expense, float &total_reimbursement) {
	string b_price = "";
	float bf_price = 0.00;
	do{
		cout << "Enter the price of your breakfast: $";
		cin >> b_price;
	}while(!error_checker(b_price));
	bf_price = atof(b_price.c_str());
	if(bf_price >= 9.00) {
		total_expense += bf_price;
		total_reimbursement += 9.00;
	}
	else {
		total_expense += bf_price;
		total_reimbursement += bf_price;
	}
}

/*********************************************************************
 * ** Function: lunch
 * ** Description: calculates lunch prices and adds them to total_expense and total_reimbursement
 * ** Parameters: total_expense and total_reimbursement
 * ** Pre-Conditions: meal_calculator worked
 * ** Post-Conditions: added to total_expense and total_reimbursement successfully and next function calls
 * *********************************************************************/

void lunch(float &total_expense, float &total_reimbursement) {
	string l_price = "";
	float lu_price = 0.00;
	do{
		cout << "Enter the price of your lunch: $";
		cin >> l_price;
	}while(!error_checker(l_price));
	lu_price = atof(l_price.c_str());
	if(lu_price >= 12.00) {
		total_expense += lu_price;
		total_reimbursement += 12.00;
	}
	else {
		total_expense += lu_price;
		total_reimbursement += lu_price;
	}
}

/*********************************************************************
 * ** Function: dinner
 * ** Description: calculates dinner prices and adds them to total_expense and total_reimbursement
 * ** Parameters: total_expense and total_reimbursement
 * ** Pre-Conditions: meal_calculator worked
 * ** Post-Conditions: added tot total_expense and total_reimbursement successfully and next function calls
 * *********************************************************************/

void dinner(float total_expense, float &total_reimbursement) {
	string d_price = "";
	float din_price = 0.00;
	do{
		cout << "Enter the price of your dinner: $";
		cin >> d_price;
	}while(!error_checker(d_price));
	din_price = atof(d_price.c_str());
	if(din_price >= 16.00) {
		total_expense += din_price;
		total_reimbursement += 16.00;
	}
	else {
		total_expense += din_price;
		total_reimbursement += din_price;
	}
}

/*********************************************************************
 * ** Function: first_day_meal
 * ** Description: determines which meals are expensed based on departure time on the first day
 * ** Parameters: departure_time, total_expense, and total_reimbursement
 * ** Pre-Conditions: it's the first day of the trip and there is a departure time
 * ** Post-Conditions: all functions inside worked properly, correct if was called, and next function calls
 * *********************************************************************/

void first_day_meal(double departure_time, float &total_expense, float &total_reimbursement) {
	if(departure_time < 7.00) {
		breakfast(total_expense, total_reimbursement);
		lunch(total_expense, total_reimbursement);
		dinner(total_expense, total_reimbursement);
	}
	else if(departure_time >= 7.00 && departure_time < 12.00) {
		cout << "Breakfast for this day is not allowed as an expense." << endl;
		lunch(total_expense, total_reimbursement);
		dinner(total_expense, total_reimbursement);
	}
	else if(departure_time >= 12.00 && departure_time < 18.00) {
		cout << "Breakfast for this day is not allowed as an expense." << endl;
		cout << "Lunch for this day is not allowed as an expense." << endl;
		dinner(total_expense, total_reimbursement);
	}
	else {
		cout << "No meals are allowed as an expense this day." << endl;
	}
}

/*********************************************************************
 * ** Function: last_day_meal
 * ** Description: determines which meals are expensed based on arrival time on the last day
 * ** Parameters: arrival_time, total_expense, and total_reimbursement
 * ** Pre-Conditions: it's the last day of the trip and there is an arrival time
 * ** Post-Conditions: all functions inside worked properly, correct if was called, and next function calls
 * *********************************************************************/

void last_day_meal(double arrival_time, float &total_expense, float &total_reimbursement) {
	if(arrival_time < 8.00) {
		cout << "No meals are allowed as an expense this day." << endl;
	}
	else if(arrival_time >= 8.00 && arrival_time < 13.00) {
		breakfast(total_expense, total_reimbursement);
		cout << "Lunch for this day is not allowed as an expense." << endl;
		cout << "Dinner for this day is not allowed as an expense." << endl;
	}
	else if(arrival_time >= 13.00 && arrival_time < 19.00) {
		breakfast(total_expense, total_reimbursement);
		lunch(total_expense, total_reimbursement);
		cout << "Dinner for this day is not allowed as an expense." << endl;
	}
	else {
		breakfast(total_expense, total_reimbursement);
		lunch(total_expense, total_reimbursement);
		dinner(total_expense, total_reimbursement);
	}
}

/*********************************************************************
 * ** Function: meal_calculator
 * ** Description: calls and calculates meals based on the day they occur
 * ** Parameters: days_of_trip, departure_time, arrival_time, total_expense, and total_reimbursement
 * ** Pre-Conditions: all functions before worked
 * ** Post-Conditions: all meals per day were calculated and determined correctly and next function calls
 * *********************************************************************/

void meal_calculator(int days_of_trip, double departure_time, double arrival_time, float &total_expense, float &total_reimbursement) {
	cout << endl;
	for(int i = 1; i <= days_of_trip; i++) {
		if(i == 1) {
			cout << "Day " << i << ":" << endl;
			first_day_meal(departure_time, total_expense, total_reimbursement);
			cout << endl;
		}
		if(i > 1 && i != days_of_trip) {
			cout << "Day " << i << ":" << endl;
			breakfast(total_expense, total_reimbursement);
			lunch(total_expense, total_reimbursement);
			dinner(total_expense, total_reimbursement);
			cout << endl;
		}
		if(i == days_of_trip) {
			cout << "Day " << i << ":" << endl;
			last_day_meal(arrival_time, total_expense, total_reimbursement);
			cout << endl;
		}
	}
}

/*********************************************************************
 * ** Function: main
 * ** Description: initiliazes variables used in multiple functions and determines the order of all functions and when they are called
 * ** Parameters: none
 * ** Pre-Conditions: program is compiled
 * ** Post-Conditions: all functions are called
 * *********************************************************************/ 

int main() {
	do{
		int days_of_trip = 0;
		float total_expense = 0.00, total_reimbursement = 0.00;
		double departure_time = 0, arrival_time = 0;
	
		days(days_of_trip);
		
		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
		departure(departure_time);

		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
		arrival(arrival_time);

		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
		air_reg(total_expense, total_reimbursement);

		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
		rent_or_taxi(days_of_trip, total_expense, total_reimbursement);
		
		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
		hotel(days_of_trip, total_expense, total_reimbursement);

		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
		meal_calculator(days_of_trip, departure_time, arrival_time, total_expense, total_reimbursement);

		cout << "Your total expense for this trip: $" << total_expense << endl;
		cout << "Your total reimbursement for this trip: $" << total_reimbursement << endl;
	}while(another_one());

	return 0;
}
