#include "circle.h"

Circle::Circle() {
	radius = 0;
}

Circle::Circle(float radius, string name, string color) : Shape(name, color) {
	this->radius = radius;
}

float Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(float radius) {
	this->radius = radius;
}

float Circle::get_area() const{
	float area = M_PI * (radius * radius);
	return area;
}

Circle::~Circle() {
}
