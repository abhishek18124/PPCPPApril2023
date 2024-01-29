/*

    https://leetcode.com/problems/wildcard-matching/

*/

class Solution {
public:

    // bool f(string s, string p, int m, int n, int i, int j) {

    //     // base case

    //     if (i == m) {

    //         // check if p[j...n-1] mathces s[m...m-1] i.e. ""

    //         bool flag = true; // assume p[j...n-1] contains only stars

    //         for (int k = j; k <= n - 1; k++) {
    //             if (p[k] != '*') {
    //                 flag = false;
    //                 break;
    //             }
    //         }

    //         return flag;


    //     }

    //     if (j == n) { // i != m

    //         // check if empty p[n...n-1] mathces non-empty s[i...m-1]

    //         return false;
    //     }

    //     // recursive case

    //     // check if p[j...n-1] mathces s[i...m-1]

    //     if (s[i] == p[j]) {

    //         // recursively, check if p[j+1...n-1] mathces s[i+1...m-1]
    //         return f(s, p, m, n, i + 1, j + 1);

    //     } else {

    //         if (p[j] == '?' || p[j] == '*') {

    //             // p[j] is a wildcard character

    //             if (p[j] == '?') {

    //                 // '?' can match s[i]

    //                 // recursively, check if p[j+1...n-1] mathces s[i+1...m-1]
    //                 return f(s, p, m, n, i + 1, j + 1);

    //             } else { // p[j] == '*'

    //                 // 1. '*' can be replaced with empty-string

    //                 // recursively, check if p[j+1...n-1] mathces s[i...m-1]

    //                 // 2. '*' can be replaced with non-empty-string

    //                 // recursively, check if p[j...n-1] mathces s[i+1...m-1]

    //                 return f(s, p, m, n, i, j + 1) or f(s, p, m, n, i + 1, j);

    //             }

    //         } else {

    //             // p[j] is not a wildcard character

    //             return false;
    //         }

    //     }

    // }

    bool f(string s, string p, int m, int n, int i, int j) {

        // base case

        if (i == m) {

            // check if p[j...n-1] mathces s[m...m-1] i.e. ""

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k <= n - 1; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return flag;


        }

        if (j == n) { // i != m

            // check if empty p[n...n-1] mathces non-empty s[i...m-1]

            return false;
        }

        // recursive case

        // check if p[j...n-1] mathces s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {

            // recursively, check if p[j+1...n-1] mathces s[i+1...m-1]
            return f(s, p, m, n, i + 1, j + 1);

        } else if (p[j] == '*') {
            // 1. '*' can be replaced with empty-string

            // recursively, check if p[j+1...n-1] mathces s[i...m-1]

            // 2. '*' can be replaced with non-empty-string

            // recursively, check if p[j...n-1] mathces s[i+1...m-1]

            return f(s, p, m, n, i, j + 1) or f(s, p, m, n, i + 1, j);

        } else {
            // p[j] is not a wildcard character

            return false;
        }

    }


    bool fTopDown(string s, string p, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // lookup

        if (dp[i][j] != 2) {

            return dp[i][j];

        }

        // base case

        if (i == m) {

            // check if p[j...n-1] mathces s[m...m-1] i.e. ""

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k <= n - 1; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            return dp[i][j] = flag;


        }

        if (j == n) { // i != m

            // check if empty p[n...n-1] mathces non-empty s[i...m-1]

            return dp[i][j] = false;
        }

        // recursive case

        // check if p[j...n-1] mathces s[i...m-1]

        if (s[i] == p[j] || p[j] == '?') {

            // recursively, check if p[j+1...n-1] mathces s[i+1...m-1]
            return dp[i][j] = fTopDown(s, p, m, n, i + 1, j + 1, dp);

        } else if (p[j] == '*') {
            // 1. '*' can be replaced with empty-string

            // recursively, check if p[j+1...n-1] mathces s[i...m-1]

            // 2. '*' can be replaced with non-empty-string

            // recursively, check if p[j...n-1] mathces s[i+1...m-1]

            return dp[i][j] = fTopDown(s, p, m, n, i, j + 1, dp) or fTopDown(s, p, m, n, i + 1, j, dp);

        } else {
            // p[j] is not a wildcard character

            return dp[i][j] = false;
        }

    }

    bool fBottomUp(string s, string p, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++) {
            dp[i][n] = false;
        }

        dp[m][n] = true;

        for (int j = 0; j < n; j++) {

            bool flag = true; // assume p[j...n-1] contains only stars

            for (int k = j; k <= n - 1; k++) {
                if (p[k] != '*') {
                    flag = false;
                    break;
                }
            }

            dp[m][j] = flag;

        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // check if p[j...n-1] mathces s[i...m-1]

                if (s[i] == p[j] || p[j] == '?') {

                    // recursively, check if p[j+1...n-1] mathces s[i+1...m-1]
                    dp[i][j] = dp[i + 1][j + 1];

                } else if (p[j] == '*') {
                    // 1. '*' can be replaced with empty-string

                    // recursively, check if p[j+1...n-1] mathces s[i...m-1]

                    // 2. '*' can be replaced with non-empty-string

                    // recursively, check if p[j...n-1] mathces s[i+1...m-1]

                    dp[i][j] = dp[i][j + 1] or dp[i + 1][j];

                } else {
                    // p[j] is not a wildcard character

                    dp[i][j] = false;
                }

            }
        }

        return dp[0][0]; // at the (0, 0)th index we store f(0, 0)


    }


    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        // return f(s, p, m, n, 0, 0);

        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 2));

        // return fTopDown(s, p, m, n, 0, 0, dp);

        return fBottomUp(s, p, m, n);

    }
};