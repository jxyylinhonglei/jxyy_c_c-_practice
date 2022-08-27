#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ret(4,"....");
        vector<string> label(6,"......");
        dfs(ans,label,ret,n,0,0,n);
        return ans;
    }
    void dfs(vector<vector<string>>& ans, vector<string>& label, vector<string>& ret,int n,int line,int column,int cur) {
        if(cur==0){
            ans.push_back(ret);
            return;
        }
        for (int i = line; i < n;i++) {
            for (int j = column; j < n;j++) {
                if (label[i+1-1][j+1]!='Q'&& 
                    label[i + 1 + 1][j + 1] != 'Q'&&
                    label[i + 1 ][j + 1-1] != 'Q'&& 
                    label[i + 1 + 1][j + 1+1] != 'Q'&&
                    label[i + 1-1][j + 1-1] != 'Q' && 
                    label[i + 1-1][j + 1+1] != 'Q' && 
                    label[i + 1+1][j + 1-1] != 'Q' &&
                    label[i + 1+1][j + 1+1] != 'Q') {
                    ret[i][j] = 'Q';
                    label[i+1][j+1] = 'Q';
                    if (column==n-1) {
                        dfs(ans, label, ret, n, line+1, 0,cur-1);
                    }
                    else {
                        dfs(ans, label, ret, n, i, j+1,cur-1);
                    }
                    ret[i][j] = '.';
                    label[i][j] = '.';
                }
            }
        }
    }
};
//int main() {
//    Solution s;
//    vector<vector<string>> ans=s.solveNQueens(4);
//	return 0;
//}