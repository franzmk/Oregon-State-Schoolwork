#include "shape.h"

Shape::Shape() {
	name = "";
	color = "";
}

Shape::Shape(string name, string color) {
	this->name = name;
	this->color = color;
}

string Shape::get_name() const{
	return name;
}

void Shape::set_name(string name) {
	this->name = name;
}

string Shape::get_color() const{
	return color;
}

void Shape::set_color(string color) {
	this->color = color;
}

bool operator>(const Shape &s1, const Shape &s2) {
	if(s1.get_area() > s2.get_area()) {
		return true;
	}
	else return false;
}

bool operator<(const Shape &s1, const Shape &s2) {
	if(s1.get_area() < s2.get_area()) {
		return true;
	}
	else return false;
}

Shape::~Shape() {
	cout << "Destructor called" << endl;
}
