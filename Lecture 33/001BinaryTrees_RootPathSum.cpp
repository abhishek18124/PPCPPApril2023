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

// int countPaths(TreeNode* root, int targetSum) {

// 	// base case

// 	if (root == NULL) {

// 		return 0;

// 	}

// 	// recursive case

// 	// 1. ask your friend to count no. of paths in the leftSubtree that start at the root of the leftSubtree at sum up to targetSum-root->val

// 	int X = countPaths(root->left, targetSum - root->val);

// 	// 2. ask your friend to count no. of paths in the rightSubtree that start at the root of the rightSubtree at sum up to targetSum-root->val

// 	int Y = countPaths(root->right, targetSum - root->val);

// 	// 3. check if path from root to root is a valid path

// 	int Z = root->val == targetSum ? 1 : 0;

// 	return X + Y + Z;


// }


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

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(2);

	// root->left = new TreeNode(7);
	// root->left->left = new TreeNode(3);
	// root->left->left->left = new TreeNode(1);
	// root->left->left->right = new TreeNode(8);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(6);
	// root->right->left = new TreeNode(4);
	// root->right->right = new TreeNode(5);

	// int targetSum = 12;

	// cout << countPaths(root, targetSum) << endl;

	// root = new TreeNode(4);

	// root->left = new TreeNode(7);
	// root->left->left = new TreeNode(3);
	// root->left->left->left = new TreeNode(1);
	// root->left->left->right = new TreeNode(8);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(6);
	// root->right->left = new TreeNode(4);
	// root->right->right = new TreeNode(5);

	// int targetSum = 4;

	// cout << countPaths(root, targetSum) << endl;

	root = new TreeNode(5);

	root->left = new TreeNode(3);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(2);

	root->right = new TreeNode(1);
	root->right->left = new TreeNode(2);
	root->right->left->left = new TreeNode(1);
	root->right->left->right = new TreeNode(2);
	root->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << countPaths(root, targetSum) << endl;

	return 0;
}