#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//This function fills the array with random values between 1 and 10,000
void fill_array(int *array, int size) {
	for(int i = 0; i < size; i++) {
		array[i] = (rand() % 10000) + 1;
	}
}

//The sorting function that does all the work
void insertionSort(int *arr, int size) {
	//Initialize variables to be used in function
	int i, j, val;
	//For loop that runs for the size of the array
	for(i = 1; i < size; i++) {
		//The first val looked at is arr[i]
		val = arr[i];
		//Set j to one less than i every iteration
		j = i - 1;

		//While j is greater than or equal to 0 and arr[j] > the current value
		while(j >= 0 && arr[j] > val) {
			//If this is true, the variables are switched
			arr[j + 1] = arr[j];
			//Decrease j by 1 every time an insertion happens
			j = j - 1;
		}
		//Set the next value in the array to val
		arr[j + 1] = val;
	}
}

//The main function
int main(int argc, char **argv) {
	//Seed random
	srand(time(NULL));

	//Set default size
	int size = 5000;

	//Create a new array
	int *array;
	
	//For loop that runs 10 times
	for(int i = 0; i < 10; i++) {
		//Intialize the new array to the current value of size
		array = new int[size];

		//Fill the array
		fill_array(array, size);

		//Start the clock
		clock_t t1, t2;
		t1 = clock();

		//Sort
		insertionSort(array, size);

		//Stop the clock
		t2 = clock();
		float diff = ((float) t2 - (float) t1);
		//Get the time in milliseconds
		diff = diff / (CLOCKS_PER_SEC/1000);

		//Print the size and time
		cout << "insertionSort n = " << size << " in " << diff << " milliseconds" << endl;

		//Delete the current array for memory
		delete[] array;
		//Increase size by 5000
		size = size + 5000;
	}

	return 0;
}
