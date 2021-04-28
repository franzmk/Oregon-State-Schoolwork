#include <iostream>
#include <stdlib.h>
#include "./mult_div.h"

int main(int argc, char* argv[]) {
	int rows = 0, cols = 0;

	check_num_args(argc);

	rows = atoi(argv[1]);
	cols = atoi(argv[2]);

	check_vals(rows, cols);

	mult_div_values **table = create_table(rows, cols);

	set_mult_values(table, rows, cols);

	set_div_values(table, rows, cols);

	print(table, rows, cols);

	delete_table(table, rows);
	
	return 0;
}
