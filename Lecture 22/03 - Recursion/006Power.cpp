#include<iostream>

using namespace std;

int power(int x, int y) {

	// base case
	if (y == 0) {
		// compute x^0
		return 1;
	}

	// recursive case

	// 1. ask your friend to compute x^(y-1)

	int A = power(x, y - 1);

	return x * A;

}

int powerEfficient(int x, int y) {

	// base case
	if (y == 0) {
		// compute x^0
		return 1;
	}

	// recursive case

	// 1. ask your friend to compute x^(y/2)

	int A = powerEfficient(x, y / 2);

	if (y % 2 == 0) {
		return A * A;
	}

	// y is odd

	return x * A * A;

}

int main() {

	int x = 3;
	int y = 4;

	cout << power(x, y) << endl;

	cout << powerEfficient(x, y) << endl;

	return 0;
}