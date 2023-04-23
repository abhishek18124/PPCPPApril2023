#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// for(int i=1; i<=n; i++) {

	// 	// in the ith row, print 'i' numbers in the increasing order starting with 1

	// 	for(int j=1; j<=i; j++) {
	// 		cout << j << " ";
	// 	}

	// 	cout << endl;

	// }

	for(int i=1; i<=n; i++) {

		// in the ith row, print 'i' numbers in the increasing order starting with 1

		// int num = 1;

		// for(int j=1; j<=i; j++) {
		// 	cout << num << " ";
		// 	num++;
		// }

		for(int j=1, ; j<=i; j++, num++) {
			cout << num << " ";
		}

		cout << endl;

	}

	return 0;
}