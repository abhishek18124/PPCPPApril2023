#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// iterate over all the possible starting indices of the subarrays

	for(int i=0; i<=n-1; i++) {

		// for given starting index 'i', iterate over all the possible ending indices of the subarrays

		for(int j=i; j<=n-1; j++) {

			// cout << i << " " << j << endl;

			// generate the subarray that starts at the ith index and ends at the jth index

			for(int k=i; k<=j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;

		}

		cout << endl;

	}

	return 0;
}