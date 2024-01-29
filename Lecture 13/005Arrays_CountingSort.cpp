// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

int main() {	

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);
	
	int k = 3; // denotes the maximum element in the array

	int count[10]; // based on the constraints

	memset(count, 0, sizeof(count));

	// n-steps

	for(int i=0; i<n; i++) {
		count[arr[i]]++;
	}

	// for(int i=0; i<=k; i++) {
	// 	cout << i << " : " << count[i] << endl;
	// }

	// n-steps : across all the values of 'i', inner loop will run 'n' times to print 'n' values of the output

	for(int i=0; i<=k; i++) {
		int x = count[i];
		// print the value 'i' x times
		
		// while(x--) {
		// 	cout << i << " ";
		// }

		for(int j=1; j<=x; j++) {
			cout << i << " ";
		}

	}

	cout << endl;

	// total time : 2.n ~ O(n) total space : k+1 ~ O(k)

	return 0;
}