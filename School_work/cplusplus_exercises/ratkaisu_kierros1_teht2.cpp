#include <iostream>
using namespace std;

void swap(int* num, int* num_2) {
	int temp;
	temp = *num;
	*num = *num_2;
	*num_2 = temp;
}

void swap2(int &num_3,int &num_4) {
	int temp;
	temp = num_3;
	num_3 = num_4;
	num_4 = temp;
}

int main() {
	int num = 1, num_2 = 2, num_3 = 3, num_4 = 4;
	cout << "num on " << num << endl;
	cout << "num_2 on " << num_2 << endl;
	cout << "num_3 on " << num_3 << endl;
	cout << "num_4 on " << num_4 << endl;
	swap(num, num_2);
	swap2(num_3, num_4);
	cout << "num on " << num << endl;
	cout << "num_2 on " << num_2 << endl;
	cout << "num_3 on " << num_3 << endl;
	cout << "num_4 on " << num_4 << endl;
	return 0;
}