
// https://leetcode.com/problems/split-array-largest-sum/

#include<iostream>

using namespace std;

class Solution {
public:

	int helper(vector<int>& nums, int n, int k, int i) {

		// base case

		// if (i == n) {

		// 	// you've partitioned the array

		// 	if (k == 0) {

		// 		// you've built a valid partition

		// 		return 0;

		// 	}

		// 	// you've built an invalid partition

		// 	return INT_MAX;

		// }

		if (k == 0) {

			// you've partitioned the array

			if (i == n) {

				// you've built a valid partition

				return 0; // or INT_MIN

			}

			// you've built an invalid partition

			return INT_MAX;

		}

		// recursive case

		// find the minimized largest sum upon partitioning nums[i...n-1] into k non-empty subarrays

		int ans = INT_MAX; // to track the minimized largest sum
		int sum = 0;       // to track the sum of nums[i...j]

		// decide where to make the next cut

		for (int j = i; j <= n - k; j++) {

			// make the next cut at the jth index and recursively find the
			// minimized largest sum upon partitioning nums[j+1...n-1] into k-1 non-empty subarrays

			sum += nums[j];
			ans = min(ans, max(sum, helper(nums, n, k - 1, j + 1)));

		}

		return ans;

	}

	int helperTopDown(vector<int>& nums, int n, int k, int i, vector<vector<int>>& dp) {

		// lookup

		if (dp[i][k] != -1) {
			return dp[i][k];
		}

		// base case

		if (k == 0) {

			// you've partitioned the array

			if (i == n) {

				// you've built a valid partition

				return dp[i][k] = 0;

			}

			// you've built an invalid partition

			return dp[i][k] = INT_MAX;

		}

		// recursive case

		// find the minimized largest sum upon partitioning nums[i...n-1] into k non-empty subarrays

		int ans = INT_MAX; // to track the minimized largest sum
		int sum = 0;       // to track the sum of nums[i...j]

		// decide where to make the next cut

		for (int j = i; j <= n - k; j++) {

			// make the next cut at the jth index and recursively find the
			// minimized largest sum upon partitioning nums[j+1...n-1] into k-1 non-empty subarrays

			sum += nums[j];
			ans = min(ans, max(sum, helperTopDown(nums, n, k - 1, j + 1, dp)));

		}

		return dp[i][k] = ans;

	}

	int splitArray(vector<int>& nums, int K) {
		int n = nums.size();
		// return helper(nums, n, K, 0);
		vector<vector<int>> dp(n + 1, vector<int>(K + 1, -1));
		return helperTopDown(nums, n, K, 0, dp);
	}
};

int main() {

	vector<int> nums = {7, 2, 5, 10, 8};
	int K = 2;

	Solution s;

	cout << s.splitArray(nums, K) << endl;

	return 0;
}