#include<vector>
#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {//行优先,false代表可以填入数字，true代表不可填入数字
		memset(line,false,sizeof(line));
		memset(column, false, sizeof(column));
		memset(block, false, sizeof(block));
		for (int i = 0; i < board.size();i++) {
			for (int j = 0; j < board[i].size();j++) {
				if (board[i][j]!='.') {
					line[i][board[i][j]-'1'] = true;
					column[j][board[i][j]- '1'] = true;
					block[i / 3][j / 3][board[i][j]-'1'] = true;
				}
				else {
					label.push_back(make_pair(i, j));
				}
			}
		}
		dfs(board,0);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> tmp;
		vector<int> ans;
		while (root || !tmp.empty()) {
			while (root) {
				tmp.push(root);
				root = root->left;
			}
			root = tmp.top();
			tmp.pop();
			ans.push_back(root->val);
			root = root->right;
		}
		return ans;
	}
private:
	void dfs(vector<vector<char>>& board,int pos) {
		if (pos>=label.size()) {
			stop = true;
			return;
		}
		pair<int,int> tmp=label[pos];
		for (int digist = 1; digist < 10&&stop==false;digist++) {
			if (line[tmp.first][digist-1]==false&& column[tmp.second][digist - 1]==false&& block[tmp.first/3][tmp.second/3][digist - 1]==false) {
				board[tmp.first][tmp.second] = digist+'0';
				line[tmp.first][digist - 1] = column[tmp.second][digist - 1] = block[tmp.first / 3][tmp.second / 3][digist - 1] = true;
				dfs(board,pos+1);
				line[tmp.first][digist - 1] = column[tmp.second][digist - 1] = block[tmp.first / 3][tmp.second / 3][digist - 1] = false;
			}
		}
	}
	bool line[9][9];
	bool column[9][9];
	bool block[3][3][9];
	bool stop = false;
	vector<pair<int, int>> label;
};
//int main() {
//	Solution s;
//	struct TreeNode a;
//	struct TreeNode b;
//	struct TreeNode c;
//	a.val = 1;
//	b.val = 2;
//	c.val = 3;
//	a.left = NULL;
//	a.right = &b;
//	b.left = &c;
//	b.right = NULL;
//	c.left= NULL;
//	c.right = NULL;
//	vector<int> ret=s.inorderTraversal(&a);
//	for (int i = 0; i < ret.size();i++) {
//		cout << ret[i] << " ";
//	}
//	return 0;
//}
//int main() {
//	Solution s;
//	vector<vector<char>> board{ {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };
//	s.solveSudoku(board);
//	for (int i = 0; i < 9;i++) {
//		for (int j = 0; j < 9;j++) {
//			cout << board[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}