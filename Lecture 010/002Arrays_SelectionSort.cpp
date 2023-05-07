#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	// iterate over the n-1 passes starting from the 0th pass and going towards the (n-2)th pass

	for(int i=0; i<n-1; i++) {

		// in the ith pass, we have to place the smallest element in the unsorted part of the array to its correct position

		int min_idx = i;

		for(int j=i+1; j<n; j++) {

			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}

		}

		swap(arr[min_idx], arr[i]); // ith index is the correct position for the smallest value in the unsorted part of the array in the ith pass

	}
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}