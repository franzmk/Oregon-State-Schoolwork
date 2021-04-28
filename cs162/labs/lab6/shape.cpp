#include "shape.h"

Shape::Shape() {
	name = "";
	color = "";
}

Shape::Shape(string name, string color) {
	this->name = name;
	this->color = color;
}

string Shape::get_name() {
	return name;
}

void Shape::set_name(string name) {
	this->name = name;
}

string Shape::get_color() {
	return color;
}

void Shape::set_color(string color) {
	this->color = color;
}

int Shape::get_area() {
	return 0;
}

Shape::~Shape() {
	cout << "Destructor called" << endl;
}
