#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
	public:
		Square();
		Square(float, string, string);
		~Square();
		float get_area() const;
		float get_dimensions() const;
		void set_dimensions(float);
};

#endif
