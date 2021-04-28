#include <iostream>
#include <iomanip>

using namespace std;

void move(int b[3][3], int from_col, int to_col, int spare, int num_disks) {
	int i, j;

	for (i = 0; i < num_disks; i++) {
		if (b[i][from_col] != 0) {
			break;
		}
	}

	for (j = num_disks - 1; j >= 0; j--) {
		if (b[j][to_col] == 0) {
			break;
		}
	}

	b[j][to_col] = b[i][from_col];
	b[i][from_col] = 0;
}

void print(int b[3][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout << setw(2) << b[i][j];
		}
		cout << endl;
	}
	cout << "-------" << endl;
}

void towers(int num_disks, int b[][3], int from_col, int to_col, int spare) {
	if(num_disks >= 1) {
		towers(num_disks - 1, b, from_col, spare, to_col);
		move(b, from_col, to_col, spare, num_disks);
		print(b);
		towers(num_disks - 1, b, spare, to_col, from_col);
	}
}

int main() {
	int num_disks = 3, from_col = 0, to_col = 1, spare = 2;
	int b[3][3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			b[i][j] = 0;

			if(j == 0)
				b[i][j] = i + 1;
		}
	}
	
	towers(num_disks, b, from_col, to_col, spare);

	return 0 ;
}
