#include<iostream>

using namespace std;

bool flag = false; // assume 't' is not present

void f(int* x, int n, int t, int i) {

	// base case

	if (i == n) {

		if (flag == false) {
			cout << -1 << " ";
		}

		return; // mandatory

	}

	// recursive case

	// find the index of the 1st occ. of the 't' in x[i...n-1]

	if (x[i] == t) {
		flag = true;
		cout << i << " ";

	}

	// ask your friend to find the index of the 1st occ. of the 't' in x[i+1...n-1]

	f(x, n, t, i + 1);

	return; // optional

}

int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 200;

	f(x, n, t, 0);

	return 0;
}