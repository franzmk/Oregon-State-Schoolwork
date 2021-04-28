#include "student.h"

using namespace std;

int main(int argc, char* argv[]) {
	string file, students;
	int num_students = 0;
	file = argv[1];
	ifstream f1;
	f1.open(file.c_str(), ios::in);
	if(!f1.is_open()) {
		cout << "File opened incorrectly!" << endl;
		exit(0);
	}
	else {
		getline(f1, students);
		num_students = atoi(students.c_str());

		student *students = create_student_db(num_students);

		get_student_db_info(students, num_students, f1);

		choose(students, num_students);
	}
	
}
