#include <iostream>

using namespace std;

int main() {
	int array_stack[10];
	int *array_heap;
	array_heap = new int[10];

	for (int i = 0; i < 10; i++) {
		array_stack[i] = i;
		array_heap[i] = i + 1;
	}

	cout << "Stack array pointer lives: " << &array_stack << endl;
	cout << "Heap array pointer lives: " << &array_heap << endl;

	cout << "Stack array begins here: " << array_stack << endl;
	cout << "Heap array begins here: " << array_heap << endl;

	cout << "Third element of stack array: " << array_stack[2] << endl;
	cout << "Third element of heap array: " << array_heap[2] << endl;

	delete [] array_heap;

	return 0;
}
