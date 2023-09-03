/*
	https://leetcode.com/problems/find-duplicate-subtrees/
*/

class Solution {
public:

	set<TreeNode*> s; // to track duplicate subtrees
	unordered_map<string, TreeNode*> hm;

	string dfs(TreeNode* root) {

		// base case

		if (root == NULL) {

			return "X";

		}

		// recursive case

		// construct a unique representation for the subTree rooted at the 'root' node

		string leftRepr  = dfs(root->left);
		string rightRepr = dfs(root->right);

		string uniqueRepr = to_string(root->val) + "-" + leftRepr + "-" + rightRepr;

		if (hm.find(uniqueRepr) != hm.end()) {

			// you've found a duplicate subtree

			s.insert(hm[uniqueRepr]); // or s.insert(root)

		} else {

			hm[uniqueRepr] = root;

		}

		return uniqueRepr;

	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return vector<TreeNode*>(s.begin(), s.end());
		// vector<TreeNode*> out;
		// for (TreeNode* duplicate_subtree_root : s) {
		// 	out.push_back(duplicate_subtree_root);
		// }
		// return out;

	}
};