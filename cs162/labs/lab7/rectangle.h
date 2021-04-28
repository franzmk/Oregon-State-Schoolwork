#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
	private:
		float width;
		float height;
	public:
		float get_width() const;
		void set_width(float);
		float get_height() const;
		void set_height(float);
		float get_area() const;
		Rectangle();
		Rectangle(float, float, string, string);
		~Rectangle();
};

#endif
