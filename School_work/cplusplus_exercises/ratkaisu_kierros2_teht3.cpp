#include <iostream>
using namespace std;

int min1(int x, int y);
int min2(int x, int y, int z);
int min3(int x, int y, int z, int w);

int main() {
	int x = 7, y = 6, z = 5, w = 2;
	int result;
	result = min1(x, y); // checks smallest between x and y
	cout << result << endl;
	result = min2(x, y, z); // checks smallest between x, y and z
	cout << result << endl;
	result = min3(x, y, z, w); // checks smallest between x,y,z and w
	cout << result;
	return 0;
}

int min1(int x, int y) {
	int result;
	result = min(x, y);
	return result;
}

int min2(int x, int y, int z) {
	int result;
	result = min1(x, y);
	result = min(result, z);
	return result;
}

int min3(int x, int y, int z, int w) {
	int result;
	result = min1(x, y);
	result = min2(result, z, w);
	return result;
}