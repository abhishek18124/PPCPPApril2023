#include<iostream>

using namespace std;

int main() {

	int arr[] = {-10, -20, 1, 2, 3};
	int n = sizeof(arr) / sizeof(int);

	int fL = INT_MIN; // to track the first largest so far
	int sL = INT_MIN; // to track the second largest so far
	int tL = INT_MIN; // to track the third largest so far

	int fS = INT_MAX; // to track the first smallest so far
	int sS = INT_MAX; // to track the second smallest so far

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

		if(arr[i] < fS) {
			sS = fS;
			fS = arr[i];
		} else if(arr[i] < sS) {
			sS = arr[i];
		}

	}

	// cout << fL << " " << sL << " " << tL << " " << fS << " " << sS << endl;

	int p1 = fL*sL*tL;
	int p2 = fL*fS*sS;

	// if(p1 > p2) {
	// 	cout << p1 << endl;
	// } else {
	// 	cout << p2 << endl;
	// }

	cout << max(p1, p2) << endl;
	cout << max(fL*sL*tL, fL*fS*sS) << endl;

	cout << min(p1, p2) << endl;

	cout << max(10, max(20, 30)) << endl;
	cout << max({10, 20, 30}) << endl;

	cout << min(10, min(20, 30)) << endl;
	cout  << max({10, 20, 30}) << endl;


	return 0;
}