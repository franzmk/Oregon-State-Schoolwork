mult_div: lab1.o prog.o
	g++ lab1.o prog.o -o mult_div
prog.o: prog.cpp
	g++ -c prog.cpp
lab1.o: lab1.cpp
	g++ -c lab1.cpp

clean:
	rm -f *.o *.out mult_div
