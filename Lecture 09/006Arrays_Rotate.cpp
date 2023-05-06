#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	// approach 1 

	// // time : O(n)

	// // 1. save the last element in 'temp' variable
	// int temp = arr[n-1];

	// // 2. shift the remaining elements in the index range [0 to n-2] 1-step to the right
	
	// // total steps = (n-1) total work = (n-1).c

	// for(int i=n-1; i>=1; i--) {
	// 	arr[i] = arr[i-1]; // const. work O(1)
	// }

	// // 3. assign the 'temp' value to the 0th index
	// arr[0] = temp;

	// approach 2 

	// total steps = n-1 ~ O(n)

	swap(arr[0], arr[n-1]);

	for(int i=n-1; i>=2; i--) {
		swap(arr[i], arr[i-1]);
	}

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}