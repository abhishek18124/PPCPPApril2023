#include<iostream>

using namespace std;

int helper(int N, int K, vector<vector<int>>& v, int i, int p) {

	// base case

	if (p == 0) {
		return 0;
	}

	if (i == N + 1) { // p != 0
		return INT_MIN;
	}

	// recursive case

	// compute the maximum beauty value we can obtain by choosing 'p'
	// plates from the given stack of plates starting from index 'i'

	// make a decision for the ith stack

	int ans = 0;

	for (int j = 0; j <= min(K, p); j++) {

		// pick 'j' plates from the ith stack

		ans = max(ans, v[i][j] + helper(N, K, v, i + 1, p - j));

	}

	return ans;

}

int helperTopDown(int N, int K, vector<vector<int>>& v, int i, int p, vector<vector<int>>& dp) {

	// base case

	if (p == 0) {
		return 0;
	}

	if (i == N + 1) {
		return INT_MIN;
	}

	// lookup

	if (dp[i][p] != -1) {
		return dp[i][p];
	}

	// recursive case

	// compute the maximum beauty value we can obtain by choosing 'p'
	// plates from the given stack of plates starting from index 'i'

	// make a decision for the ith stack

	int ans = 0;

	for (int j = 0; j <= min(K, p); j++) {

		// pick 'j' plates from the ith stack

		ans = max(ans, v[i][j] + helperTopDown(N, K, v, i + 1, p - j, dp));

	}

	return dp[i][p] = ans;

}

int helperBottomUp(int N, int K, int P, vector<vector<int>>& v) {

	vector<vector<int>> dp(N + 2, vector<int>(P + 1));

	for (int i = 1; i <= N + 1; i++) {
		dp[i][0] = 0;
	}

	for (int p = 1; p <= P; p++) {
		dp[N + 1][p] = INT_MIN;
	}

	for (int i = N; i >= 1; i--) {

		for (int p = 1; p <= P; p++) {

			// compute the maximum beauty value we can obtain by choosing 'p'
			// plates from the given stack of plates starting from index 'i'

			int ans = 0;

			for (int j = 0; j <= min(K, p); j++) {

				// pick 'j' plates from the ith stack

				ans = max(ans, v[i][j] + dp[i + 1][p - j]);

			}

			dp[i][p] = ans;

		}

	}

	return dp[1][P];

}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int N, K, P;
		cin >> N >> K >> P;

		vector<vector<int>> v(N + 1, vector<int>(K + 1));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				cin >> v[i][j];
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= K; j++) {
				v[i][j] += v[i][j - 1];
			}
		}

		// for (int i = 1; i <= N; i++) {
		// 	for (int j = 1; j <= K; j++) {
		// 		cout << v[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		// cout << helper(N, K, v, 1, P) << endl;

		// vector<vector<int>> dp(N + 2, vector<int>(P + 1, -1));

		// cout << helperTopDown(N, K, v, 1, P, dp) << endl;

		cout << helperBottomUp(N, K, P, v) << endl;
	}

	return 0;
}