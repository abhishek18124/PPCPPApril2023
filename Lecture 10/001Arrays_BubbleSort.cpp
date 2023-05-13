#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	// iterate over the (n-1) passes starting from the 1st pass and going towards the (n-1)th pass
	for(int i=1; i<=n-1; i++) {

		// in ith the pass, we've to place the largest element in the unsorted
		// part of the array to its correct position

		bool flag = false; // assume no swaps will be done in the ith pass

		for(int j=0; j<n-i; j++) {
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				flag = true;
			}
		}

		if(flag == false) {
			// our initial assumption that no swaps will be done in the ith pass was correct
			break;
		}

	}
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}