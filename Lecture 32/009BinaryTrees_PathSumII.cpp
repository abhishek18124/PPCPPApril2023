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

void helper(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& paths) {

	// base case

	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		if (root->val == targetSum) {
			path.push_back(root->val);

			// for (int i = 0; i < path.size(); i++) {
			// 	cout << path[i] << " ";
			// }

			paths.push_back(path);

			cout << endl;

			path.pop_back();
		}
		return;
	}

	// recursive case

	path.push_back(root->val);

	helper(root->left, targetSum - root->val, path, paths);
	helper(root->right, targetSum - root->val, path, paths);

	path.pop_back(); // backtracking

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);
	root->right->right->left = new TreeNode(5);

	int targetSum = 22;

	vector<int> path;
	vector<vector<int>> paths;

	helper(root, targetSum, path, paths);


	return 0;
}