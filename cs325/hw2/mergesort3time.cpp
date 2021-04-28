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

//GeeksforGeeks used as a reference for how to do merge sort in thirds
//The merge function that merges 3 parts
void merge(int origArray[], int lowBound, int firstMid, int secondMid, int upBound, int sortedArray[]) {
	//Initialize the bounds, these are used instead of splitting one array into 3 arrays
	int firstIndex = lowBound;
  	int secondIndex = firstMid;
  	int thirdIndex = secondMid;
  	int sortedIndex = lowBound;

	//This while loop will run while there is a smaller value in all three thirds of the array
	while (firstIndex < firstMid && secondIndex < secondMid && thirdIndex < upBound) {
		//This if statement will check if the int from the first third is less than the int from the second third
		if(origArray[firstIndex] < origArray[secondIndex]) {
			//If that's true, this if will check if the int from the first third is less than the int from the third third
			if(origArray[firstIndex] < origArray[thirdIndex]) {
				//If the int from the first third is the smallest, then it's added to the sorted array
				sortedArray[sortedIndex] = origArray[firstIndex];
				//The indexes for both the sorted array and the first third are incremented
        		sortedIndex++;
        		firstIndex++;
			//If the int from the third third is the smallest, then that int is added to the sorted array
			} else {
				sortedArray[sortedIndex] = origArray[thirdIndex];
				//The indexes for both the sorted array and the third third are incremented
        		sortedIndex++;
        		thirdIndex++;
			}
		//If the int from the second third is smaller than the int from the first third, this else is entered
		} else {
			//The int from the second third and the int from the third third are now compared
			if(origArray[secondIndex] < origArray[thirdIndex]) {
				//If the int from the second third is smaller, it's added to the sorted array
				sortedArray[sortedIndex] = origArray[secondIndex];
				//The indexes are incremented
        		sortedIndex++;
        		secondIndex++;
			} else { //If the int from the third third is the smallest, it gets added to the sorted array
				sortedArray[sortedIndex] = origArray[thirdIndex];
				//The indexes are incremented
        		sortedIndex++;
        		thirdIndex++;
			}
		}
	}

	//If there are any remaining ints in the first and second thirds, this while loop is entered
	while (firstIndex < firstMid && secondIndex < secondMid) {
		//Check if the int from the first third is smaller than the int from the second third
		if(origArray[firstIndex] < origArray[secondIndex]) {
			//If it is, the int from the first third is added to the sorted array
			sortedArray[sortedIndex] = origArray[firstIndex];
			//The indexes are incremented
      		sortedIndex++;
      		firstIndex++;
		} else { //If the int from the second third is smaller, it gets added to the sorted array
			sortedArray[sortedIndex] = origArray[secondIndex];
			//The indexes are incremented
      		sortedIndex++;
      		secondIndex++;
		}
	}

	//If there are still ints in the first and third thirds, this while loop is entered
	while (firstIndex < firstMid && thirdIndex < upBound) {
		//check if the int from the first third is smaller than the int from the third third
		if(origArray[firstIndex] < origArray[thirdIndex]) {
			//If it is, the int from the first third is added to the sorted array
			sortedArray[sortedIndex] = origArray[firstIndex];
			//The indexes are incremented
      		sortedIndex++;
      		firstIndex++;
		} else { //If not, the int from the third third is added to the sorted array
			sortedArray[sortedIndex] = origArray[thirdIndex];
			//The indexes are incremented
      		sortedIndex++;
      		thirdIndex++;
		}
	}

	//If there are still ints in the second and thir thirds, this while loop is entered
	while (secondIndex < secondMid && thirdIndex < upBound) {
		//Check if the int from the second third is smaller than the int from the third third
		if(origArray[secondIndex] < origArray[thirdIndex]) {
			//If it is, the int from the second third is added to the sorted array
			sortedArray[sortedIndex] = origArray[secondIndex];
			//The indexes are incremented
      		sortedIndex++;
      		secondIndex++;
		} else { //If not, the int from the third third is added to the sorted array
			sortedArray[sortedIndex] = origArray[thirdIndex];
			//The indexes are incremented
      		sortedIndex++;
      		thirdIndex++;
		}
	}

	//If the firstIndex is less than the first midpoint, there are still values to be sorted from the first third
	if (firstIndex < firstMid) {
		//For loop runs however many values are left
    	for(int i = 0; i < (firstMid - firstIndex); i++) {
			//The ints get added to the sorted array
      		sortedArray[sortedIndex] = origArray[firstIndex];
			//The indexes are incremented
      		sortedIndex++;
      		firstIndex++;
    	}
  	}

	//If the secondIndex is less than the second midpoint, there are still values to be sorted from the second third
	if (secondIndex < secondMid) {
		//For loop runs however many values are left
    	for (int i = 0; i < (secondMid - secondIndex); i++) {
			//The ints get added to the sorted array
      		sortedArray[sortedIndex] = origArray[secondIndex];
			//The indexes are incremented
      		sortedIndex++;
      		secondIndex++;
    	}
  	}

	//If the thirdIndex is less than the upper bound, there are still values to be sorted from the third third
	if (thirdIndex < upBound) {
		//For loop runs however many values are left
    	for (int i = 0; i < (upBound - thirdIndex); i++) {
			//The ints get added to the sorted array
      		sortedArray[sortedIndex] = origArray[thirdIndex];
			//The indexes are incremented
      		sortedIndex++;
      		thirdIndex++;
    	}
  	}
}


//This is the recursive function that splits the current array into thirds using indexes and math
void mergeSort3(int origArray[], int lowerBound, int upperBound, int sortedArray[]) {
	//If the array is size 1, return
	if (upperBound - lowerBound < 2) {
		return;
  	}

	//This is where the array is split into thirds, the indexes are calculated instead of actually splitting the array
	int firstThird = lowerBound + ((upperBound - lowerBound) / 3);
	int secondThird = lowerBound + 2 * ((upperBound - lowerBound) / 3) + 1;

	//Call mergeSort3 recursively, this will sort each third of the array
	//First third is lowerBound - firstThird
	mergeSort3(sortedArray, lowerBound, firstThird, origArray);
	//Second third is firstThird - secondThird
	mergeSort3(sortedArray, firstThird, secondThird, origArray);
	//Third third is secondThird - upperBound
	mergeSort3(sortedArray, secondThird, upperBound, origArray);

	//This will merge all parts of the array
	merge(sortedArray, lowerBound, firstThird, secondThird, upperBound, origArray);
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

		int tempArr[size];

		for(int k = 0; k < size; k++) {
			tempArr[k] = array[k];
		}

		//Initialize clock
		clock_t t1, t2;

		//Start the clock
		t1 = clock();
		//mergeSort3 function
		mergeSort3(tempArr, 0, size, array);
		//Stop the clock
		t2 = clock();

		//Calculate the time
		float diff = ((float) t2 - (float) t1);
		diff = diff / (CLOCKS_PER_SEC/1000);

		//Print the size and time
		cout << "mergeSort3 n = " << size << " in " << diff << " milliseconds" << endl;

		//Delete array for memory
		delete[] array;
		//Increase size by 10000
		size = size + 10000;
	}

	return 0;
}
