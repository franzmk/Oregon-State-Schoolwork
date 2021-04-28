#include "circle.h"

Circle::Circle() {
	radius = 0;
}

Circle::Circle(float radius, string name, string color) : Shape(name, color) {
	this->radius = radius;
}

float Circle::get_radius() {
	return radius;
}

void Circle::set_radius(float radius) {
	this->radius = radius;
}

float Circle::get_area() {
	float area = M_PI * (radius * radius);
	return area;
}

Circle::~Circle() {
	cout << "Destructor called" << endl;
}
