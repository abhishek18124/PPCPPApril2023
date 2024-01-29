#include<iostream>

using namespace std;

int f2(int* x, int i) {

	// base case

	// if (i == 0) {
	// 	// compute the sum of x[0...0] = {x[0]}
	// 	return x[0]; // or x[i]
	// }

	if (i == -1) {
		// compute the sum of x[0...-1] = {}
		return 0;
	}

	// recursive case

	// compute the sum of x[0...i]

	// 1. ask your friend to compute the sum of x[0...i-1]

	int A = f2(x, i - 1);

	return A + x[i];

}

int f3(int* x, int s, int e) {

	// base case

	// if (s == e) {
	// 	// compute the sum of x[s..s] = {x[s]}
	// 	return x[s]; // or x[e]
	// }

	if (s > e) {
		return 0;
	}

	// recursive case

	// compute the sum of x[s...e]

	int m = s + (e - s) / 2;

	// 1. ask your friend to compute sum of x[s...m]
	int A = f3(x, s, m);

	// 2. ask your friend to compute sum of x[m+1...e]
	int B = f3(x, m + 1, e);

	return A + B;

}

int main() {

	int x[] = {10, 20, 30, 40, 50};
	int n = sizeof(x) / sizeof(int);

	cout << f2(x, n - 1) << endl;

	cout << f3(x, 0, n - 1) << endl;

	return 0;
}