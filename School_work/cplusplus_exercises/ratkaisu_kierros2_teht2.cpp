#include <iostream>
#include <cmath>
using namespace std;


int main() {
	double num, numup, numdown;
	cout << "Give a number: ";
	cin >> num;
	numup = ceil(num);
	numdown = floor(num);
	cout << "Number " << num << " is between " << numdown << " and " << numup << "." << endl;

	return 0;
}