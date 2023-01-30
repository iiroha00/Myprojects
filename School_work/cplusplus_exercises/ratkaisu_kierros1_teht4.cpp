#include <iostream>
using namespace std;

void swap(int* num, int* num_2) {
	int temp;
	temp = *num;
	*num = *num_2;
	*num_2 = temp;
}

int main() {
	int array[10];
	int num = 0;
	int* array_p = array;
	for (int i = 0; i < 10; i++) {
		array[i] = num + 1;
		num++;
	}
	int num2 = 9;
	for (int i = 0; i < 5; i++) {
		swap(array_p + i, array_p + num2);
		num2--;
	}
	cout << "Array flipped: ";
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	return 0;
}