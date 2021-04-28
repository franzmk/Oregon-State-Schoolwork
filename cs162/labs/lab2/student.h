#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

struct student {
	int id;
	string first_name;
	string last_name;
	string major;
};

student * create_student_db(int);
void get_student_db_info(student *, int, ifstream &);
void delete_student_db_info(student *, int);
void print(student *, int);
void choose(student *, int);
