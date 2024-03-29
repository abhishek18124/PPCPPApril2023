#include<iostream>
#include<vector>

using namespace std;

int f(vector<int> d, int i, int j) {

	// base case

	if (i == j) {
		return 0;
	}

	// recursive case

	int ans = INT_MAX;

	for (int k = i; k <= j - 1; k++) {

		// make a cut at the kth index

		ans = min(ans, f(d, i, k) + f(d, k + 1, j) + d[i - 1] * d[k] * d[j]);
	}

	return ans;

}

int TD(vector<int> d, int i, int j, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == j) {
		return dp[i][j] = 0;
	}

	// recursive case

	int ans = INT_MAX;

	for (int k = i; k < j; k++) {
		ans = min(ans, TD(d, i, k, dp) + TD(d, k + 1, j, dp) + d[i - 1] * d[k] * d[j]);
	}

	return dp[i][j] = ans;

}

// time : O(n^3)
// space : O(n^2)

int BU(vector<int> d, int n) {

	vector<vector<int>> dp(n + 1, vector<int>(n + 1)); // 0th row, and 0th col. is not used

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {

			int ans = INT_MAX;

			for (int k = i; k < j; k++) {
				ans = min(ans, dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
			}

			dp[i][j] = ans;

		}
	}

	return dp[1][n]; // f(1, n)

}

// dp[i][j] -> dp[i][k] and dp[k+1][j]

// k = i    : dp[i][j] -> dp[i][i] and dp[i+1][j]
// k = i+1  : dp[i][j] -> dp[i][i+1] and dp[i+2][j]
// k = i+2  : dp[i][j] -> dp[i][i+2] and dp[i+3][j]
// ...
// k = j-1  : dp[i][j] -> dp[i][j-1] and dp[j][j]


int main() {

	vector<int> d = {2, 1, 2, 4};

	int n = d.size() - 1;

	cout << f(d, 1, n) << endl;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

	cout << TD(d, 1, n, dp) << endl;

	cout << BU(d, n) << endl;

	return 0;
}