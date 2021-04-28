#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
	private:
		float width;
		float height;
	public:
		float get_width();
		void set_width(float);
		float get_height();
		void set_height(float);
		float get_area();
		Rectangle();
		Rectangle(float, float, string, string);
		~Rectangle();
};

#endif
