/*

Example :
	Input : n = 5, x = 4
			w[] = {1, 2, 3, 2, 2}
			p[] = {8, 4, 1, 5, 3}
	Output: 13

*/


#include<iostream>
#include<vector>

using namespace std;

int helper(vector<int>& weights, vector<int>& profits,
           int n, int i, int w) {

	// base case

	if (i == n) {
		return 0;
	}

	if (w == 0) { // mandatory
		return 0;
	}

	// recursive case

	// make a decision for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return helper(weights, profits, n, i + 1, w);
	}

	// 1. include the ith object into the knapsack
	int x = helper(weights, profits, n, i, w - weights[i]);

	// 2. exclude the ith object from the knapsack
	int y = helper(weights, profits, n, i + 1, w);

	return max(profits[i] + x, y);

}

int helperBottomUp(vector<int>& weights, vector<int>& profits, int N, int W) {

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

	// for (int i = 0; i <= N; i++) {
	// 	dp[i][0] = 0;
	// }

	// for (int w = 0; w <= W; w++) {
	// 	dp[N][w] = 0;
	// }

	for (int i = N - 1; i >= 0; i--) {

		for (int w = 1; w <= W; w++) {

			// dp[i][w] = f(i, w)

			// make a decision for the ith object

			if (weights[i] > w) {
				// exclude the ith object from the knapsack
				dp[i][w] = dp[i + 1][w];
			} else {
				// 1. include the ith object into the knapsack
				int x = dp[i][w - weights[i]];

				// 2. exclude the ith object from the knapsack
				int y = dp[i + 1][w];

				dp[i][w] = max(profits[i] + x, y);

			}

		}

	}

	return dp[0][W]; // at this index, we store f(0, W)

}

// time : O(N+1.W+1) ~ O(N.W)
// space : O(W) ~ O(W)

int helperBottomUpSpaceOptimised2(vector<int>& weights, vector<int>& profits,
                                  int N, int W) {

	vector<int> dp(W + 1, 0); // next i.e. (i+1)th row

	for (int i = N - 1; i >= 0; i--) {

		for (int w = 1; w <= W; w++) {

			// dp[i][w] = f(i, w)

			// make a decision for the ith object

			if (weights[i] > w) {
				// exclude the ith object from the knapsack

				// dp[i][w] = dp[i + 1][w];

				// curr[w] = next[w];

				dp[w] = dp[w];

			} else {
				// 1. include the ith object into the knapsack

				// int x = dp[i][w - weights[i]];
				int x = dp[w - weights[i]];

				// 2. exclude the ith object from the knapsack

				// int y = dp[i + 1][w];

				int y = dp[w];

				// dp[i][w] = max(profits[i] + x, y);

				// curr[w] = max(profits[i] + x, y);

				dp[w] = max(profits[i] + x, y);

			}

		}

	}

	// return dp[0][W]; // at this index, we store f(0, W)

	return dp[W];

}



int main() {

	int N = 3;
	int W = 10;

	vector<int> weights = {6, 3, 8};
	vector<int> profits = {3, 1, 4};

	cout << helper(profits, weights, N, 0, W) << endl;

	cout << helperBottomUp(profits, weights, N, W) << endl;

	cout << helperBottomUpSpaceOptimised2(profits, weights, N, W) << endl;

	return 0;
}