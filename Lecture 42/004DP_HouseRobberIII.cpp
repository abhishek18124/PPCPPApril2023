#include<iostream>
#include<unordered_map>

using namespace std;

class TreeNode {

public :

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

// recursive implementation

// int helper(TreeNode* root) {

//     // base case

//     if (root == NULL) {
//         return 0;
//     }

//     // recursive case

//     // make a decision for the root

//     // 1. do not rob at the root node

//     int doNotRobAtRoot = helper(root->left) + helper(root->right);

//     // 2. rob at the root node

//     int robAtRoot = root->val;

//     if (root->left != NULL) {
//         robAtRoot += helper(root->left->left);
//         robAtRoot += helper(root->left->right);
//     }

//     if (root->right != NULL) {
//         robAtRoot += helper(root->right->left);
//         robAtRoot += helper(root->right->right);
//     }

//     return max(doNotRobAtRoot, robAtRoot);

// }

int helperTopDown(TreeNode* root, unordered_map<TreeNode*, int>& dp) {

    // base case

    if (root == NULL) {
        return 0;
    }

    // lookup
    if (dp.find(root) != dp.end()) {
        return dp[root];
    }

    // recursive case

    // make a decision for the root

    // 1. do not rob at the root node

    int doNotRobAtRoot = helperTopDown(root->left, dp) + helperTopDown(root->right, dp);

    // 2. rob at the root node

    int robAtRoot = root->val;

    if (root->left != NULL) {
        robAtRoot += helperTopDown(root->left->left, dp);
        robAtRoot += helperTopDown(root->left->right, dp);
    }

    if (root->right != NULL) {
        robAtRoot += helperTopDown(root->right->left, dp);
        robAtRoot += helperTopDown(root->right->right, dp);
    }

    return dp[root] = max(doNotRobAtRoot, robAtRoot);

}


int rob(TreeNode* root) {

    // return helper(root);

    unordered_map<TreeNode*, int> dp;

    return helperTopDown(root, dp);

}

int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(4);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(5);
    // root->right->right = new TreeNode(1);

    // cout << rob(root) << endl;

    return 0;
}