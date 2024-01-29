/*

given a number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>
#include<vector>

using namespace std;

int fibo(int n) {

	// base case
	if (n == 0 || n == 1) {
		return n;
	}

	// recursive case
	return fibo(n - 1) + fibo(n - 2);
}

int fiboTopDown(int n, vector<int>& dp) {

	// lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	// base case
	if (n == 0 || n == 1) {
		return dp[n] = n;
	}

	// recursive case

	return dp[n] = fiboTopDown(n - 1, dp) + fiboTopDown(n - 2, dp);

}

int fiboBottomUp(int n) {

	vector<int> dp(n + 1);

	dp[0] = 0; // at the 0th index of dp[], we store f(0)
	dp[1] = 1; // at the 1st index of dp[], we store f(1)

	for (int i = 2; i <= n; i++) {

		// dp[i] = f(i) : ith fibonacci number

		dp[i] = dp[i - 1] + dp[i - 2];

	}

	return dp[n]; // at the nth index of dp[], we store f(n)

}

int main() {

	int n = 7;

	cout << fibo(n) << endl;

	vector<int> dp(n + 1, -1);

	cout << fiboTopDown(n, dp) << endl;

	cout << fiboBottomUp(n) << endl;

	return 0;
}