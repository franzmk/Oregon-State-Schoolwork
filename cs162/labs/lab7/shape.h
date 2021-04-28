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
		string get_name() const;
		void set_name(string);
		string get_color() const;
		void set_color(string);
		Shape();
		Shape(string, string);
		~Shape();
		virtual float get_area() const = 0;
		friend bool operator>(const Shape&, const Shape&);
		friend bool operator<(const Shape&, const Shape&);
};


#endif
