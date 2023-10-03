#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {
		// you've build a valid partitioning
		return 0;
	}

	// recursive case

	// compute the largest sum upon partitioning arr[i...n-1] such that each subarray if of length <= k

	// decide the next cut

	int maxValue = INT_MIN; // to track the largest value in arr[i...j]
	int maxSoFar = INT_MIN; // to track the largest sum upon partitioning arr[i...n-1]

	for (int j = i; j < i + k and j < n; j++) {

		// make the next cut at the jth index
		maxValue = max(maxValue, arr[j]);
		maxSoFar = max(maxSoFar, (j - i + 1) * maxValue + helper(arr, n, k, j + 1));

	}

	return maxSoFar;

}


int helperTopDown(vector<int>& arr, int n, int k, int i, vector<int>& dp) {

	// lookup
	if (dp[i] != -1) {
		return dp[i];
	}

	// base case

	if (i == n) {
		// you've build a valid partitioning
		return dp[n] = 0;
	}

	// recursive case

	// compute the largest sum upon partitioning arr[i...n-1] such that each subarray if of length <= k

	// decide the next cut

	int maxValue = INT_MIN; // to track the largest value in arr[i...j]
	int maxSoFar = INT_MIN; // to track the largest sum upon partitioning arr[i...n-1]

	for (int j = i; j < i + k and j < n; j++) {

		// make the next cut at the jth index
		maxValue = max(maxValue, arr[j]);
		maxSoFar = max(maxSoFar, (j - i + 1) * maxValue + helperTopDown(arr, n, k, j + 1, dp));

	}

	return dp[i] = maxSoFar;

}

// time : O(n.k)

// space : O(n) due to the dp[]

int helperBottomUp(vector<int> arr, int n, int k) {

	vector<int> dp(n + 1);

	dp[n] = 0;

	for (int i = n - 1; i >= 0; i--) {


		int maxValue = INT_MIN; // to track the largest value in arr[i...j]
		int maxSoFar = INT_MIN; // to track the largest sum upon partitioning arr[i...n-1]

		for (int j = i; j < i + k and j < n; j++) {

			// make the next cut at the jth index
			maxValue = max(maxValue, arr[j]);
			maxSoFar = max(maxSoFar, (j - i + 1) * maxValue + dp[j + 1]);

		}

		dp[i] = maxSoFar;
	}

	return dp[0]; // at the 0th index of dp[], we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {
	int n = arr.size();
	// return helper(arr, n, k, 0);
	// vector<int> dp(n + 1, -1);
	// return helperTopDown(arr, n, k, 0, dp);
	return helperBottomUp(arr, n, k);
}

int main() {
	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;
	cout << maxSumAfterPartitioning(arr, k) << endl;
	return 0;
}