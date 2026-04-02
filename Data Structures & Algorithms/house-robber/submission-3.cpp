class Solution {
public:
    vector<int> memo;
    int rob(vector<int>& nums) {
        memo.assign(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int idx){
        if(idx >= nums.size()){
            return 0;
        }
        if(memo[idx] != -1) return memo[idx];
        memo[idx] = max(dfs(nums, idx+1), nums[idx] + dfs(nums, idx+2));
        return memo[idx];
    }
};
