#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//This function will print an array
void print_array(int *array, int size) {
	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
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

//This function reads the data.txt file
void readFile(int *arr, int size) {
	int numLines = 0;
	string line;

	//Open data.txt
	ifstream file("data.txt");

	//Get the number of lines
	while(getline(file, line)) {
		++numLines;
	}

	//Close and open again so that it's pointing to the beginning of the file
	file.close();
	file.open("data.txt");

	int count = 0, x;

	//Collect all of the ints into one big array
	while(count < 1000 && file >> x) {
		arr[count] = x;
		count++;
	}

	int arrSize = arr[0];
	int mainArrayIndex = 1;
	int *tempArray;

	//For loop runs numLines times
	for(int i = 0; i < numLines; i++) {
		//tempArray is initalized with the correct number of values
		tempArray = new int[arrSize];

		//This for loop collects all of the ints that pertain to each line
		for(int j = 0; j < arrSize; j++) {
			tempArray[j] = arr[mainArrayIndex];
			mainArrayIndex++;
		}

		//Each array gets sorted and then printed
		mergeSort(tempArray, 0, arrSize - 1);
		print_array(tempArray, arrSize);

		//arrSize is changed to the next line of ints
		arrSize = arr[mainArrayIndex];
		mainArrayIndex++;

		//To free memory
		delete[] tempArray;
	}

	//File closed
	file.close();
}

//The main function
int main(int argc, char **argv) {
	//Set size to a large number
	int size = 1000;

	//Intialize a new array
	int *array = new int[size];

	//Call this function to read the file
	readFile(array, size);

	//Delete the array for memory
	delete[] array;

	return 0;
}
