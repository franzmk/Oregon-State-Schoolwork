#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <cstring>

using namespace std;


class Shape {
	private:
		string name;
		string color;
	public:
		string get_name();
		void set_name(string);
		string get_color();
		void set_color(string);
		Shape();
		Shape(string, string);
		~Shape();
		int get_area();
};

#endif
