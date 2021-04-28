/*
*   Written by Student B.
*   This is D level work.
*   10/14/20
*   Assignment 7
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
*   Function that adds 12 to the int that is passed in by pointer and displays the new value.
*   Valid input ranges from 0 - maximum signed int value.
*/

int* do_something(int* x) {
	int *ptr = (int*) malloc(sizeof(int));
	int value = *x;

	printf("Initial value: %d\n", value);
	if (value > 4) {
		printf("That is greater than 4!\n");
	} else {
		printf("That is less than 4.\n");
	}

	*ptr = value + 12; //weird
	printf("result after adding 12: %d\n", *ptr);

	return ptr;
}

char create_a_char() {

	//array that is used to hold random numbers for the character generator
	int my_array[1000];

	printf("Please provide an integer for the function:\n");
	scanf("%d", my_array);

	//this loops fills all indeces in the array with the user input
	for (int i = 1; i < 1000; i++) {
		my_array[i] = my_array[0];
	}

	char new_char = (char)(my_array[7] * my_array[476]);

	return new_char;
}

int main(void) {
	int user_input;
	int* other_num = &user_input; //initialized to NULL, good

	printf("Launching main function...\n");
	printf("Please provide an integer:\n");
	scanf("%d", &user_input);
	int* result =	do_something(other_num);

	printf("The new char is: %c\n", create_a_char());

	printf("Value returned was: %d\n", *result);

	free(result);

	return 0;
}
