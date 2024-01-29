/*

Example :
	Input : N = 5, X = 4
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

	if (w == 0) { // optional
		return 0;
	}

	// recursive case

	// make a decision for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return helper(weights, profits, n, i + 1, w);
	}

	// 1. include the ith object into the knapsack
	int x = helper(weights, profits, n, i + 1, w - weights[i]);

	// 2. exclude the ith object from the knapsack
	int y = helper(weights, profits, n, i + 1, w);

	return max(profits[i] + x, y);

}


int helperTopDown(vector<int>& weights, vector<int>& profits,
                  int n, int i, int w, vector<vector<int>>& dp) {

	// lookup
	if (dp[i][w] != -1) {
		return dp[i][w];
	}

	// base case

	if (i == n) {
		return dp[i][w] = 0;
	}

	if (w == 0) { // optional
		return dp[i][w] = 0;
	}

	// recursive case

	// make a decision for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return dp[i][w] = helperTopDown(weights, profits, n, i + 1, w, dp);
	}

	// 1. include the ith object into the knapsack
	int x = helperTopDown(weights, profits, n, i + 1, w - weights[i], dp);

	// 2. exclude the ith object from the knapsack
	int y = helperTopDown(weights, profits, n, i + 1, w, dp);

	return dp[i][w] = max(profits[i] + x, y);

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
				int x = dp[i + 1][w - weights[i]];

				// 2. exclude the ith object from the knapsack
				int y = dp[i + 1][w];

				dp[i][w] = max(profits[i] + x, y);

			}

		}

	}

	return dp[0][W]; // at this index, we store f(0, W)

}


// time : O(N+1.W+1) ~ O(N.W)
// space : O(W+W) ~ O(W)

int helperBottomUpSpaceOptimised(vector<int>& weights, vector<int>& profits,
                                 int N, int W) {

	// vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

	// for (int i = 0; i <= N; i++) {
	// 	dp[i][0] = 0;
	// }

	// for (int w = 0; w <= W; w++) {
	// 	dp[N][w] = 0;
	// }

	vector<int> curr(W + 1);
	vector<int> next(W + 1, 0);

	for (int i = N - 1; i >= 0; i--) {

		for (int w = 1; w <= W; w++) {

			// dp[i][w] = f(i, w)

			// make a decision for the ith object

			if (weights[i] > w) {
				// exclude the ith object from the knapsack

				// dp[i][w] = dp[i + 1][w];

				curr[w] = next[w];

			} else {
				// 1. include the ith object into the knapsack

				// int x = dp[i + 1][w - weights[i]];
				int x = next[w - weights[i]];

				// 2. exclude the ith object from the knapsack

				// int y = dp[i + 1][w];

				int y = next[w];

				// dp[i][w] = max(profits[i] + x, y);

				curr[w] = max(profits[i] + x, y);

			}

		}

		// next = curr; // copy O(W)

		// swap(next, curr); // O(1)

		next.swap(curr);

	}

	// return dp[0][W]; // at this index, we store f(0, W)

	return next[W]; // or curr[W]

}


// time : O(N+1.W+1) ~ O(N.W)
// space : O(W) ~ O(W)

int helperBottomUpSpaceOptimised2(vector<int>& weights, vector<int>& profits,
                                  int N, int W) {

	vector<int> dp(W + 1, 0); // next i.e. (i+1)th row

	for (int i = N - 1; i >= 0; i--) {

		for (int w = W; w >= 1; w--) {

			// dp[i][w] = f(i, w)

			// make a decision for the ith object

			if (weights[i] > w) {
				// exclude the ith object from the knapsack

				// dp[i][w] = dp[i + 1][w];

				// curr[w] = next[w];

				dp[w] = dp[w];

			} else {
				// 1. include the ith object into the knapsack

				// int x = dp[i + 1][w - weights[i]];
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

	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

	cout << helper(weights, profits, N, 0, W) << endl;

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
	cout << helperTopDown(weights, profits, N, 0, W, dp) << endl;

	cout << helperBottomUp(weights, profits, N, W) << endl;

	cout << helperBottomUpSpaceOptimised(weights, profits, N, W) << endl;

	cout << helperBottomUpSpaceOptimised2(weights, profits, N, W) << endl;

	return 0;
}