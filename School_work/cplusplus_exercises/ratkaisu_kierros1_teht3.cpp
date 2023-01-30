#include <iostream>
using namespace std;

void arrayAdd(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] = 1;
	}
}

void arrayAdd2(int *array_p, int size) {
	for (int i = 0; i < size; i++) {
		*(array_p + i) = 1;
	}
}


int main() {
	int array[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	cout << "Array before function: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i]<< " ";
	}
	arrayAdd(array, 10);
	cout << "\nArray after function 1: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	for (int i = 0; i < 10; i++) {
		array[i] = 0;
	}
	int *array_p = array;
	cout << "\nArray before function 2: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	arrayAdd2(array_p, 10);
	cout << "\nArray after function 2: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	return 0;
}