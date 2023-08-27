/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7},
                {2, 4, 6, 8},
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11

*/

#include<iostream>
#include<queue>
#include<vector>

#define piii pair<int, pair<int, int>>

using namespace std;

class triple {

public :

    int val;
    int row;
    int col;

    triple(int val, int row, int col) {
        this->val = val;
        this->row = row;
        this->col = col;
    }

};

class tripleComparator {

public :

    bool operator()(triple a, triple b) {
        if (b.val < a.val) {
            // we need to swap to build a minHeap
            return true;
        }
        // we don't need to swap to build a minHeap
        return false;
    }

};


int main() {

    vector<vector<int>> inp = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = inp.size();

    vector<int> out;

    // priority_queue<triple, vector<triple>, tripleComparator> minHeap;

    // for (int i = 0; i < k; i++) {
    //     minHeap.push(triple(inp[i][0], i, 0));
    // }

    // while (!minHeap.empty()) {

    //     triple t = minHeap.top();
    //     minHeap.pop();

    //     int val = t.val;
    //     int row = t.row;
    //     int col = t.col;

    //     out.push_back(val);

    //     if (col + 1 < inp[row].size()) {
    //         minHeap.push(triple(inp[row][col + 1], row, col + 1));
    //     }

    // }

    priority_queue <piii, vector<piii>, greater<piii>> minHeap;

    for (int i = 0; i < k; i++) {
        minHeap.push({inp[i][0], {i, 0}}); // make_pair(inp[i][0], make_pair(i, 0))
    }

    while (!minHeap.empty()) {

        piii t = minHeap.top();
        minHeap.pop();

        int val = t.first;
        int row = t.second.first;
        int col = t.second.second;

        out.push_back(val);

        if (col + 1 < inp[row].size()) {
            minHeap.push({inp[row][col + 1], {row, col + 1}});
        }

    }


    for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
    }

    cout << endl;

    return 0;
}