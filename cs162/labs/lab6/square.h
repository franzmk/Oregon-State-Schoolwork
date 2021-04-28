#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
	public:
		Square();
		Square(float, string, string);
		~Square();
		float get_area();
		float get_dimensions();
		void set_dimensions(float);
};

#endif
