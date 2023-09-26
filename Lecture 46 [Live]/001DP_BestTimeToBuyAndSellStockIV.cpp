// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:

    int helper(vector<int>& prices, int N, int i, int k) {

        // base case

        if (i == N) {

            return 0;

        }

        if (k == 0) { // i != N

            return 0;

        }

        // recursive case

        // find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int ans = helper(prices, N, i + 1, k);

        // 2. buy the stock on the ith day

        // decide the day on which you'll sell the stock

        for (int j = i + 1; j < N; j++) {

            // sell the stock on the jth day

            ans = max(ans, prices[j] - prices[i] + helper(prices, N, j + 1, k - 1));

        }

        return ans;


    }

    int helperTopDown(vector<int>& prices, int N, int i, int k, vector<vector<int>>& dp) {

        // lookup
        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        // base case

        if (i == N) {

            return dp[i][k] = 0;

        }

        if (k == 0) { // i != N

            return dp[i][k] = 0;

        }

        // recursive case

        // find the maximum profit you can make by completing <=k transactions starting from the ith day

        // make a decision for the ith day

        // 1. do not buy the stock on the ith day

        int ans = helperTopDown(prices, N, i + 1, k, dp);

        // 2. buy the stock on the ith day

        // decide the day on which you'll sell the stock

        for (int j = i + 1; j < N; j++) {

            // sell the stock on the jth day

            ans = max(ans, prices[j] - prices[i] + helperTopDown(prices, N, j + 1, k - 1, dp));

        }

        return dp[i][k] = ans;


    }

    int helperBottomUp(vector<int>& prices, int N, int K) {

        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

        for (int i = N - 1; i >= 0; i--) {

            for (int k = 1; k <= K; k++) {

                // find the maximum profit you can make by completing <=k transactions starting from the ith day

                // make a decision for the ith day

                // 1. do not buy the stock on the ith day

                int ans = dp[i + 1][k];

                // 2. buy the stock on the ith day

                // decide the day on which you'll sell the stock

                for (int j = i + 1; j < N; j++) {

                    // sell the stock on the jth day

                    ans = max(ans, prices[j] - prices[i] + dp[j + 1][k - 1]);

                }

                dp[i][k] = ans;

            }

        }

        return dp[0][K];

    }


    int maxProfit(int K, vector<int>& prices) {
        int N = prices.size();
        // return helper(prices, N, 0, K);

        // vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
        // return helperTopDown(prices, N, 0, K, dp);

        return helperBottomUp(prices, N, K);
    }
};