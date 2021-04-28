#include "student.h"

student * create_student_db(int num_students) {
	student *students = new student[num_students];
	return students;
}

void get_student_db_info(student *students, int num_students, ifstream &f1) {
	for (int i = 0; i < num_students; i++) {	
		f1 >> students[i].id >> students[i].first_name >> students[i].last_name >> students[i].major;
	}
}

void print(student *students, int num_students) {
	for (int i = 0; i < num_students; i++) {
		cout << endl;
		cout << students[i].id << " " << students[i].first_name << " " << students[i].last_name << " " << students[i].major;
		cout << endl;
	}
}

void id_sort(student *students, int num_students) {
	for (int i = 0; i < num_students; i++) {
		for (int j = 0; j < num_students - 1; j++) {
			if (students[j].id > students[j + 1].id) {
				student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
	
	print(students, num_students);
}

void ln_sort(student *students, int num_students) {
	for (int i = 0; i < num_students; i++) {
		for (int j = 0; j < num_students - 1; j++) {
			int a = int(students[j].last_name[0]);
			int b = int(students[j + 1].last_name[0]);
			if (a > b) {
				student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	print(students, num_students);
}

void major_count(student *students, int num_students) {
	int num = 0;
	
	for (int i = 0; i < num_students; i++) {
		int j;
		for (j = 0; j < i; j++) {
			if (students[i].major == students[j].major) {
				break;
			}
		}
		if (i == j) {
			num++;
		}
	}

	cout << endl;
	cout << "There are " << num << " unique majors among the students." << endl;
}

void delete_student_db_info(student *students, int num_students) {
	delete [] students;
	students = NULL;
}

void choose(student *students, int num_students) {
	do {
		int choice = 4;
		cout << endl;
		cout << "Sort students by ID (1)" << endl;
		cout << "Sort students by last name (2)" << endl;
		cout << "Find number of unique majors (3)" << endl;
		cout << "Exit (4)" << endl;
		cin >> choice;

		if (choice == 1) id_sort(students, num_students);
		else if (choice == 2) ln_sort(students, num_students);
		else if (choice == 3) major_count(students, num_students);
		else {
			delete_student_db_info(students, num_students);
			return;
		}
	} while(true);
}

