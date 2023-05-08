#include<iostream>
#include<climits>

using namespace std;

int main() {

	int arr[] = {20, 5, 0, 25, 15, 10};
	int n = sizeof(arr) / sizeof(int);

	int fL = INT_MIN; // to track the first largest so far
	int sL = INT_MIN; // to track the second largest so far
	int tL = INT_MIN; // to track the third largest so far

	// total work = n.c ~ O(n)

	for(int i=0; i<n; i++) {

		if(arr[i] > fL) {
			tL = sL;
			sL = fL;
			fL = arr[i];
		} else if(arr[i] > sL) {
			tL = sL;
			sL = arr[i];
		} else if(arr[i] > tL) {
			tL = arr[i];
		}

	}

	cout << fL << " " << sL << " " << tL << endl;

	return 0;
}