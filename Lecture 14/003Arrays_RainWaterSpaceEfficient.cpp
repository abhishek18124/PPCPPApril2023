#include<iostream>

using namespace std;

int main() {

	// time : O(n) space : O(1)

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int i = 0;
	int j = n - 1;

	int l = INT_MIN; // or 0 or h[0]   maximum of 0 to i
	int r = INT_MIN; // or 0 or h[n-1] maximum of j to n-1

	int total = 0;

	while (i <= j) {

		l = max(l, h[i]); // maximum of 0 to i
		r = max(r, h[j]); // maximum of j to n-1

		if (l < r) {
			// compute the rainwater trapped on top of the ith building
			int w_i = l - h[i];
			total += w_i;
			i++;
		} else {
			// compute the rainwater trapped on top of the jth building
			int w_j = r - h[j];
			total += w_j;
			j--;
		}

	}

	cout << total << endl;

	return 0;
}