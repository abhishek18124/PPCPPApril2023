// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	int answer[100]; // based on the constraint

	// // time : O(n^2)

	// for(int i=0; i<n; i++) {

	// 	// l_i : product of all the elements in nums from 0 to i-1
	// 	int l_i = 1;
	// 	for(int j=0; j<=i-1; j++) {
	// 		l_i *= nums[j];
	// 	}

	// 	// r_i : produce of all the elements in nums from i+1 to n-1
	// 	int r_i = 1;
	// 	for(int j=i+1; j<=n-1; j++) {
	// 		r_i *= nums[j];
	// 	}

	// 	// to compute l_i and r_i, we will perform n-1 multiplication

	// 	answer[i] = l_i * r_i;

	// }

	// n-steps

	int l[100];
	l[0] = 1;
	for(int i=1; i<=n-1; i++) {
		l[i] = l[i-1]*nums[i-1];
	}

	// n-steps

	int r[100];
	r[n-1] = 1;
	for(int i=n-2; i>=0; i--) {
		r[i] = r[i+1]*nums[i+1];
	}

	// n-steps

	for(int i=0; i<=n-1; i++) {
		answer[i] = l[i]*r[i];
	}

	// total steps  = 3.n and each step takes O(1) therefore time = O(n)
	// extrac space for l[] and r[] = n+n = 2.n O(n)


	for(int i=0; i<n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;
	
	return 0;
}