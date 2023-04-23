#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// for(int i=1; i<=n; i++) {

	// 	for(int j=1; j<=i; j++) {

	// 		// if((i+j)%2 == 0) {
	// 		// 	cout << 1 << " ";
	// 		// } else {
	// 		// 	cout << 0 << " ";
	// 		// }

	// 		(i+j)%2 == 0 ? cout << 1 << " " : cout << 0 << " ";

	// 	}

	// 	cout << endl;

	// }

	for(int i=1; i<=n; i++) {

		// for the ith row, print i numbers

		// if the ith row is even, starting printing numbers from 0 otherwise starting printing numbers from 1

		int num = i%2 == 0 ? 0 : 1;

		for(int j=1; j<=i; j++) {

			cout << num << " ";
			num = 1-num;
			// num = !num;

		}

		cout << endl;

	}

	return 0;
}