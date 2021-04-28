struct mult_div_values {
	int mult;
	float div;
};

mult_div_values** create_table(int, int);
void set_mult_values(mult_div_values **, int, int);
void set_div_values(mult_div_values **, int, int);
void delete_table(mult_div_values **, int);
void check_num_args(int);
void check_vals(int&, int&);
void print(mult_div_values **, int, int);
void again();
