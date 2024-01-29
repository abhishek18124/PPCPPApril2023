/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	return root->val;

}

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	return root->val;

}


bool checkBST(TreeNode* root) {

	// base case
	if (root == NULL) {
		return true;
	}

	// recursive case

	// 1. recursively, check if the LST is a BST
	bool leftIsBST = checkBST(root->left);

	// 2. recursively, check if the RST is a BST
	bool rightIsBST = checkBST(root->right);

	// 3. check if the BST property is satisfied at the root node
	bool rootIsBST = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBST && rightIsBST && rootIsBST;

}

class Triple {

public :

	bool isBST;
	int maxVal;
	int minVal;

};

// time : O(n)

Triple checkBSTEffcient(TreeNode* root) {

	Triple t;

	// base case
	if (root == NULL) {
		t.isBST = true;
		t.maxVal = INT_MIN;
		t.minVal = INT_MAX;
		return t;
	}

	// recursive case

	// 1. recursively, check if the LST is a BST
	Triple left = checkBSTEffcient(root->left);

	// 2. recursively, check if the RST is a BST
	Triple right = checkBSTEffcient(root->right);

	// 3. check if the BST property is satisfied at the root node
	bool rootIsBST = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.isBST = left.isBST and right.isBST and rootIsBST;
	t.minVal = min({left.minVal, right.minVal, root->val});
	t.maxVal = max({left.maxVal, right.maxVal, root->val});

	return t;

}


bool checkBSTEffcientRange(TreeNode* root, long long lb, long long ub) {

	if (root == NULL) {
		return true;
	}

	return root->val > lb and root->val < ub and
	       checkBSTEffcientRange(root->left, lb, root->val) and
	       checkBSTEffcientRange(root->right, root->val, ub);

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(1);

	checkBST(root) ? cout << "BST" << endl : cout << "not a BST" << endl;

	checkBSTEffcient(root).isBST ? cout << "BST" << endl : cout << "not a BST" << endl;

	// int lb = INT_MIN;
	// int ub = INT_MAX;

	// long long lb = (long long)INT_MIN-1;
	// long long ub = (long long)INT_MAX+1;
	long long lb = LLONG_MIN;
	long long ub = LLONG_MAX;

	checkBSTEffcientRange(root, lb, ub) ? cout << "BST" << endl : cout << "not a BST" << endl;

	return 0;
}