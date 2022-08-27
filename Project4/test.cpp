//#include<iostream>
//#include<vector>
//#include<string>
//#include<stack>
//#include<queue>
//#include<algorithm>
//using namespace std;
//#include<map>
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//};
//struct Node
//{
//    int val;
//    Node* left;
//    Node* right;
//    Node* next;
//};
//class Solution
//{
//public:
//    bool  quickAdd (int y, int z, int x)
//    {
//        // x 和 y 是负数，z 是正数
//        // 需要判断 z * y >= x 是否成立
//        long long result = 0;
//        long long add = y;
//        while (z>0)
//        {
//            if (z & 1)
//            {
//                if (result+add<x)
//                {
//                    return false;
//                }
//                result = add+result;
//            }
//                add = add + add;
//            z=z >> 1;
//        }
//        return true;
//    }
//    int divide(int dividend, int divisor)
//    {
//        if (dividend == 0)
//        {
//            return 0;
//        }
//        if (dividend == INT_MIN)
//        {
//            if (divisor == -1)
//            {
//                return INT_MAX;
//            }
//            if (divisor == 1)
//            {
//                return INT_MIN;
//            }
//        }
//        if (divisor==INT_MIN)
//        {
//            if (dividend == INT_MIN)
//            {
//                return -1;
//            }
//            else
//            {
//              return  0;
//            }
//        }
//        bool flat1 = false;
//        bool flat2 = false;
//        if (dividend>0)
//        {
//            flat1 = true;
//            dividend = -dividend;
//        }
//        if (divisor>0)
//        {
//            flat2 = true;
//            divisor = -divisor;
//        }
//        int left = 1;
//        int right = 0;
//        if (dividend == INT_MIN)
//        {
//           right = INT_MAX;
//        }
//        else
//        {
//           right = -dividend;
//        }
//        int ans = 0;
//        while (left<=right)
//        {
//            int mid = left + ((right - left) >> 1);
//            bool check = quickAdd(divisor,mid,dividend);
//            if (check)
//            {
//                ans = mid;
//                if (mid == INT_MAX)
//                {
//                    break;
//                }
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//        if (flat1 == flat2)
//        {
//            return ans;
//        }
//        return -ans;
//    }
//    //int longestValidParentheses(string s) {
//    //    if (s.size() <= 1)
//    //    {
//    //        return 0;
//    //    }
//    //    int ans = 0;
//    //    for (int i=0;i<s.size()-1;i++)
//    //    {
//    //        int sum = 0;
//    //        int check = 0;
//    //        stack<char> tmp;
//    //        int flat1 = 0;
//    //        int flat2 = 0;
//    //        for (int j=i;j<s.size();j++)
//    //        {
//    //            if (s[j] == '(')
//    //            {
//    //                tmp.push('(');
//    //            }
//    //            else
//    //            {
//    //                if (tmp.size() == 0)
//    //                {
//    //                    break;
//    //                }
//    //                tmp.pop();
//    //                sum++;
//    //            }
//    //            if (tmp.empty())
//    //            {
//
//    //            }
//    //        }//"(()(((()"  ()()()()((()
//    //        //ans = max(ans,check);
//    //    }
//    //    return 2*ans;
//    //}
///*    int longestValidParentheses(string s) {
//        stack<int> tmp;
//        int maxiter = 0;
//        tmp.push(-1);
//        for (int i = 0; i < s.size(); i++)
//        {
//            if (s[i]=='(')
//            {
//                tmp.push(i);
//            }
//            else
//            {
//                tmp.pop();
//                if (tmp.empty())
//                {
//                    tmp.push(i);
//                }
//                else
//                {
//                    maxiter = max(maxiter,i-tmp.top());
//                }
//            }
//        }
//        return maxiter;
//    }*/// "()()()()((())"
//    int longestValidParentheses(string s) {
//        int left = 0; int right = 0; int ans = 0;
//        for (int i=0;i<s.size();i++)
//        {
//            if (s[i] == '(')
//            {
//                left++;
//            }
//            else
//            {
//                right++;
//                if (left == right)
//                {
//                    ans = max(ans, left + right);
//                }
//                if (right > left)
//                {
//                    left = right = 0;
//                }
//            }
//        }
//        left = right = 0;
//        for (int i = s.size()-1; i >=0; i--)
//        {
//            if (s[i] == ')')
//            {
//               right++;
//            }
//            else
//            {
//                left++;
//                if (left == right)
//                {
//                    ans = max(ans, left + right);
//                }
//                if (left > right)
//                {
//                    left = right = 0;
//                }
//            }
//        }
//        return ans;
//    }
//    //vector<int> searchRange(vector<int>& nums, int target) {
//    //    if (nums.size()==0){
//    //        return vector<int>{-1,-1};
//    //    }
//    //    int left = 0;
//    //    int right = nums.size()-1;
//    //    vector<int> ans = {-1,-1};
//    //    while (left<=right){
//    //        int mid = left + ((right - left) >> 1);
//    //        if (nums[mid]==target){
//    //            for (int i =mid; i>=0;i--) {
//    //                if (nums[i] == target) {
//    //                    ans[0] = i;
//    //                }
//    //            }
//    //            for (int i = mid; i < nums.size(); i++) {
//    //                if (nums[i] == target) {
//    //                    ans[1] = i;
//    //                }
//    //            }
//    //            return ans;
//    //        }
//    //        else if (nums[mid]>target){
//    //            right = mid - 1;
//    //        }
//    //        else{
//    //            left = mid + 1;
//    //        }
//    //    }
//    //    return ans;
//    //}
//    vector<int> searchRange(vector<int>& nums, int target) {
//        pair<vector<int>::iterator, vector<int>::iterator> ans = equal_range(nums.begin(),nums.end(),target);
//        if (ans.first==ans.second)
//        {
//            return vector<int>{-1,-1};
//        }
//        return vector<int>{(int)(ans.first-nums.begin()),(int)(ans.second - nums.begin() - 1)};
//    }
//    //bool _isValidSudoku(vector<vector<char>>& board,const int hang,const int lie){
//    //    int arr[9] = { 0 };
//    //    for (int i =hang; i <hang+3 ; i++) {
//    //        for (int j =lie-2; j <=lie; j++) {
//    //            if (board[i][j] != '.') {
//    //                arr[board[i][j] - '1']++;
//    //                if (arr[board[i][j] - '1'] > 1) {
//    //                    return false;
//    //                }
//    //            }
//    //        }
//    //    }
//    //    return true;
//    //}
//    //bool isValidSudoku(vector<vector<char>>& board) {
//    //    for (int i = 0; i < board.size(); i++) {
//    //        int arr1[9] = { 0 };//行
//    //        int arr2[9] = { 0 };//列
//    //        for (int j = 0; j < board[0].size(); j++) {
//    //            if (board[i][j] != '.') {
//    //                arr1[board[i][j] - '1']++;
//    //                if (arr1[board[i][j] - '1'] > 1) {
//    //                    return false;
//    //                }
//    //            }
//    //            if (board[j][i] != '.') {
//    //                arr2[board[j][i] - '1']++;
//    //                if (arr2[board[j][i] - '1'] > 1) {
//    //                    return false;
//    //                }
//    //            }
//    //        }
//    //    }
//    //    for (int i = 0; i < board.size();i+=3) {
//    //        for (int j = 2; j < board.size();j += 3) {
//    //            if (!_isValidSudoku(board,i,j)) {
//    //                return false;
//    //            }
//    //        }
//    //    }
//    //    return true;
//    //}
//    bool isValidSudoku(vector<vector<char>>& board) {
//        int rows[9][9] = { 0 };
//        int column[9][9] = { 0 };
//        int arr[3][3][9] = {0};
//        for (int i = 0; i < board.size(); i++) {
//            for (int j = 0; j < board.size(); j++) {
//                if (board[i][j] != '.') {
//                    int index = board[i][j] - '1';
//                    rows[i][index]++;
//                    column[j][index]++;
//                    arr[i/3][j/3][index]++;
//                    if (rows[i][index]>1|| column[j][index]>1|| arr[i / 3][j / 3][index]>1) {
//                        return false;
//                    }
//                }
//            }
//        }
//        return true;
//    }
//    void _combinationSum(vector<int>& candidates, int target, vector<vector<int>>& ans,int sum,vector<int>& tmp) {
//        if (sum>target) {
//            return;
//        }
//        if (sum == target) {
//            ans.push_back(tmp);
//            return;
//        }
//        for (int i = 0; i < candidates.size();i++) {
//            if (sum + candidates[i] > target) {
//                return;
//            }
//            if (!tmp.empty()&&candidates[i]<tmp.back()) {
//                continue;
//            }
//            sum += candidates[i];
//            tmp.push_back(candidates[i]);
//            _combinationSum(candidates, target, ans, sum, tmp);
//            sum -= candidates[i];
//            tmp.pop_back();
//        }
//    }
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<vector<int>> ans;
//        vector<int>tmp;
//        sort(candidates.begin(),candidates.end());
//        _combinationSum(candidates,target,ans,0,tmp);
//        return ans;
//    }
//    //void _combinationSum2(vector<int>& candidates, int target, vector<vector<int>>& ans,vector<int>& ret,int& cur,int tt) {
//    //    if (cur>target) {
//    //        return;
//    //    }
//    //    else if (cur==target) {
//    //        ans.push_back(ret);
//    //        return;
//    //    }
//    //    else {
//    //        for (int i = tt; i < candidates.size(); i++) {
//    //            if (candidates[i]+cur<=target) {
//    //                cur += candidates[i];
//    //                ret.push_back(candidates[i]);
//    //                _combinationSum2(candidates, target, ans, ret, cur,tt+1);
//    //                cur -= candidates[i];
//    //                ret.pop_back();
//    //            }
//    //            else {
//    //                break;
//    //            }
//    //        }
//    //    }
//    //}
//    //vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//    //    vector<vector<int>> ans;
//    //    vector<int> ret;
//    //    int cur = 0;
//    //    sort(candidates.begin(),candidates.end());
//    //    _combinationSum2(candidates,target,ans,ret,cur,0);
//    //    return ans;
//    //}
//    //void DFS(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int>& tmp,int ret,int prev,int next) {
//    //    if (ret == target) {                                                                 //prev为数字下标，next对应数字出现的次数
//    //        ans.push_back(tmp);
//    //        return;
//    //    }
//    //    else if (ret>target||prev>tmp.size()-2) {
//    //        return;
//    //    }
//    //    else {
//    //        if (tmp.at(prev+1)<next) {
//    //            prev += 2;
//    //            next = 0;
//    //        }
//    //        int i = prev;
//    //        while (i<=tmp.size()-2) {
//    //            ret += tmp[prev];
//    //            DFS(candidates,target,ans,tmp,ret,prev,next+1);
//    //            ret -= tmp[prev];
//    //            i += 2;
//    //        }
//    //    }
//    //}
//    //vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//    //    sort(candidates.begin(),candidates.end());
//    //    vector<int> tmp;
//    //    int ret = 0;
//    //    vector<vector<int>> ans;
//    //    for (int i = 0; i < candidates.size();i++) {
//    //        if (tmp.empty()||tmp.back()!=candidates[i]) {
//    //            tmp.push_back(candidates[i]);
//    //            tmp.push_back(1);
//    //        }
//    //        else {
//    //            tmp[tmp.size() - 1]++;
//    //        }
//    //    }
//    //    DFS(candidates, target, ans, tmp, ret,0,1);
//    //    return ans;
//    //}
// //   void _solveSudoku(vector<vector<char>>& board, int cur) {//按行有先
// //       if (cur == 9) {
// //           return;
// //       }
// //       for (int i = 0; i < 9; i++) {//行中每一个元素
// //           //一行九个数字
// //           if (blankspace[cur][i]==true ) {//blankspace为真代表是'.'
// //               for (int j =0; j <=9; j++) {
// //                   if (!rows[cur][j]&&!column[i][j]&&!block[cur/3][i/3][j]) {
// //                       rows[cur][j] = true;
// //                       column[i][j]=true;
// //                       block[cur / 3][i / 3][j]=true;
//
// //                   }
// //               }
// //           }
// //       }
// //   }
// //   void solveSudoku(vector<vector<char>>& board) {
// //       memset(rows,false,sizeof(rows));
// //       memset(column, false, sizeof(column));
// //       memset(block, false, sizeof(block));
// //       memset(blankspace,false,sizeof(blankspace));
// //       for (int i = 0; i < 9; i++) {
// //           for (int j = 0; j < 9; j++) {
// //               if (board[i][j]!='.') {
// //                   rows[i][board[i][j]-'1'] = true;
// //                   column[j][board[i][j]-'1'] = true;
// //                   block[i/3][j/3][board[i][j] - '1'] = true;
// //               }
// //               else {
// //                   blankspace[i][j] = true;
// //               }
// //           }
// //       }
// //       _solveSudoku(board,0);
// //   }
// //private:
// //       bool rows[9][9];
// //       bool column[9][9];
// //       bool block[3][3][9];
// //       bool blankspace[9][9];
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//        if (!p && !q) {
//            return true;
//        }
//        else if (p && q&&q->val==p->val) {
//            return isSameTree(p->left, p->left)&& isSameTree(p->right, p->right);
//        }
//        else {
//            return false;
//        }
//    }
//    //bool _isSymmetric(TreeNode* left, TreeNode* right) {
//    //    if (!left&&!right) {
//    //        return true;
//    //    }
//    //    else if (left&&right) {
//    //        if (left->val==right->val) {
//    //            return _isSymmetric(left->left,right->right) &&
//    //                _isSymmetric(left->right, right->left);
//    //        }
//    //        else {
//    //            return false;
//    //        }
//    //    }
//    //    else {
//    //        return false;
//    //    }
//    //}
//    //bool isSymmetric(TreeNode* root) {
//    //    if (!root) {
//    //        return true;
//    //    }
//    //    else if (root->left&&root->right) {
//    //        if (root->left->val==root->right->val) {
//    //            return _isSymmetric(root->left->left, root->right->right)&& 
//    //                _isSymmetric(root->left->right, root->right->left);
//    //        }
//    //        else {
//    //            return false;
//    //        }
//    //    }
//    //    else if (root->left || root->right) {
//    //        return false;
//    //    }
//    //    else {
//    //        return true;
//    //    }
//    //}
//    bool check(TreeNode* left, TreeNode* right) {
//        if (left&&right) {
//            return left->val==right->val&&check(left->left,right->right)&&check(left->right,right->left);
//        }
//        else if (left||right) {
//            return false;
//        }
//        else {
//            return true;
//        }
//    }
//    bool isSymmetric(TreeNode* root) {
//        if (!root) {
//            return true;
//        }
//        else {
//            return check(root->left, root->right);
//        }
//    }
//    int minDepth(TreeNode* root) {
//        if (!root) {
//            return 0;
//        }
//        else {
//            if (root->left&&root->right) {
//                return min(minDepth(root->left), minDepth(root->right)) + 1;
//            }
//            else if (root->left==NULL&& root->right != NULL) {
//                return minDepth(root->right) + 1;
//            }
//            else if(root->left != NULL&&root->right==NULL)
//            { 
//                return minDepth(root->left) + 1;
//            }
//            else
//            {
//                return 1;
//            }
//        }
//    }
//    bool hasPathSum(TreeNode* root, int targetSum) {
//        if (!root) {
//            return false;
//        }
//        queue<int> que_val;
//        queue<TreeNode*> que_node;
//        que_val.push(root->val);
//        que_node.push(root);
//        while (!que_node.empty()) {
//            int temp = que_val.front();
//            TreeNode* now = que_node.front();
//            que_val.pop();
//            que_node.pop();
//            if (temp==targetSum&&!now->left&&!now->right) {
//                return true;
//            }
//            if (now->left!=nullptr) {
//                que_node.push(now->left);
//                que_val.push(now->left->val+temp);
//            }
//            if (now->right != nullptr) {
//                que_node.push(now->right);
//                que_val.push(now->right->val + temp);
//            }
//        }
//        return false;
//    }
//    void dfs(TreeNode* root, int targetSum,vector<int>& cur,vector<vector<int>>& ans) {
//        if (!root) {
//            return;
//        }
//        else {
//            cur.push_back(root->val);
//            targetSum -= root ->val;
//            if (targetSum==0&&!root->left&&!root->right) {
//                ans.push_back(cur);
//                return;
//            }
//            if (root->left) {
//                dfs(root->left,targetSum,cur,ans);
//                cur.pop_back();
//            }
//            if (root->right) {
//                dfs(root->right, targetSum, cur, ans);
//                cur.pop_back();
//            }
//        }
//    }
//    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//        vector <vector< int >> ans;
//        vector<int> cur;
//        dfs(root,targetSum,cur,ans);                  
//        return ans;
//    }
//    //void flatten(TreeNode* root) {
//    //    stack<TreeNode*> tmp;
//    //    TreeNode* head = nullptr;
//    //    TreeNode* tail = nullptr;
//    //    TreeNode* temp = root;
//    //    while (!tmp.empty() ||root) {
//    //        while (root) {
//    //            if (head == nullptr) {
//    //                head = tail = new TreeNode;
//    //                tail->right = nullptr;
//    //            }
//    //            else {
//    //                tail->right = new TreeNode;
//    //                tail = tail->right;
//    //            }
//    //            tail->left = nullptr;
//    //            tail->val = root->val;
//    //            tmp.push(root);
//    //            root = root->left;
//    //        }
//    //        root = tmp.top();
//    //        tmp.pop();
//    //        root = root->right;
//    //    }
//    //    temp->left = nullptr;
//    //    if (head) {
//    //        temp->right = head->right;
//    //    }
//    //}
//    void flatten(TreeNode* root) {
//        TreeNode* cur = root;
//        while (cur) {
//            TreeNode* next = cur->left;
//            if (next != nullptr) {
//                while (next->right != nullptr) {
//                    next = next->right;
//                }
//                next->right = cur->right;
//                cur->right = cur->left;
//                cur->left = nullptr;
//            }
//            cur = cur->right;
//        }
//    }
//    void recoverTree(TreeNode* root) {
//        stack<TreeNode*> tmp;
//        vector<int> val;
//        TreeNode* rroot = root;
//        while (!tmp.empty() || rroot) {
//            while (rroot) {
//                tmp.push(rroot);
//                val.push_back(rroot->val);
//                rroot = rroot->left;
//            }
//            rroot = tmp.top();
//            tmp.pop();
//            rroot = rroot->right;
//        }
//        sort(val.begin(), val.end());
//        stack<TreeNode*> tmp1;
//        int i = 0;
//        while (!tmp1.empty() || root) {
//            while (root) {
//                tmp1.push(root);
//                root = root->left;
//            }
//            root = tmp1.top();
//            tmp1.pop();
//            root->val = val[i++];
//            root = root->right;
//        }
//    }
//    Node* connect(Node* root) {
//        if (root == nullptr) {
//            return root;
//        }
//        queue<Node*> tmp;
//        root->next = nullptr;
//        tmp.push(root->left);
//        tmp.push(root->right);
//        int i = 1;
//        while (!tmp.empty()) {
//
//        }
//    }
//};
//int main()
//{
//    Solution s;
//    /*cout << (s.divide(-2147483648, 2));*/
//    /*cout << s.divide(-11, 2);*/
// /*   string ss = "(()";
//    cout << s.longestValidParentheses(ss)<<endl;*/
//    //vector<int>tmp = {5,7,7,8,8,10};
//    //tmp = s.searchRange(tmp,8);
//    //cout << tmp.at(0) << tmp.at(1)<<endl;
//    //vector<vector<char>> tmp;
//    //vector<char> a1 = {'5','3','.','.','7','.','.','.','.'};
//    //vector<char> a2 = { '6','.','.','1','9','5','.','.','.'};
//    //vector<char> a3 = { '.','9','8','.','.','.','.','6','.'};
//    //vector<char> a4 = { '8','.','.','.','6','.','.','.','3'};
//    //vector<char> a5 = { '4','.','.','8','.','3','.','.','1'};
//    //vector<char> a6 = { '7','.','.','.','2','.','.','.','6'};
//    //vector<char> a7 = { '.','6','.','.','.','.','2','8','.'};
//    //vector<char> a8 = { '.','.','.','4','1','9','.','.','5'};
//    //vector<char> a9 = { '.','.','.','.','8','.','.','7','9'};
//    //tmp.push_back(a1);
//    //tmp.push_back(a2);
//    //tmp.push_back(a3);
//    //tmp.push_back(a4);
//    //tmp.push_back(a5);
//    //tmp.push_back(a6);
//    //tmp.push_back(a7);
//    //tmp.push_back(a8);
//    //tmp.push_back(a9);
//    //vector<vector<char>> tmp;
//    //vector<char> a1 = { '8','3','.','.','7','.','.','.','.' };
//    //vector<char> a2 = { '6','.','.','1','9','5','.','.','.' };
//    //vector<char> a3 = { '.','9','8','.','.','.','.','6','.' };
//    //vector<char> a4 = { '8','.','.','.','6','.','.','.','3' };
//    //vector<char> a5 = { '4','.','.','8','.','3','.','.','1' };
//    //vector<char> a6 = { '7','.','.','.','2','.','.','.','6' };
//    //vector<char> a7 = { '.','6','.','.','.','.','2','8','.' };
//    //vector<char> a8 = { '.','.','.','4','1','9','.','.','5' };
//    //vector<char> a9 = { '.','.','.','.','8','.','.','7','9' };
//    //tmp.push_back(a1);
//    //tmp.push_back(a2);
//    //tmp.push_back(a3);
//    //tmp.push_back(a4);
//    //tmp.push_back(a5);
//    //tmp.push_back(a6);
//    //tmp.push_back(a7);
//    //tmp.push_back(a8);
//    //tmp.push_back(a9);
//    //cout << s.isValidSudoku(tmp);
//    /*vector<int> tmp = { 10,1,2,7,6,1,5 };*/
//    //vector<int> tmp = {1,2,2,2,5};
//    //vector<vector<int>> ans = s.combinationSum2(tmp,8);
//    //for (int i = 0; i < ans.size();i++) {
//    //    for (int j = 0; j <ans[i].size() ;j++) {
//    //        cout << ans[i][j] << " ";
//    //    }
//    //    cout << endl;
//    //}
//    TreeNode a1;
//    TreeNode a2;
//    TreeNode a3;
//    TreeNode a4;
//    TreeNode a5;
//    TreeNode a6;
//    TreeNode a7;
//    TreeNode a8;
//    TreeNode a9;
//    TreeNode a10;
//    a1.val = 1;
//    a2.val = 2;
//    a3.val = 3;
//    a4.val = 4;
//    a5.val = 5;
//    a6.val = 6;
//    a1.left = &a2;
//    a1.right = &a5;
//    a2.left = &a3;
//    a2.right = &a4;
//    a3.left = nullptr;
//    a3.right = nullptr;
//    a4.left = nullptr;
//    a4.right = nullptr;
//    a5.left = nullptr;
//    a5.right = &a6;
//    a6.left = nullptr;
//    a6.right = nullptr;
//    a7.left = NULL;
//    a7.right = NULL;
//    a8.left = &a9;
//    a8.right = &a10;
//    a9.left = NULL;
//    a9.right = NULL;
//    a10.left = NULL;
//    a10.right = NULL;
//    //s.recoverTree(&a1);
//    string ret1 = "a";
//    string ret2 = "b";
//    string ret3 = "c";
//    string ret4 = "d";
//    cout<<ret1.append(ret2)<<endl;
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define COUNT 10
;//个数
void InitArray(int** ret) {
	int n = COUNT;
	int i = 0;
	*ret = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		//*(*ret + i) = i;
		(*ret)[i] = i+1;
	}
}
void DestroyArray(int* ret) {
	if (ret!=NULL) {
		free(ret);
	}
}
void Swap(int* ret1,int* ret2) {
	int tmp = *ret1;
	*ret1 = *ret2;
	*ret2 = tmp;
}
void Play() {
	int* arr = NULL;
	InitArray(&arr);
	int right = COUNT;
	int sz = COUNT;
	int index = 0;
	printf("抽奖开始!\n");
	srand(time(NULL));
	while (right) {
		index = rand() % right;
		getchar();
		printf("第%d抽奖的号码为%d\n",sz-right+1,arr[index]);
		//Sleep(1000);
		Swap(&arr[index],&arr[right-1]);
		right--;
	}
	printf("抽奖结束!\n");
	DestroyArray(arr);
}
int main() {
	Play();
	return 0;
}