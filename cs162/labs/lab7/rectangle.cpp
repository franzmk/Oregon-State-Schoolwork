#include "rectangle.h"

Rectangle::Rectangle() {
	width = 0;
	height = 0;
}

Rectangle::Rectangle(float width, float height, string name, string color) : Shape(name, color) {
	this->width = width;
	this->height = height;
}

float Rectangle::get_height() const{
	return height;
}

void Rectangle::set_height(float height) {
	this->height = height;
}

float Rectangle::get_width() const{
	return width;
}

void Rectangle::set_width(float width) {
	this->width = width;
}

float Rectangle::get_area() const{
	float area = width * height;
	return area;
}

Rectangle::~Rectangle() {
}
