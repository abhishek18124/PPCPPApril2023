
// n <= 100

#include<iostream>

using namespace std;

int main() {

	// int arr[] = {10, 20, 30, 10, 20};
	// int n = sizeof(arr) / sizeof(int);

	// int t = 20;

	int arr[100]; // based on the constraints

	int n;
	cout << "enter the number of elements in the array : ";
	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}

	int t;
	cout << "enter the target : ";
	cin >> t;

	// time : O(n)

	int i;

	for(i=0; i<n; i++) {
		if(arr[i] == t) {
			// you've found the first occ. of the 't' at index 'i'
			cout << i << endl;
			break;
		}
	}

	if(i == n) {
		cout << -1 << endl;
	}

	return 0;
}