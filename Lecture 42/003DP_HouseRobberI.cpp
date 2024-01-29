#include<iostream>
#include<vector>

using namespace std;

// // recursive implementation

// int helper(vector<int>& nums, int n, int i) {

//     // base case

//     if (i >= n) {
//         return 0;
//     }

//     // recursive case

//     // find the maximum amount of money you can rob given a sequence of n-i houses [i...n-1] w/o alerting the police

//     // make a decision for the ith house

//     // 1. do not rob the ith house

//     // recursively, find the maximum amount of money you can rob given the sequence houses [i+1...n-1] w/o alerting the police

//     int x  = helper(nums, n, i + 1);

//     // 2. rob the ith house

//     // recursively, find the maximum amount of money you can rob given the sequence houses [i+2...n-1] w/o alerting the police

//     int y  = helper(nums, n, i + 2);

//     return max(x, nums[i] + y);
// }

int helperTopDown(vector<int>& nums, int n, int i, vector<int>& dp) {

    // base case

    if (i >= n) {
        return 0;
    }

    // lookup
    if (dp[i] != -1) {
        return dp[i];
    }

    // recursive case

    // find the maximum amount of money you can rob given a sequence of n-i houses [i...n-1] w/o alerting the police

    // make a decision for the ith house

    // 1. do not rob the ith house

    // recursively, find the maximum amount of money you can rob given the sequence houses [i+1...n-1] w/o alerting the police

    int x  = helperTopDown(nums, n, i + 1, dp);

    // 2. rob the ith house

    // recursively, find the maximum amount of money you can rob given the sequence houses [i+2...n-1] w/o alerting the police

    int y  = helperTopDown(nums, n, i + 2, dp);

    return dp[i] = max(x, nums[i] + y);
}

// time : O(n) space : O(n) due to dp[]

int helperBottomUp(vector<int> nums, int n) {

    vector<int> dp(n + 2);

    dp[n + 1] = 0; // at the (n+1)th index of dp[], we store f(n+1)
    dp[n] = 0; // at the nth index of dp[], we store f(n)

    for (int i = n - 1; i >= 0; i--) {

        // dp[i] = f(i) : max. profit from robbing houses[i...n-1]

        // make a decision for the ith house

        // 1. do not rob

        int x = dp[i + 1];

        // 2. rob

        int y = dp[i + 2];

        dp[i] = max(x, nums[i] + y);

        // dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);

    }

    return dp[0]; // at the 0th index of dp[], we store f(0)

}


int rob(vector<int>& nums) {

    int n = nums.size();

    // return helper(nums, n, 0);

    // vector<int> dp(n, -1);

    // return helperTopDown(nums, n, 0, dp);

    return helperBottomUp(nums, n);

}

int main() {

    vector<int> nums = {100, 50, 400, 200, 100};

    cout << rob(nums) << endl;


    return 0;
}