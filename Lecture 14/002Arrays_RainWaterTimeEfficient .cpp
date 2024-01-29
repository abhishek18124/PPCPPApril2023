// n <= 100

#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// total time : n+n+n = 3.n ~ O(n)
	// extra space : n+n = 2n ~ O(n)

	// int l[100];
	// l[0] = h[0];
	// for (int i = 1; i < n; i++) {
	// 	l[i] = max(l[i - 1], h[i]);
	// }

	int r[100];
	r[n - 1] = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int l_i = h[0];

	for (int i = 0; i < n; i++) {

		// compute the rainwater trapped on top of the ith building

		l_i = max(l_i, h[i]);
		int w_i = min(l_i, r[i]) - h[i];
		total += w_i;

	}

	cout << total << endl;

	return 0;
}