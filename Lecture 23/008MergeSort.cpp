// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int* arr, int s, int m, int e) {

	int i = s;
	int j = m + 1;
	int k = s;

	int crr[100];

	while (i <= m and j <= e) {

		if (arr[i] < arr[j]) {
			crr[k] = arr[i];
			i++;
			k++;
		} else {
			crr[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {
		crr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		crr[k] = arr[j];
		j++;
		k++;
	}

	for (int l = s; l <= e; l++) {
		arr[l] = crr[l];
	}

}

void mergeSort(int* arr, int s, int e) {

	// base case

	// recursive case
	if (s == e) {
		// sort the arr[s...s] = {arr[s]} -> already sorted
		return;
	}

	// sort the arr[s...e]

	// 1. divide the arr[] around the midPoint
	int m = s + (e - s) / 2;

	// 2. recursively sort the two subarrays arr[s...m] and arr[m+1...e]

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	// 3. merge the two sorted subarrays
	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}