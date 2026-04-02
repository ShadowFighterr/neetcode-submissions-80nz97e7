class Solution {
vector<vector<int>> dp;
int total;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        total = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2*total+1, INT_MIN));
        return dfs(nums, target, 0, 0);
    }
    int dfs(vector<int>& nums, int x, int i, int cur){
        if(i == nums.size()) {
            return cur == x;
        }
        if(dp[i][cur+total] != INT_MIN) return dp[i][cur+total];
        int p, m;
        p = dfs(nums, x, i+1, cur+nums[i]);
        m = dfs(nums, x, i+1, cur-nums[i]);
        return dp[i][total+cur] = p + m;
    }
};
