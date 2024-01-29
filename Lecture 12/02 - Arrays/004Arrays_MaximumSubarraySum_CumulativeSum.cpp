// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	int csum[101]; // based on the constaints
	csum[0] = 0;

	// no. of computations ~ n

	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + arr[i-1];
	}

	// for(int i=0; i<=n; i++) {
	// 	cout << csum[i] << " ";
	// }

	// cout << endl;

	// no. of computations ~ n^2

	int lsf = INT_MIN; // to track the maximum subarray sum

	// iterate over all the possible starting indices of the subarrays

	for(int i=0; i<n; i++) {

		// for any starting index 'i', iterate over all the possible ending indices

		for(int j=i; j<n; j++) {

			// compute the sum of the subarray that starts at the ith index and ends at the jth index

			int sum = csum[j+1]-csum[i];
			lsf = max(lsf, sum);

		}

	}

	cout << lsf << endl;

	// total computation ~ n+n^2 = O(n^2)



	return 0;
}