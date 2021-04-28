#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//This function fills the array with the correct size
void fill_array(int *array, int size) {
	for(int i = 0; i < size; i++) {
		array[i] = (rand() % 10000) + 1;
	}
}

//The merge function that connects two pieces of an array
void merge(int *arr, int leftBound, int mid, int rightBound) {
	//Intialize left array size
	int leftArrSize = mid - leftBound + 1;

	//Create a Left array
	int L[leftArrSize];
	
	//Initialize right array size
	int rightArrSize = rightBound - mid;

	//Create a right array
	int R[rightArrSize];

	//Copy data into left and right arrays
	for (int i = 0; i < leftArrSize; i++) {
		L[i] = arr[leftBound + i];
	}

	for (int j = 0; j < rightArrSize; j++) {
		R[j] = arr[mid + 1 + j];
	}

	//Intialize indexes to appropriate values
	int leftI = 0, rightI = 0, mainI = leftBound;

	//Sort the pieces of the array
	while (leftI < leftArrSize && rightI < rightArrSize) {
		//Check if the left value is less than or equal to the right value
		if (L[leftI] <= R[rightI]) {
			//If so, add the left value to the main array
			arr[mainI] = L[leftI];
			//Increase the i index
			leftI++;
		} else {
			//If not, add the right value to the main array
			arr[mainI] = R[rightI];
			//Increase the j index
			rightI++;
		}
		//Increase the main array index after the new value has been added
		mainI++;
	}

	//Copy any remaining values
	while (leftI < leftArrSize) { //If the left index is less than the total size of the left half, the rest of the values are added to the main array
		arr[mainI] = L[leftI];
		//Both indexes are increased to account for however many values were added
		leftI++;
		mainI++;
	}

	//Copy any remaining values
	while (rightI < leftArrSize) { //If the right index is less than the total size of the left half, the rest of the values are added to the main array
		arr[mainI] = R[rightI];
		//Both indexes are increased to account for however many values were added
		rightI++;
		mainI++;
	} 
} 

//Driving function for the merge sort algorithm, recursively calls itself
void mergeSort(int *arr, int leftBound, int rightBound) {
	if (leftBound < rightBound) {
		//Find the middle of the array
		int mid = (leftBound + rightBound - 1) / 2;
		//Recursively call mergeSort to sort two halves of the array every recursion
		mergeSort(arr, leftBound, mid);
		mergeSort(arr, mid + 1, rightBound);
		//Merge the two halves
		merge(arr, leftBound, mid, rightBound);
	}
}

int main() {
	//Random is seeded
	srand(time(NULL));

	//Set size to 50000
	int size = 50000;
	//Create a new array
	int *array;
	
	//For loop that runs 10 times
	for(int i = 0; i < 10; i++) {
		//Initialize new array to correct size
		array = new int[size];

		//Fill array
		fill_array(array, size);

		//Initialize clock
		clock_t t1, t2;

		//Start the clock
		t1 = clock();
		//mergeSort function
		mergeSort(array, 0, size - 1);
		//Stop the clock
		t2 = clock();

		//Calculate the time
		float diff = ((float) t2 - (float) t1);
		diff = diff / (CLOCKS_PER_SEC/1000);

		//Print the size and time
		cout << "mergeSort n = " << size << " in " << diff << " milliseconds" << endl;

		//Delete array for memory
		delete[] array;
		//Increase size by 10000
		size = size + 10000;
	}

	return 0;
}
