#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <cmath>

class Circle : public Shape {
	private:
		float radius;
	public:
		float get_radius();
		void set_radius(float);
		float get_area();
		Circle();
		Circle(float, string, string);
		~Circle();
};

#endif
