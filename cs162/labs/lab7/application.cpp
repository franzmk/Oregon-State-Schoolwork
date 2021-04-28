#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

void print_shape_info(const Shape &s) {
	cout << s.get_name() << ":" << endl;
	cout << "Color: " << s.get_color() << endl;
	cout << "Area: " << s.get_area() << endl;
	cout << endl;
}

int main() {
	Square sq1(9, "Square", "Blue");
	Square sq2(7, "Square", "Orange");

	cout << "sq1: " << sq1.get_area() << endl;
	cout << "sq2: " << sq2.get_area() << endl;

	if(sq1 > sq2) {
		cout << "sq1 area is greater than sq2 area" << endl;
	}



	Rectangle r1(9, 4, "Rectangle", "Red");
	print_shape_info(r1);

	print_shape_info(sq1);

	Circle c1(2.6, "Circle", "Orange");
	print_shape_info(c1);

	if(sq1 > c1) {
		cout << "sq1 area greater than c1 area" << endl;
	}

	return 0;
}
