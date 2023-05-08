#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int k = 3;

	k = k%n;

	// // time : O(kn)

	// for(int j=1; j<=k; j++) {

	// 	// rotate the array the once in the clockwise direction

	// 	// 1. save the last element in 'temp' variable
	// 	int temp = arr[n-1];

	// 	// 2. shift the remaining elements in the index range [0 to n-2] 1-step to the right
		
	// 	// total steps = (n-1) total work = (n-1).c

	// 	for(int i=n-1; i>=1; i--) {
	// 		arr[i] = arr[i-1]; // const. work O(1)
	// 	}

	// 	// 3. assign the 'temp' value to the 0th index
	// 	arr[0] = temp;

	// }

	// approach 2 - time : O(n)

	// 1. reverse the entire array

	int i = 0;
	int j = n-1;

	while(i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// 2. reverse the first k elements

	i = 0;
	j = k-1;

	while(i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	// 3. reverse the last n-k elements

	i = k;
	j = n-1;

	while(i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}