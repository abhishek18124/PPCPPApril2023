/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> prices, int i, int j, int y) {

	// base case

	if (i == j) {
		return y * prices[i]; // or y * prices[j] // y is equal to n
	}

	// recursive case

	// make a decision for the yth year

	// 1. sell the ith bottle of wine

	int x = maxProfit(prices, i + 1, j, y + 1);

	// 2. sell the jth bottle of wine

	int z = maxProfit(prices, i, j - 1, y + 1);

	return max(y * prices[i] + x, y * prices[j] + z);

}

int maxProfitTopDown(vector<int> prices, int i, int j, int y, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		// you've already computed result for f(i, j)
		return dp[i][j];
	}

	// base case

	if (i == j) {
		return dp[i][j] = y * prices[i]; // or y * prices[j] // y is equal to n
	}

	// recursive case

	// make a decision for the yth year

	// 1. sell the ith bottle of wine

	int x = maxProfitTopDown(prices, i + 1, j, y + 1, dp);

	// 2. sell the jth bottle of wine

	int z = maxProfitTopDown(prices, i, j - 1, y + 1, dp);

	return dp[i][j] = max(y * prices[i] + x, y * prices[j] + z);

}

int maxProfitBottomUp(vector<int>& prices, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		// int j = i;
		// int y = n;
		// dp[i][j] = y * prices[i]; // y * prices[j]
		dp[i][i] = n * prices[i];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {

			// make a decision for the yth year

			int y = n - j + i;

			// 1. sell the ith bottle of wine

			int x = dp[i + 1][j];

			// 2. sell the jth bottle of wine

			int z = dp[i][j - 1];

			dp[i][j] = max(y * prices[i] + x, y * prices[j] + z);
		}
	}

	return dp[0][n - 1]; // at the (0, n-1)th index, we store f(0, n-1)

}


int main() {

	vector<int> prices = {2, 3, 5, 1, 4};
	int n = prices.size();
	cout << maxProfit(prices, 0, n - 1, 1) << endl;

	vector<vector<int>> dp(n, vector<int>(n, -1));
	cout << maxProfitTopDown(prices, 0, n - 1, 1, dp) << endl;

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << maxProfitBottomUp(prices, n) << endl;

	return 0;
}