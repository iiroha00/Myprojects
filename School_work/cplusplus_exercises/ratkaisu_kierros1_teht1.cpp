#include <iostream>
using namespace std;

int main() {
	//a
	int num, *num_p = &num; 
	//b
	*num_p = 7;
	//c
	cout << &num_p << endl; // Prints the address of num_p
	cout << &num << endl; // Prints the address of num
	cout << num_p << endl; // prints the content of num_p
	cout << num << endl; // Prints the content of num
	//&num and num_p are the same as they should be.
	
	//d 
	cout << *&num << endl; //prints the contents of num instead of the address because * and & cancel each other out as i understand it
	cout << &*num_p << endl; // prints the address of num because & and * cancel each other.

	//e
	cout << sizeof(num) << endl; //prints the sizeof num in bytes
	cout << sizeof(num_p) << endl; // prints the sizeof num_p in bytes
	//g
	int *numptr;
	//h
	//cout << *numptr << endl; //This part give an error in visual studio doenst let me run the code because uninitialized variable
	//i
	numptr = nullptr;
	//cout << *numptr << endl;
	//visual studio debugger give exception thrown: read access violation numptr was nullptr
	//doesnt print anything when ran without debuggin
	return 0;
}