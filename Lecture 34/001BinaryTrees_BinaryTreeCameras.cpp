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

// class Triple {
// public :

// 	int numCameras;
// 	bool isCovered;
// 	bool hasCamera;

// };

// Triple helper(TreeNode* root) {

// 	Triple t;

// 	// base case

// 	if (root == NULL) {

// 		t.numCameras = 0;
// 		t.hasCamera = false;
// 		t.isCovered = true;

// 		return t;
// 	}

// 	// recursive case

// 	Triple left = helper(root->left);
// 	Triple right = helper(root->right);

// 	if (!left.isCovered || !right.isCovered) {
// 		// install camera at the root node
// 		t.numCameras = left.numCameras + right.numCameras + 1;
// 		t.hasCamera = true;
// 		t.isCovered = true;
// 		return t;
// 	}

// 	// do not install camera at the root node

// 	t.numCameras = left.numCameras + right.numCameras;
// 	t.hasCamera = false;
// 	t.isCovered = left.hasCamera || right.hasCamera ? true : false;

// 	return t;

// }

// int minCameraCover(TreeNode* root) {

// 	Triple t = helper(root);

// 	return t.isCovered ? t.numCameras : t.numCameras + 1;

// //	return t.numCameras;

// }


// 0 : not Covered
// 1 : Covered + hasCamera
// 2 : Covered + no Camera

int numCameras = 0;

int helper(TreeNode* root) {

	// base case

	if (root == NULL) {
		return 2; // isCovered + no Camera
	}

	// recursive case

	int leftStatus = helper(root->left);
	int rightStatus = helper(root->right);

	if (leftStatus == 0 || rightStatus == 0) {
		// install camera at the root node
		numCameras++;
		return 1; // isCovered + hasCamera
	}

	return leftStatus == 1 || rightStatus == 1 ? 2 : 0;

}

int minCameraCover(TreeNode* root) {

	int rootStatus = helper(root);

	if (rootStatus == 0) {
		numCameras++;
	}

	return numCameras;

}


int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	TreeNode* root1 = new TreeNode(0);

	root = new TreeNode(0);

	root1->left = root;

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	root->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(0);

	cout << minCameraCover(root1) << endl;

	return 0;
}