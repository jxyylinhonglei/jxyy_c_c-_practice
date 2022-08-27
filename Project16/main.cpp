#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> tmp;
		TreeNode* prev = NULL;
		while (root||!tmp.empty()) {
			while (root) {
				tmp.push(root);
				root = root->left;
			}
			root = tmp.top();
			tmp.pop();
			if (root->right==NULL||root->right==prev) {
				ans.push_back(root->val);
				prev = root;
				root = NULL;
			}
			else {
				tmp.push(root);
				root = root->right;
			}
		}
	}
};
int main() {
	Solution s;
	TreeNode a;
	TreeNode b;
	TreeNode c;
	a.left = NULL;
	a.right = &b;
	b.left = &c;
	b.right = NULL;
	c.left = NULL;
	c.right = NULL;
	s.postorderTraversal(&a);
	return 0;
}