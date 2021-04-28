#include "square.h"

Square::Square() {
	//nothing here
}

Square::Square(float x, string name, string color) : Rectangle(x, x, name, color) {
	//nothing here
}

float Square::get_dimensions() {
	get_height();
}

void Square::set_dimensions(float x) {
	set_height(x);
	set_width(x);
}

float Square::get_area() {
	float area = get_height() * get_width();
	return area;
}

Square::~Square() {
	cout << "Destructor called" << endl;
}
