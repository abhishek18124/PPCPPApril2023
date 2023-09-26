// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#define vvvi vector<vector<vector<int>>>

class Solution {
public:

    int helper(vector<int>& prices, int N, int i, int k, bool canBuy) {

        // base case

        if (i == N || k == 0) {

            return 0;

        }

        // recursive case

        // find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. don't do anything

        int ans = helper(prices, N, i + 1, k, canBuy);

        // 2. buy a stock on the ith day
        if (canBuy) {
            ans = max(ans, helper(prices, N, i + 1, k, false) - prices[i]);

            // Y - prices[i]
        }

        // 3. sell the stock on the ith day
        if (!canBuy) {
            ans = max(ans, helper(prices, N, i + 1, k - 1, true) + prices[i]);

            // Z + prices[i]
        }

        return ans;



    }

    int helperTopDown(vector<int>& prices, int N, int i, int k, bool canBuy, vvvi& dp) {

        // base case

        if (i == N || k == 0) {

            return 0;

        }

        // lookup

        if (dp[i][k][canBuy] != -1) {
            return dp[i][k][canBuy];
        }

        // recursive case

        // find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. don't do anything

        int ans = helperTopDown(prices, N, i + 1, k, canBuy, dp);

        // 2. buy a stock on the ith day
        if (canBuy) {
            ans = max(ans, helperTopDown(prices, N, i + 1, k, false, dp) - prices[i]);

            // Y - prices[i]
        }

        // 3. sell the stock on the ith day
        if (!canBuy) {
            ans = max(ans, helperTopDown(prices, N, i + 1, k - 1, true, dp) + prices[i]);

            // Z + prices[i]
        }

        return dp[i][k][canBuy] = ans;

    }


    int maxProfit(int K, vector<int>& prices) {
        int N = prices.size();
        // return helper(prices, N, 0, K, true);
        vvvi dp(N + 1, vector<vector<int>>(K + 1, vector<int>(2, -1)));
        return helperTopDown(prices, N, 0, K, true, dp);
    }
};