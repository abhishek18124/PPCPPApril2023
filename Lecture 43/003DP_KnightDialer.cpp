/*
    https://leetcode.com/problems/knight-dialer/
*/

#define vvvi vector<vector<vector<int>>>

class Solution {
public:

    vector<int> dx = { -2, -2, 2, 2, -1, 1, -1, 1};
    vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

    long long MOD = 1e9 + 7; // 1*10^9

    int f(int i, int j, int m) {

        // base case

        if (i < 0 || i > 3 || j < 0 || j > 2 ) {
            return 0;
        }

        if ((i == 3 and j == 0) || (i == 3 and j == 2)) {
            return 0;
        }

        if (m == 0) {
            return 1;
        }

        // recursive case

        // count # phone numbers the knight can dial by making 'm' moves starting from the (i, j)th cell

        int count = 0;

        // decide the next move

        for (int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            count = (count + f(nx, ny, m - 1)) % MOD;
        }

        return count % MOD;
    }

    int fTopDown(int i, int j, int m, vvvi& dp) {

        // base case

        if (i < 0 || i > 3 || j < 0 || j > 2 ) {
            return 0;
        }

        if ((i == 3 and j == 0) || (i == 3 and j == 2)) {
            return 0;
        }

        if (m == 0) {
            return 1;
        }

        // lookup

        if (dp[i][j][m] != -1) {
            return dp[i][j][m];
        }

        // recursive case

        // count # phone numbers the knight can dial by making 'm' moves starting from the (i, j)th cell

        int count = 0;

        // decide the next move

        for (int k = 0; k < 8; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            count = (count + fTopDown(nx, ny, m - 1, dp)) % MOD;
        }

        return dp[i][j][m] = count % MOD;
    }


    // int knightDialer(int n) {
    //     int total = 0;
    //     for (int i = 0; i < 4; i++) {
    //         for (int j = 0; j < 3; j++) {
    //             // count # distinct phone numbers of length 'n' the knight can dial starting from the (i, j)th cell
    //             if ((i == 3 and j == 0) || (i == 3 and j == 2)) continue;
    //             total = (total + f(i, j, n - 1))%MOD;
    //         }
    //     }
    //     return total%MOD;
    // }

    int knightDialer(int n) {
        vvvi dp(4, vector<vector<int>>(3, vector<int>(n, -1)));
        int total = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                // count # distinct phone numbers of length 'n' the knight can dial starting from the (i, j)th cell
                if ((i == 3 and j == 0) || (i == 3 and j == 2)) continue;
                total = (total + fTopDown(i, j, n - 1, dp)) % MOD;
            }
        }
        return total % MOD;
    }
};