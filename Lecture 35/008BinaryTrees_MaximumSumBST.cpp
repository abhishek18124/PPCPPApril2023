#include<iostream>
#include<vector>

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

class Data {
public :
    int sum;
    int minData;
    int maxData;
    bool isBST;
    int maxBSTSum;
};

Data helper(TreeNode* root) {

    Data d;

    // base case

    if (root == NULL) {

        d.sum = 0;
        d.isBST = true;
        d.minData = INT_MAX;
        d.maxData = INT_MIN;
        d.maxBSTSum = 0;

        return d;

    }

    // recursive case

    Data left = helper(root->left);
    Data right = helper(root->right);

    d.sum = left.sum + right.sum + root->val;
    d.minData = min({left.minData, right.minData, root->val});
    d.maxData = max({left.maxData, right.maxData, root->val});
    d.isBST = left.isBST and right.isBST and (root->val > left.maxData and root->val < right.minData);

    if (d.isBST) {
        d.maxBSTSum = max({left.maxBSTSum, right.maxBSTSum, d.sum});
    } else {
        d.maxBSTSum = max(left.maxBSTSum, right.maxBSTSum);
    }

    return d;

}


int maxSumBST(TreeNode* root) {

    Data d = helper(root);
    return d.maxBSTSum;

}


int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(4);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(3);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    cout << maxSumBST(root) << endl;

    return 0;
}