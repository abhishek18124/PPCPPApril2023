#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

void f(int* x, int n, int t, int i) {

	// base case

	if (i == n) {

		return; // mandatory

	}

	// recursive case

	// find the index of the 1st occ. of the 't' in x[i...n-1]

	if (x[i] == t) {
		v.push_back(i);
	}

	// ask your friend to find the index of the 1st occ. of the 't' in x[i+1...n-1]

	f(x, n, t, i + 1);

	return; // optional

}

int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 20;

	f(x, n, t, 0);

	if (v.size() == 0) {
		cout << -1 << endl;
	} else {

		for (int occ_idx : v) {
			cout << occ_idx << " ";
		}

		cout << endl;

	}

	return 0;
}