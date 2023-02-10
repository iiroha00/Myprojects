#include <iostream>
#include <fstream>
using namespace std;


int main() {
	int count=0, sum=0, number;
	double average;
	ifstream file;
	string filename = "random.txt";
	file.open(filename);
	if (!file) {
		cout << "file open failure";
		return 0;
	}
	while (file >> number) {
		sum = number + sum;
		count++;
	}
	average = sum / count;
	cout << "The sum of the numbers in the file is " << sum << endl;
	cout << "The amount of numbers in the file is " << count << endl;
	cout << "The average of the numbers is " << average << endl;

	file.close();
	

	return 0;
}