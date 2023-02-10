/*
1000 , 5000, 10000, 100 000, 1 000 000, bytes  succesful
10 000 000, 2 000 000, 1 500 000, 1 100 000 bytes unsuccesful

in dynamic memory:
1 000 000 bytes succesful
10 000 000 bytes succesful
50 000 000 bytes succesful
100 000 000 bytes succesful
1 000 000 000 bytes succesful and then unsuccesful

visual studio says this is not a valid win32 program after this on any size amount. So i cant run it anymore.
Also i think 1 000 000 000 bytes was succesful on dynamic memory the first time i did it.
I dont know how to fix this. I think i tested the memory allocation right.

My guess is if it was a win64 program it would allow me to allocate more memory.

*/

// I commented void m() away when testing dynamic mermory allocation and changed m() to m2() in main
#include <iostream>

using namespace std;
const int SIZE = 10;

char gArray[SIZE] = {};

void m();
void m2();

int main() {
	m();
	return 0;
}
void m() {
	char array[SIZE] = {};
	cout << sizeof(array) << endl;
	m2();
}
void m2() {
	char *array_p = new char[SIZE];
	delete[] array_p;
	array_p = nullptr;
}