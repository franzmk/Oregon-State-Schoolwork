#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

int main() {
	Shape s1;
	Shape s2("Square", "Blue");

	s1 = s2;

	cout << "s2: " << s2.get_name() << endl;
	cout << "s2: " << s2.get_color() << endl;

	cout << endl;
	
	Circle c1;
	Circle c2(2.3, "Circle", "Red");

	c1 = c2;

	cout << "c2: " << c2.get_name() << endl;
	cout << "c2: " << c2.get_color() << endl;
	cout << "c2: " << c2.get_radius() << endl;
	cout << "c2: " << c2.get_area() << endl;

	cout << endl;

	Rectangle r1;
	Rectangle r2(4, 6, "Rectangle", "Green");

	r1 = r2;

	cout << "r2: " << r2.get_name() << endl;
	cout << "r2: " << r2.get_color() << endl;
	cout << "r2: " << r2.get_width() << endl;
	cout << "r2: " << r2.get_height() << endl;
	cout << "r2: " << r2.get_area() << endl;

	cout << endl;

	Square sq1;
	Square sq2(7, "Square", "Orange");

	sq1 = sq2;

	cout << "sq2: " << sq2.get_name() << endl;
	cout << "sq2: " << sq2.get_color() << endl;
	cout << "sq2: " << sq2.get_dimensions() << endl;
	cout << "sq2: " << sq2.get_area() << endl;

	return 0;
}
