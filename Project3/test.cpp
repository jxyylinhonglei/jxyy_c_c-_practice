#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
//#define INT_MAX 2147483647;
class Solution
{
public:
    //int TwoFind(vector<int>& nums, int begin, int end, int target)
    //{
    //    while (begin <= end)
    //    {
    //        int mid = (begin + end) >> 1;
    //        if (nums[mid] == target)
    //        {
    //            return mid;
    //        }
    //        else if (nums[mid] > target)
    //        {
    //            end = mid - 1;
    //        }
    //        else
    //        {
    //            begin = mid + 1;
    //        }
    //    }
    //    return -1;
    //}
    //int search(vector<int>& nums, int target) {
    //    int sz = nums.size();
    //    if (sz==0)
    //    {
    //        return -1;
    //    }
    //    if (sz == 1)
    //    {
    //        return nums[0] == target ? 0 : -1;
    //    }
    //    int begin = 0; 
    //    int end = sz - 1;
    //    while (begin<=end)
    //    {
    //        int mid = (begin + end) >> 1;
    //        if (nums[begin] <= nums[mid])
    //        {
    //            int ans=TwoFind(nums,begin,mid,target);
    //            if (ans!=-1)
    //            {
    //                return ans;
    //            }
    //            begin = mid + 1;
    //        }
    //        else
    //        {
    //            int ans = TwoFind(nums, mid+1,end, target);
    //            if (ans != -1)
    //            {
    //                return ans;
    //            }
    //            end = mid;
    //        }
    //    }
    //    return -1;
    //}
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz == 0)
        {
            return -1;
        }
        if (sz == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        int begin = 0;
        int end = sz - 1;
        while (begin <= end)
        {
            int mid = (begin + end) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[begin] <= nums[mid])
            {
                if (nums[begin] <= target && target <= nums[mid])
                {
                    end = mid;
                }
                else
                {
                    begin = mid + 1;
                }
            }
            else
            {
                if (nums[mid + 1] <= target && target <= nums[end])
                {
                    begin = mid + 1;
                }
                else
                {
                    end = mid;
                }
            }
        }
        return -1;
    }//F(S)=min{F(S-Ci)}+1，F(0)=0;1,3,6   
    //int coinChange(vector<int>& coins, int amount) {
    //    if (amount==0)
    //    {
    //        return 0;
    //    }
    //    vector<int> ans(amount+1,-1);
    //    ans[0] = 0;
    //    for (int i=1;i<=amount;i++)
    //    {
    //        int min =INT_MAX;
    //        for (int j = 0; j <coins.size(); j++)
    //        {
    //            if (i-coins[j]>=0&& ans[i - coins[j]]!=-1)
    //            {
    //               min= ans[i - coins[j]] + 1>min?min: ans[i - coins[j]] + 1;
    //            }
    //        }
    //        if (min==INT_MAX)
    //        {
    //            ans[i] = -1;
    //        }
    //        else
    //        {
    //            ans[i] =min;
    //        }
    //    }
    //    return ans[amount];
    //}
    int _coinChangeshang(vector<int>& coins, vector<int>& ans, int amount)
    {
        if (ans[amount] != -1)
        {
            /*  cout << amount << " " << ans[amount]<<endl;*/
            return ans[amount];
        }
        if (amount == 0)
        {
            return 0;
        }
        int min = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (amount - coins[i] >= 0)
            {
                int ret = _coinChangeshang(coins, ans, amount - coins[i]);
                if (min > ret + 1 && ret != -2)
                {
                    /*   cout << amount << " " << ret << endl;*/
                    min = ret + 1;
                }
            }
        }
        /* cout << amount << " " << ans[amount] << endl;*/
        if (min != INT_MAX)
        {
            ans[amount] = min;
        }
        else
        {
            ans[amount] = -2;
        }
        /* cout << amount << " " << ans[amount] << endl;*/
        return ans[amount];
    }
    int coinChangeshang(vector<int>& coins, int amount) {
        if (amount == 0)
        {
            return 0;
        }
        vector<int> ans(amount + 1, -1);
        return _coinChangeshang(coins, ans, amount);
    }
    void _change(int amount, int ret, int& ans, vector<int>& coins) {
        if (ret == amount)
        {
            ans++;
            return;
        }
        if (ret > amount)
        {
            return;
        }
        for (int i = 0; i < coins.size(); i++)
        {
            _change(amount, ret + coins[i], ans, coins);
        }
    }
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
        {
            return 0;
        }
        int ans = 0;
        int ret = 0;
        _change(amount, ret, ans, coins);
        return ans;
    }
    int _climb(int n, vector<int>& ans)
    {
        if (n == 1)
        {
            return 1;
        }//2    F(n)=F(n-1)+F(n-2)   1 2 3 5 8 13
        if (n == 2)
        {
            return 2;
        }
        if (ans[n] != 0)
        {
            return ans[n];
        }
        ans[n - 1] = _climb(n - 1, ans);
        ans[n - 2] = _climb(n - 2, ans);
        ans[n] = ans[n - 2] + ans[n - 1];
        return ans[n];
    }
    int climbStairs(int n) {
        vector<int> ans(n + 1, 0);
        return _climb(n, ans);//3
    }
    //int Cost(vector<int>& cost,vector<int>& ans,int cur)
    //{//f(n)=min{f(n-1)+Ci,f(n-2)+Ci-1}
    //    if (cur==0)
    //    {
    //        return cost[cur];
    //    }
    //    if (ans[cur]!=0)
    //    {
    //        return ans[cur];
    //    }
    //    ans[cur-1]= Cost(cost, ans,cur-1);
    //    //if (cur!=1)
    //    //{
    //    //    ans[cur - 2] = Cost(cost, ans, cur - 2);
    //    //}
    //    //else
    //    //{
    //    //    ans[cur] = cost[1] > ans[0];
    //    //}
    //   if(cur!=1)
    //   {
    //       ans[cur - 2] = Cost(cost, ans, cur - 2);
    //       ans[cur] = ans[cur - 1] + cost[cur - 1] > ans[cur - 2] + cost[cur - 2] ? ans[cur - 2] + cost[cur - 2] : ans[cur - 1] + cost[cur - 1];
    //   }
    //    return ans[cur];
    //}
    //int minCostClimbingStairs(vector<int>& cost) {
    //    int sz = cost.size();//10,15,20  i      //F(i)=min{F(i-1)+20,F(i-2)+15}
    //    vector<int> ans(sz+1,0);//0  1  2    3
    //    return Cost(cost,ans,sz);//3
    //}
    //int minCostClimbingStairs(vector<int>& cost) {
    //    int sz = cost.size();
    //    if (sz == 1)
    //    {
    //        return cost[0];
    //    }//F(i)=min{F(i-1)+20,F(i-2)+15}
    //    vector<int> ans(sz+1, 0);
    //    for (int i=0;i<sz;i++)//10,15,20
    //    {
    //        if (i<=1)
    //        {
    //            if (cost[0] > cost[1])
    //            {
    //                ans[i] = cost[1];
    //            }
    //            else
    //            {
    //                ans[i] = cost[0];
    //            }
    //        }
    //        if (i == 2)
    //        {
    //            ans[i] = cost[0] + cost[2] > cost[1] ? cost[1] : cost[0] + cost[2];
    //        }
    //        if (i>2)
    //        {
    //            ans[i] = ans[i - 1] + cost[i-1]> ans[i - 2] + cost[i - 2]? ans[i - 2] + cost[i - 2]: ans[i - 1] + cost[i - 1];
    //        }

    //    }
    //    return ans[sz-1];
    //}
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        vector<int> df(sz + 1, 0);
        df[0] = 0;
        df[1] = 0;
        for (int i = 2; i <= sz; i++)
        {
            df[i] = df[i - 1] + cost[i - 1] > df[i - 2] + cost[i - 2] ? df[i - 2] + cost[i - 2] : df[i - 1] + cost[i - 1];
        }
        return df[sz];
    }
    int _minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        int prev = 0;
        int cur = 0;
        int next = 0;
        for (int i = 2; i <= sz; i++)
        {
            next = cur + cost[i - 1] > prev + cost[i - 2] ? prev + cost[i - 2] : cur + cost[i - 1];
            prev = cur;
            cur = next;
        }
        return next;
    }
    int rob(vector<int>& nums) {
        int prev = nums[0];
        if (nums.size() == 1)
        {
            return prev;
        }
        int cur = prev > nums[1] ? prev : nums[1];
        if (nums.size() == 2)
        {
            return cur;
        }
        int next = 0;
        for (int i = 2; i < nums.size(); i++)
        {// 1,2,3,1
            next = prev + nums[i] > cur ? prev + nums[i] : cur;
            prev = cur;
            cur = next;
        }
        return next;
    }
    //int rob(vector<int>& nums) {
    //    if (nums.size() == 1)
    //    {
    //        return nums[0];
    //    }
    //    vector<int>df(nums.size(),0);
    //    df[0] = nums[0];
    //    df[1] = df[0] > nums[1] ? df[0]: nums[1];
    //    if (nums.size() == 2)
    //    {
    //        return df[1];
    //    }
    //    for (int i = 2; i < nums.size(); i++)
    //    {//2,10,1,2 7 4
    //        df[i] = nums[i] + df[i - 2] > df[i - 1] ? nums[i] + df[i - 2] : df[i - 1];
    //    }
    //    return df[nums.size()-1];
    //}
    int rob2(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        vector<int> df1(nums.size() - 1, 0);
        vector<int> df2(nums.size() - 1, 0);
        df1[0] = nums[0];
        df1[1] = df1[0] > nums[1] ? df1[0] : nums[1];
        df2[0] = nums[1];
        df2[1] = df2[0] > nums[2] ? df2[0] : nums[2];
        for (int i = 2; i < nums.size(); i++)
        {
            if (i < nums.size() - 1)
            {
                df1[i] = df1[i - 2] + nums[i] > df1[i - 1] ? df1[i - 2] + nums[i] : df1[i - 1];
            }
            if (i != 2)
            {
                df2[i - 1] = df2[i - 3] + nums[i] > df2[i - 2] ? df2[i - 3] + nums[i] : df2[i - 2];
            }
        }
        return df1[nums.size() - 2] > df2[nums.size() - 2] ? df1[nums.size() - 2] : df2[nums.size() - 2];
    }
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        vector<int> reslut;
        vector<int> flat;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
            {
                reslut[reslut.size() - 1] += nums[i];
            }
            else
            {
                reslut.push_back(nums[i]);
                flat.push_back(nums[i]);
            }
        }
        if (reslut.size() == 1)
        {
            return reslut[0];
        }
        else
        {
            int prev = reslut[0];
            int cur = 0;
            int next = 0;
            vector<int> df(flat.size(), 0);
            df[0] = reslut[0];
            if (flat[0] + 1 == flat[1])
            {
                df[1] = df[0] > reslut[1] ? df[0] : reslut[1];
            }
            else
            {
                /*next=cur = prev += reslut[1];*/
                df[1] = df[0] + reslut[1];
            }
            for (int i = 2; i < flat.size(); i++)
            {
                if (flat[i - 1] + 1 == flat[i])
                {
                    /*next = prev + reslut[i] > cur ?  prev + reslut[i]:cur;*/
                    df[i] = df[i - 1] > df[i - 2] + reslut[i] ? df[i - 1] : df[i - 2] + reslut[i];
                }
                else
                {
                    df[i] = df[i - 1] + reslut[i] > df[i - 2] + reslut[i] ? df[i - 1] + reslut[i] : df[i - 2] + reslut[i];
                }
                //else//2 3  5 6 7
                //{
                //    cur += reslut[i];
                //    prev += reslut[i];
                //    next = prev > cur ? prev  : cur;
                //}
                //prev = cur;
                //cur = next;
            }
            return df[flat.size() - 1];
        }
    }
    //bool _can(vector<int>& nums,int cur,int sz)
    //{
    //    if (cur >= sz - 1)
    //    {
    //        return true;
    //    }
    //    for (int i= nums[cur];i>=1;i--)
    //    {
    //        if (_can(nums, cur + i, nums.size()))
    //        {
    //            return true;
    //        }
    //    }
    //    return false;
    //}
    //bool canJump(vector<int>& nums) {
    //    int cur = 0;
    //    return _can(nums,cur,nums.size());
    //}
    bool canJump(vector<int>& nums) {
        int max_distance = 0;//2 1 1 3 4
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > max_distance)
            {
                return false;
            }
            if (i + nums[i] > max_distance)
            {
                max_distance = i + nums[i];
            }
            if (max_distance >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
    //void _jump(vector<int>& nums,int i, int& cur,int& ans,int sz)
    //{
    //    if (cur >= sz-1)
    //    {
    //        if (i < ans||ans==0)
    //        {
    //            cout<<i<<endl;
    //            ans = i;
    //        }
    //        return;
    //    }
    //    for (int j = 1; j <=nums[cur]; j++)//21134
    //    {
    //        cur+=j;//cur是记录下表
    //        i++;//记录跳的次数
    //        _jump(nums, i,cur, ans,sz);
    //        cur -= j;
    //        i--;
    //    }
    //}
    //int jump(vector<int>& nums) {
    //    int ret = 0;
    //    int ans = 0;
    //    _jump(nums,0,ret,ans,nums.size());
    //    return ans;
    //}
    //int jump(vector<int>& nums) {
    //    int cur = 0;
    //    int i = nums.size() - 1;
    //   while(i>0)
    //    {
    //       int min_distance = 99999;
    //        for (int j=i-1;j>=0;j--)
    //        {
    //            if (j+nums[j]>=i)
    //            {
    //                min_distance = min(min_distance,j);
    //            }
    //        }
    //        cur++;
    //        i = min_distance;
    //    }
    //    return cur;
    //}
    //int jump(vector<int>& nums) {
    //    int ans = 0;
    //    int max_distance = 0;
    //    int end =0;//2,3,1,1,4
    //    for (int i = 0; i < nums.size()-1; i++)
    //    {
    //        max_distance = max(max_distance, i + nums[i]);
    //        if(end==i)
    //        {
    //            end = max_distance;
    //            ans++;
    //        }
    //    }
    //    return ans;
    //}
    int jump(vector<int>& nums) {
        int max_distance = 0;
        int ans = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            max_distance = max(max_distance, i + nums[i]);
            if (end == i)
            {
                ans++;
                end = max_distance;
            }
        }
        return ans;
    }
    //double myPow(double x, int n) {
    //    double ans = x;
    //    int mid = 1;
    //    int left = 0;
    //    int right = 0;
    //    int tmp = 1;
    //    while (left<right&&left!=0)
    //    {
    //        while (mid*2<=n)
    //        {
    //            tmp = ans;
    //            ans = ans * ans;
    //            mid = mid * 2;
    //            right = mid * 2;
    //            left = mid;
    //        }
    //        mid = (left + right) >> 1;
    //        ans = ans * tmp;
    //        if (n>mid)
    //        {
    //            left = mid+1;

    //        }
    //        else if (n==mid)
    //        {
    //            break;
    //        }
    //        else
    //        {
    //            right = mid-1;
    //        }
    //    }
    //}
    //double _myPow(double x, int n)
    //{
    //    if (n== 1)
    //    {
    //        return x;
    //    }
    //    else
    //    {
    //        return x*_myPow(x,n-1);
    //    }
    //}
    //double myPow(double x, int n) {
    //    if (n == 0)
    //    {
    //        return 1;
    //    }
    //    if (n < 0)
    //    {
    //        return 1/_myPow(x, -n);
    //    }
    //    else
    //    {
    //        return _myPow(x,n);
    //    }
    //}
    //double _myPow(double x, int n)
    //{
    //    if (n==1)
    //    {
    //        return x;
    //    }
    //    else
    //    {
    //        int ret = n % 2;
    //        double ans = _myPow(x, (n-ret)/2);
    //        ans = ans * ans;
    //        for (int i = 0; i < ret; i++)
    //        {
    //            ans = ans * x;
    //        }
    //        return ans;
    //    }
    //}
    //double myPow(double x, int n) {
    //   if (n == 0)
    //   {
    //       return 1;
    //   }
    //   if (n < 0)
    //   {
    //       int tmp = 0;
    //       if (n == -2147483648)
    //       {
    //           return 1 / (_myPow(x, 2147483647)*x);
    //       }
    //       else
    //       {
    //           return 1 / _myPow(x,-n);
    //       }
    //   }
    //   else
    //   {
    //       return _myPow(x,n);
    //   }
    //}
    double quickpow(double x, int n)
    {
        double ans = 1;
        double sum = x;
        while (n > 0)
        {
            if (n & 1)
            {
                ans = ans * sum;
            }
            n = n >> 1;
            sum = sum * sum;
        }
        return ans;
    }
    double myPow(double x, int n) {
        if (n == 0)
        {
            return 1;
        }
        if (n == -2147483648)
        {
            return 1 / (quickpow(x, 2147483648) * x);
        }
        else
        {
            return n > 0 ? quickpow(x, n) : quickpow(x, -n);
        }
    }
    //bool quickAdd(int divisor, int mid, int dividend)
    //{
    //    int result = 0;
    //    int add = divisor;
    //    while (mid > 0)// -4   -2
    //    {
    //        if (mid & 1)
    //        {
    //            if (dividend > result + add)
    //            {
    //                return false;
    //            }
    //            result = result + add;
    //        }
    //        if (mid != 1) {
    //            // 需要保证 add + add >= x
    //            if (add < dividend - add) {
    //                return false;
    //            }
    //            add += add;
    //        }
    //         //if (dividend >add)
    //         //{
    //         //    return false;
    //         //}
    //         //add += add;
    //        mid = mid >> 1;
    //    }
    //    //if (result<dividend)
    //    //{
    //    //    return false;
    //    //}
    //    return true;
    //}
    //bool  quickAdd(int y, int z, int x) {
    //    // x 和 y 是负数，z 是正数
    //    // 需要判断 z * y >= x 是否成立
    //    int result = 0, add = y;
    //    while (z) {
    //        if (z & 1) {
    //            // 需要保证 result + add >= x
    //            if (result < x - add) {
    //                return false;
    //            }
    //            result += add;
    //        }
    //        if (z != 1) {
    //            // 需要保证 add + add >= x
    //            if (add < x - add) {
    //                return false;
    //            }
    //            add += add;
    //        }
    //        // 不能使用除法
    //        z >>= 1;
    //    }
    //    return true;
    //}
        //int divide(int dividend, int divisor) {
        //    if (dividend == 0)
        //    {
        //        return 0;
        //    }
        //    if (dividend == INT_MIN)
        //    {
        //        if (divisor == 1)
        //        {
        //            return INT_MIN;
        //        }
        //        if (divisor == -1)
        //        {
        //            return INT_MAX;
        //        }
        //    }
        //    if (divisor == INT_MIN)
        //    {
        //        if (dividend == INT_MIN)
        //        {
        //            return 1;
        //        }
        //        else
        //        {
        //            return 0;
        //        }
        //    }
        //    bool flat1 = false;
        //    bool flat2 = false;
        //    if (dividend > 0)
        //    {
        //        flat1 = true;
        //        dividend = -dividend;
        //    }
        //    if (divisor > 0)
        //    {
        //        flat2 = true;
        //        divisor = -divisor;
        //    }//z*y>=x 求最大的z
        //    int left = 1;
        //    int ans = 0;
        //    int right = INT_MAX;
        //    while (left <= right)
        //    {
        //        int mid = left + ((right - left) >> 1);
        //        bool flat = quickadd(dividend, mid, divisor);// -4 -2 1
        //        if (flat)
        //        {
        //            ans = mid;
        //            if (mid == INT_MAX)
        //            {
        //                break;
        //            }
        //            left = mid + 1;
        //        }
        //        else
        //        {
        //            right = mid - 1;
        //        }
        //        cout << "left" << left << " " << "right" << right << endl;;
        //    }
        //    if (ans == 0)
        //    {
        //        return 0;
        //    }
        //    if (flat1 == flat2)
        //    {
        //        return ans;
        //    }
        //    return -ans;
        //}
    //    int divide(int dividend, int divisor) {
    //    // 考虑被除数为最小值的情况
    //    if (dividend == INT_MIN) {
    //        if (divisor == 1) {
    //            return INT_MIN;
    //        }
    //        if (divisor == -1) {
    //            return INT_MAX;
    //        }
    //    }
    //    // 考虑除数为最小值的情况
    //    if (divisor == INT_MIN) {
    //        return dividend == INT_MIN ? 1 : 0;
    //    }
    //    // 考虑被除数为 0 的情况
    //    if (dividend == 0) {
    //        return 0;
    //    }

    //    // 一般情况，使用二分查找
    //    // 将所有的正数取相反数，这样就只需要考虑一种情况
    //    bool rev = false;
    //    if (dividend > 0) {
    //        dividend = -dividend;
    //        rev = !rev;
    //    }
    //    if (divisor > 0) {
    //        divisor = -divisor;
    //        rev = !rev;
    //    }
    //    int left = 1, right = INT_MAX, ans = 0;
    //    while (left <= right) {
    //        // 注意溢出，并且不能使用除法
    //        int mid = left + ((right - left) >> 1);
    //        bool check = quickAdd(divisor, mid, dividend);
    //        if (check)
    //        {
    //            ans = mid;
    //            // 注意溢出
    //            if (mid == INT_MAX) 
    //            {
    //                break;
    //            }
    //            left = mid + 1;
    //        }
    //        else
    //        {
    //            right = mid - 1;
    //        }
    //    }

    //    return rev ? -ans : ans;
    //}
};
//2,3,1,1,4
//
//
int main()
{
    Solution s;
 /*   vector<int> tmp = { 4, 5, 6, 7, 0, 1, 2 };*/
   /* vector<int> tmp = {5,1,3};
    cout << s.search(tmp,1) << endl;*/
 /*   vector<int> tmp = { 186,419,83,408 };*/
    /*vector<int> tmp = {1,2,5};
    cout << s.change(5,tmp);*/
   /* cout<<s.climbStairs(6);*/
    //vector<int> tmp = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    /*vector<int> tmp = {10,15,20};*/
    //vector<int> tmp={0,0,1,1};
    //cout << s._minCostClimbingStairs(tmp);
    //vector<int> tmp = { 2,7,9,3,1 };
    //vector<int> tmp = { 0,0 };
    //cout << s.rob2(tmp);
    //vector<int> tmp = { 2,2,3,3,3,4 };
    //cout << s.deleteAndEarn(tmp);
     //*vector<int> tmp = {9997,9957,9956,937,9276,9275,9274,9273,9272,9271,9270,9269,9268,9267,9266,9265,9264,9263,9262,9261,9260,9259,9258,9257,9256,9255,9254,9253,9252,9251,9250,9249,9248,9247,9246,9245,9244,9243,9242,9241,9240,9239,1242,1241,1240,1239,1238,1237,1236,1235,1234,1233,1232,1231,1230,1229,1228,1227,1226,1225,1224,1223,1222,1221,1220,1219,1218,1217,1216,1215,1214,1213,1212,1211,1210,1209,1208,1207,1206,1205,1204,1203,1202,1201,1200,1199,1198,1197,1196,1195,1194,1193,1192,1191,1190,1189,1188,1187,1186,1185,1184,1183,1182,1181,1180,1179,1178,1177,1176,1175,1174,1173,1172,1171,1170,1169,1168,1167,1166,1165,1164,1163,1162,1161,1160,1159,1158,1157,1156,1155,1154,1153,1152,1151,1150,1149,1148,1147,1146,1145,1144,1143,1142,1141,1140,1139,1138,1137,1136,1135,1134,1133,1132,1131,1130,1129,1128,1127,1126,1125,1124,1123,1122,1121,1120,1119,1118,1117,1116,1115,1114,1113,1112,1111,1110,1109,1108,1107,1106,1105,1104,1103,1102,1101,1100,1099,1098,1097,1096,1095,1094,1093,1092,1091,1090,1089,1088,1087,1086,1085,1084,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064,1063,1062,1061,1060,1059,1058,1057,1056,1055,1054,1053,1052,1051,1050,1049,1048,1047,1046,1045,1044,1043,1042,1041,1040,1039,1038,1037,1036,1035,1034,1033,1032,1031,1030,1029,1028,1027,1026,1025,1024,1023,1022,1021,1020,1019,1018,1017,1016,1015,1014,1013,1012,1011,1010,1009,1008,1007,1006,1005,1004,1003,1002,1001,1000,999,998,997,996,995,994,993,992,991,990,989,988,987,986,985,984,983,982,981,980,979,978,977,976,975,974,973,972,971,970,969,968,967,966,965,964,963,962,961,960,959,958,957,956,955,954,953,952,951,950,949,948,947,946,945,944,943,942,941,940,939,938,937,936,935,934,933,932,931,930,929,928,927,926,925,924,923,922,921,920,919,918,917,916,915,914,913,912,911,910,909,908,907,906,905,904,903,902,901,900,899,898,897,896,895,894,893,892,891,890,889,888,887,886,885,884,883,882,881,880,879,878,877,876,875,874,873,872,871,870,869,868,867,866,865,864,863,862,861,860,859,858,857,856,855,854,853,852,851,850,849,848,847,846,845,844,843,842,841,840,839,838,837,836,835,834,833,832,831,830,829,828,827,826,825,824,823,822,821,820,819,818,817,816,815,814,813,812,811,810,809,808,807,806,805,804,803,802,801,800,799,798,797,796,795,794,793,792,791,790,789,788,787,786,785,784,783,782,781,780,779,778,777,776,775,774,773,772,771,770,769,768,767,766,765,764,763,762,761,760,759,758,757,756,755,754,753,752,751,750,749,748,747,746,745,744,743,742,741,740,739,738,737,736,735,734,733,732,731,730,729,728,727,726,725,724,723,722,721,720,719,718,717,716,715,714,713,712,711,710,709,708,707,706,705,704,703,702,701,700,699,698,697,696,695,694,693,692,691,690,689,688,687,686,685,684,683,682,681,680,679,678,677,676,675,674,673,672,671,670,669,668,667,666,665,664,663,662,661,660,659,658,657,656,655,654,653,652,651,650,649,648,647,646,645,644,643,642,641,640,639,638,637,636,635,634,633,632,631,630,629,628,627,626,625,624,623,622,621,620,619,618,617,616,615,614,613,612,611,610,609,608,607,606,605,604,603,602,601,600,599,598,597,596,595,594,593,592,591,590,589,588,587,586,585,584,583,582,581,580,579,578,577,576,575,574,573,572,571,570,569,568,567,566,565,564,563,562,561,560,559,558,557,556,555,554,553,552,551,550,549,548,547,546,545,544,543,542,541,540,539,538,537,536,535,534,533,532,531,530,529,528,527,526,525,524,523,522,521,520,519,518,517,516,515,514,513,512,511,510,509,508,507,506,505,504,503,502,501,500,499,498,497,496,495,494,493,492,491,490,489,488,487,486,485,484,483,482,481,480,479,478,477,476,475,474,473,472,471,470,469,468,467,466,465,464,463,462,461,460,459,458,457,456,455,454,453,452,451,450,449,448,447,446,445,444,443,442,441,440,439,438,437,436,435,434,433,432,431,430,429,428,427,426,425,424,423,422,421,420,419,418,417,416,415,414,413,412,411,410,409,408,407,406,405,404,403,402,401,400,399,398,397,396,395,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,377,376,375,374,373,372,371,370,369,368,367,366,365,364,363,362,361,360,359,358,357,356,355,354,353,352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336,335,334,333,332,331,330,329,328,327,326,325,324,323,322,321,320,319,318,317,316,315,314,313,312,311,310,309,308,307,306,305,304,303,302,301,300,299,298,297,296,295,294,293,292,291,290,289,288,287,286,285,284,283,282,281,280,279,278,277,276,275,274,273,272,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,0};
    //cout << tmp.size();
    // vector<int> tmp = {2,1,1,3,4};
    //if (s.canJump(tmp))
    //{
    //    cout << "可以到达";
    //}
    //else
    //{
    //    cout << "不能到达";
    //}
    //vector<int> tmp = {4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,};
    ////vector<int> tmp = {2,5,1,1,4};
    //cout << s.jump(tmp);
    //cout << s.myPow(0.00001, 2147483647);
   /* cout << s.myPow(2,-2);*/
    //cout << s._myPow(2, 4);
    cout << s.divide(-2147483648,-2)<<endl;
    //cout << s.quickadd(-10,(INT_MAX-1)>>1,-3);
    return 0;
}
//
// -2147483648
//- 1
//	[4, 5, 6, 7, 0, 1, 2]
//[4,5,6,7,0,1,2]
//[186,419,83,408]
//
// [186,419,83,408]
// 
// 13 5
// 8 5
// 5 3
// 3 2 
// 2 1
// 
// 0.00001
// 
// [1,1,1,2,4,5,5,5,6]
// 
// 
//2 3 4 5 6 7
//2 4 6
//3 5 7
//f(n)=f(n-)+1
//
// 
// 2,3,1,2,4,2,3
// 
// -2147483648
//2
// 
//