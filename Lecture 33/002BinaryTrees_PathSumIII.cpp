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

int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {

		return 0;

	}

	int count = 0;

	if (root->val == targetSum) count++;

	// recursive case

	// count no. of paths that start at the root and sum up to targetSum

	// 1. ask your friend to count no. of paths in the leftSubtree that start at the root of the leftSubtree at sum up to targetSum-root->val

	count += countPaths(root->left, targetSum - root->val);

	// 2. ask your friend to count no. of paths in the rightSubtree that start at the root of the rightSubtree at sum up to targetSum-root->val

	count += countPaths(root->right, targetSum - root->val);

	return count;

}



int pathSum(TreeNode* root, int targetSum) {

	// base case
	if (root == NULL) {
		return 0;
	}

	// recursive case

	// 1. recursively, count no. of paths in the leftSubtree that sum upto targetSum

	int X = pathSum(root->left, targetSum);

	// 2. recursively, count no. of paths in the rightSubtree that sum upto targetSum

	int Y = pathSum(root->right, targetSum);

	// 3. count no. of paths in the tree that start at the root and sum upto targetSum
	int Z = countPaths(root, targetSum);

	return X + Y + Z;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}