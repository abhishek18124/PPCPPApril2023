// https://leetcode.com/problems/largest-number/
// avoid leading zeros

#include<iostream>
#include<algorithm>

using namespace std;

bool myComparator(int a, int b) {

	string s_a = to_string(a);
	string s_b = to_string(b);

	string x = s_a + s_b;
	string y = s_b + s_a;

	if (x > y) {
		// you don't a swap to sort x_arr[] in decreasing order
		return true;
	}

	// you need a swap to sort x_arr[] in decreasing order
	return false;
}

int main() {

	int arr[] = {0, 0, 0, 0};
	int n = sizeof(arr) / sizeof(int);

	sort(arr, arr + n, myComparator);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}