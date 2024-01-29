// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int* arr, int s, int e) {

	int j = s;
	int i = j - 1; // represent the right boundary of the left partition

	int pivot = arr[e];

	while (j < e) {

		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}

		j++;

	}

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

void quickSort(int* arr, int s, int e) {

	// base case
	if (s >= e) {
		return;
	}

	// recursive case

	int m = partition(arr, s, e);

	quickSort(arr, s, m - 1);
	quickSort(arr, m + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}