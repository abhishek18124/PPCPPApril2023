
// https://leetcode.com/problems/dungeon-game/

class Solution {
public:

    // recursive implementation

    int helper(vector<vector<int>>& dungeon, int m, int n, int i, int j) {

        // base case

        if (i == m || j == n) {
            return INT_MAX;
        }

        if (i == m - 1 and j == n - 1) {
            return dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
        }

        // recursive case

        // compute the minimum initial health points required to go from (i, j)th cell to the (m-1, n-1)th cell

        // make a decision for the (i, j)th cell

        // 1. move right, and recursively compute the minimum initial health points required to go from (i, j+1)th cell to the (m-1, n-1)th cell

        int x = helper(dungeon, m, n, i, j + 1);

        // 2. move down, and recursively compute the minimum initial health points required to go from (i+1, j)th cell to the (m-1, n-1)th cell

        int y = helper(dungeon, m, n, i + 1, j);

        if (dungeon[i][j] == 0) {
            return min(x, y);
        } else if (dungeon[i][j] < 0) {
            return min(x, y) - dungeon[i][j]; // min(x, y) + abs(dungeon[i][j])
        } else { // dungeon[i][j] > 0
            if (dungeon[i][j] >= min(x, y)) {
                return 1;
            } else {
                return min(x, y) - dungeon[i][j];
            }
        }

    }


    int helperTopDown(vector<vector<int>>& dungeon, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // base case

        if (i == m || j == n) {
            return dp[i][j] = INT_MAX;
        }

        if (i == m - 1 and j == n - 1) {
            return dp[i][j] = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
        }

        // recursive case

        // compute the minimum initial health points required to go from (i, j)th cell to the (m-1, n-1)th cell

        // make a decision for the (i, j)th cell

        // 1. move right, and recursively compute the minimum initial health points required to go from (i, j+1)th cell to the (m-1, n-1)th cell

        int x = helperTopDown(dungeon, m, n, i, j + 1, dp);

        // 2. move down, and recursively compute the minimum initial health points required to go from (i+1, j)th cell to the (m-1, n-1)th cell

        int y = helperTopDown(dungeon, m, n, i + 1, j, dp);

        if (dungeon[i][j] == 0) {
            return dp[i][j] = min(x, y);
        } else if (dungeon[i][j] < 0) {
            return dp[i][j] = min(x, y) - dungeon[i][j]; // min(x, y) + abs(dungeon[i][j])
        } else { // dungeon[i][j] > 0
            if (dungeon[i][j] >= min(x, y)) {
                return dp[i][j] = 1;
            } else {
                return dp[i][j] = min(x, y) - dungeon[i][j];
            }
        }

    }

    // time : O(m.n)

    // space : O(m.n) due to dp[][]

    int helperBottomUp(vector<vector<int>>& dungeon, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; i++) {
            dp[i][n] = INT_MAX;
        }

        for (int j = 0; j <= n; j++) {
            dp[m][j] = INT_MAX;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // dp[i][j] = f(i, j) : compute the minimum initial health points required to go from (i, j)th cell to the (m-1, n-1)th cell

                if (i == m - 1 and j == n - 1) {
                    dp[i][j] = dungeon[i][j] >= 0 ? 1 : 1 - dungeon[i][j];
                } else {

                    // make a decision for the (i, j)th cell

                    // 1. move right, and recursively compute the minimum initial health points required to go from (i, j+1)th cell to the (m-1, n-1)th cell

                    int x = dp[i][j + 1];

                    // 2. move down, and recursively compute the minimum initial health points required to go from (i+1, j)th cell to the (m-1, n-1)th cell

                    int y = dp[i + 1][j];

                    if (dungeon[i][j] == 0) {
                        dp[i][j] = min(x, y);
                    } else if (dungeon[i][j] < 0) {
                        dp[i][j] = min(x, y) - dungeon[i][j]; // min(x, y) + abs(dungeon[i][j])
                    } else { // dungeon[i][j] > 0
                        if (dungeon[i][j] >= min(x, y)) {
                            dp[i][j] = 1;
                        } else {
                            dp[i][j] = min(x, y) - dungeon[i][j];
                        }
                    }


                }

            }
        }

        return dp[0][0]; // at the (0, 0)th index of dp[][], we store the result of f(0, 0)

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // return helper(dungeon, m, n, 0, 0);

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        // return helperTopDown(dungeon, m, n, 0, 0, dp);

        return helperBottomUp(dungeon, m, n);
    }
};