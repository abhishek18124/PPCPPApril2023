#include<iostream>
#include<algorithm>

using namespace std;
/*

	assume currently, idx(a) < idx(b)

	this fn. will return true when swap is not required
	and it will return false when swap is required

*/

bool myComparator(string a, string b) {

	// if (a > b) {

	// 	// you don't need a swap to sort the arr[] in the decreasing order
	// 	return true;

	// }

	// // you need a swap to sort the arr[] in decreasing order

	// return false;

	return a > b;

}

bool myIntegerCompartor(int a, int b) {

	// if (a > b) {

	// 	// you don't need a swap to sort brr[] in decreasing order
	// 	return true;
	// }

	// // you need a swap to sort brr[] in decreasing order
	// return false;

	return a > b;

}

int main() {

	string arr[] = {"abc", "ghi", "jkl", "def"};
	int n = 4;

	// sort(arr, arr + n);
	// sort(arr, arr + n, greater<string>());
	sort(arr, arr + n, myComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	int brr[] = {10, 5, 4, 2, 20};

	int m = 5;

	// sort(brr, brr + m, greater<int>());
	sort(brr, brr + m, myIntegerCompartor);

	for (int i = 0; i < m; i++) {
		cout << brr[i] << " ";
	}

	cout << endl;

	return 0;
}