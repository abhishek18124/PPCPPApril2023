#include<iostream>
#include<algorithm>

using namespace std;

// time : O(m.logn)

bool search(int mat[][3], int m, int n, int t) { // or int (*mat)[3]

	for (int i = 0; i < m; i++) {

		// check if 't' is present in the ith row using binary search

		if (binary_search(mat[i], mat[i] + n, t)) { // mat[i]+n is equal to mat[i+1] i.e. &mat[i+1][0]
			return true;
		}

	}

	// 't' not found
	return false;

}

int main() {

	int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 20;

	search(mat, m, n, t) ? cout << t << " found!" << endl :
	                            cout << t << " not found!" << endl;

	return 0;
}