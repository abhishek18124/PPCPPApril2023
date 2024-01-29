// constraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	// time : O(n) space : O(n)

	// int X[100];
	// X[0] = arr[0];
	// int maxSum = X[0];

	// for(int i=1; i<=n-1; i++) {
	// 	X[i] = max(X[i-1]+arr[i], arr[i]);
	// 	maxSum = max(maxSum, X[i]);
	// }

	// time : O(n) space : O(1)

	int X;
	X = arr[0];
	int maxSum = X;

	for(int i=1; i<=n-1; i++) {
		X = max(X+arr[i], arr[i]);
		maxSum = max(maxSum, X);
	}

	cout << maxSum << endl;

	return 0;
}