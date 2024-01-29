#include<iostream>

using namespace std;

bool f(int* x, int n, int i) {

	// base case

	if (i == n - 1) {
		// check if x[n-1...n-1] = {x[n-1]} is sorted ?
		return true;
	}

	// recursive case

	// check if x[i...n-1] is sorted

	return x[i] < x[i + 1] and f(x, n, i + 1);

}

int main() {

	int x[] = {10, 20, 40, 30, 50};
	int n = sizeof(x) / sizeof(int);

	f(x, n, 0) ? cout << "array is sorted" << endl :
	                  cout << "array is not sorted" << endl;

	return 0;
}