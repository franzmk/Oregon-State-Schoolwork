#include "square.h"

Square::Square() {
	//nothing here
}

Square::Square(float x, string name, string color) : Rectangle(x, x, name, color) {
	//nothing here
}

float Square::get_dimensions() const{
	get_height();
}

void Square::set_dimensions(float x) {
	set_height(x);
	set_width(x);
}

float Square::get_area() const{
	float area = get_height() * get_width();
	return area;
}

Square::~Square() {
}
