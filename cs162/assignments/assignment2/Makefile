pizza: prog.o pizza.o menu.o restaurant.o
	g++ prog.o pizza.o menu.o restaurant.o -o pizza
prog.o: prog.cpp
	g++ -c prog.cpp
pizza.o: pizza.cpp
	g++ -c pizza.cpp
menu.o: menu.cpp
	g++ -c menu.cpp
restaurant.o: restaurant.cpp
	g++ -c restaurant.cpp

clean:
	rm -f *.o *.out pizza
	clear
