lab: shape.o rectangle.o circle.o square.o application.o
	g++ shape.o rectangle.o circle.o square.o application.o -o lab
shape.o: shape.cpp
	g++ -c shape.cpp
rectangle.o: rectangle.cpp
	g++ -c rectangle.cpp
circle.o: circle.cpp
	g++ -c circle.cpp
square.o: square.cpp
	g++ -c square.cpp
application.o: application.cpp
	g++ -c application.cpp

clean:
	rm -f *.o *.out lab
	clear
