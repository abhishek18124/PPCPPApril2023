#include<iostream>

using namespace std;

int f(int* x, int t, int s, int e) {

	// base case
	if (s > e) {
		// search space is empty
		return -1;
	}

	// reucursive case

	int m = s + (e - s) / 2;

	if (x[m] == t) {
		return m;
	} else {
		if (t < x[m]) {
			// recursively search for the 't' in the x[s...m-1]
			return f(x, t, s, m - 1);
		} else { // t > x[m]
			// recurisvely search for the 't' in the x[m+1...e]
			return f(x, t, m + 1, e);
		}
	}

}

int main() {

	int x[] = {10, 20, 30, 40, 50};
	int n = sizeof(x) / sizeof(int);
	int t = 60;

	cout << f(x, t, 0, n - 1) << endl;

	return 0;
}