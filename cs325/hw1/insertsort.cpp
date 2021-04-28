#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

//This function prints an array
void print_array(int *array, int size) {
	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

//The sorting function that does all the work
void insertionSort(int *arr, int size) {
	//Initialize variables to be used in function
	int i, j, val;
	//For loop that runs for the size of the array
	for(i = 1; i < size; i++) {
		//The first val looked at is arr[i]
		val = arr[i];
		//Set j to less than 1 every iteration
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
		tempArray = new int[arrSize];

		//This for loop collects all of the ints that pertain to each line
		for(int j = 0; j < arrSize; j++) {
			tempArray[j] = arr[mainArrayIndex];
			mainArrayIndex++;
		}

		//Each array gets sorted and then printed
		insertionSort(tempArray, arrSize);
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

	//Initialize an array to hold all of the ints
	int *array = new int[size];

	//call readFile to begin
	readFile(array, size);

	//Delete the array for memory
	delete[] array;

	return 0;
}
