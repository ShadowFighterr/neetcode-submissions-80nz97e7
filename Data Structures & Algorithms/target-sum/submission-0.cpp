class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0, 0);
    }
    int dfs(vector<int>& nums, int x, int i, int cur){
        if(i == nums.size()) {
            if(cur != x) return 0;
            else return 1;
        }
        // if(cur == x) return 1;
        int p, m;
        p = dfs(nums, x, i+1, cur+nums[i]);
        m = dfs(nums, x, i+1, cur-nums[i]);
        return p+m;
    }
};
