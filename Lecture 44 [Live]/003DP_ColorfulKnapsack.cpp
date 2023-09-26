#include <iostream>
#include<vector>
#include<climits>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<int, vector<int>> cmap; // to store a mapping b/w a color and object weights of that color

int helper(vector<int>& w, vector<int>& c, int n, int m, int x, int i) {

    // base case

    if (i == m + 1) {

        // you've build a valid configuration

        return x;

    }

    if (x == 0) {

        // you've build an invalid configuration

        return INT_MAX;

    }

    // recursive case

    // make a decision for the ith color

    vector<int> options = cmap[i];

    int ans = INT_MAX;

    for (int xij : options) {

        if (xij <= x) {

            // choose this option

            ans = min(ans, helper(w, c, n, m, x - xij, i + 1));


        }

    }

    return ans;

}

// map<pair<int, int>, int> dp;

class pairGenericHash {

public :

    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {

        hash<T1> hasher1;
        hash<T2> hasher2;

        auto hash1 = hasher1(p.first);
        auto hash2 = hasher2(p.second);

        return hash1 ^ hash2;

    }

};

unordered_map<pair<int, int>, int, pairGenericHash> dp;

int helperTopDown(vector<int>& w, vector<int>& c, int n, int m, int x, int i) {

    // lookup

    pair<int, int> key = make_pair(i, x);

    if (dp.find(key) != dp.end()) {
        return dp[key];
    }

    // base case

    if (i == m + 1) {

        // you've build a valid configuration

        return dp[key] = x;

    }

    if (x == 0) {

        // you've build an invalid configuration

        return dp[key] = INT_MAX;

    }

    // recursive case

    // make a decision for the ith color

    vector<int> options = cmap[i];

    int ans = INT_MAX;

    for (int xij : options) {

        if (xij <= x) {

            // choose this option

            ans = min(ans, helperTopDown(w, c, n, m, x - xij, i + 1));


        }

    }

    return dp[key] = ans;

}


int colorfulKnapsack(vector<int>& w, vector<int>& c, int n, int m, int x) {

    for (int i = 0; i < n; i++) {
        // c[i] : color of the ith object
        // w[i] : weight of ith object
        cmap[c[i]].push_back(w[i]);
    }

    // return helper(w, c, n, m, x, 1);

    // return helperTopDown(w, c, n, m, x, 1);

    int ans = helperTopDown(w, c, n, m, x, 1);

    return ans == INT_MAX ? -1 : ans;

}

int main() {

    vector<int> w = {2, 3, 4, 2, 4, 5, 2, 3};
    vector<int> c = {1, 1, 1, 2, 2, 2, 3, 3};

    int n = 8;
    int m = 3;

    int x = 13;

    cout << colorfulKnapsack(w, c, n, m, x) << endl;

    return 0;

}