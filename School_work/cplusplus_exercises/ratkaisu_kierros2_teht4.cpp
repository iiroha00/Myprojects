#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int x);
bool prime_all(int x);
bool prime_half(int x);
bool prime_square_root(int x);

int main() {
	double numberof=0, size=10000;
	double procentageof;
	bool result;
	for (int i = 1; i <= size; i++) {
		result=prime_square_root(i); // change function name here to check other functions
		if (result == true) {
			numberof++;
			cout << i << endl;
		}
	}
	procentageof = (numberof / size) * 100;
	cout << "There was " << numberof << " prime numbers" << endl;
	cout << "Procentage of primes was: " << procentageof << endl;
	return 0;
}

bool isPrime(int x) {
	if (x <= 1) {
		return false;
	}
	for (int i = 2; i < x; i++) {
		if (1==x/x&&x==x/1) {
			if (x % i == 0) {
				return false;
			}
		}
	}
	return true;
}
bool prime_all(int x) {
	if (x <= 1) {
		return false; 
	}
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
bool prime_half(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i <= x / 2; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
bool prime_square_root(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i <=sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}