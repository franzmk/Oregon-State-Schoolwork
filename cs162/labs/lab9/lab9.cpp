#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void input(int &size) {
	do {
		cout << "Size of array (less than 20): ";
		cin >> size;
	} while(size > 20);
}

void fill_array(int *array, int size) {
	srand(time(NULL));

	for(int i = 0; i < size; i++) {
		array[i] = (rand() % 50) + 1;
	}
}

void print_array(int *array, int size) {
	cout << "Array values: ";
	for(int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void copy_array(int *array_copy, int *array, int size) {
	for(int i = 0; i < size; i++) {
		array_copy[i] = array[i];
	}
}

void merge(int *arr, int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 =  r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	 *        are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	   are any */
	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
 * *    sub-array of arr to be sorted */

void mergeSort(int *arr, int l, int r) { 
	if (l < r) { 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 
		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
}

void prime_numbers(int *array_copy, int size) {
	cout << "Prime numbers from the sorted list include: " << endl;
	for(int i = 0; i < size; i++) {
		int count = 0;
		for(int j = 2; j < array_copy[i]; j++) {
			if(array_copy[i] % j == 0) count++;
		}
		if(count <= 1) cout << array_copy[i] << " ";
	}
	cout << endl;
}

int main() {
	int size = 0;

	input(size);

	int *array = new int[size];

	fill_array(array, size);

	print_array(array, size);

	int *array_copy = new int[size];

	copy_array(array_copy, array, size);

	mergeSort(array_copy, 0, size - 1);

	print_array(array_copy, size);

	prime_numbers(array_copy, size);

	return 0;
}
