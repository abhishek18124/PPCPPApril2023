#include<iostream>
#include<algorithm>

using namespace std;

int main() {	

	int h[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(h)/sizeof(int);

	int i = 0;
	int j = n-1;

	int maxArea = 0; // or INT_MIN

	while(i < j) {

		// compute the area of the container which uses the ith and jth line

		int a_ij = (j-i)*min(h[i], h[j]);
		maxArea = max(maxArea, a_ij);

		if(h[i] < h[j]) {
			i++;
		} else {
			j--;
		}


	}

	cout << maxArea << endl;

	return 0;
}