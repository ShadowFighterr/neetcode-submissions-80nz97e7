class Solution {
public:
    int sum;
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(n == 1 || (sum&1)) return false;
        memo.resize(n, vector<int>(sum/2+1, -1));
        return dfs(nums, 0, 0);
    }
    bool dfs(vector<int>& nums, int idx, int cnt){
        if(cnt == sum/2) {return true;}
        if(idx == nums.size()) return cnt == sum/2;
        if(cnt > sum/2) return false;
        if(memo[idx][cnt] != -1) return memo[idx][cnt];
        memo[idx][cnt] = dfs(nums, idx+1, cnt) || dfs(nums, idx+1, cnt+nums[idx]);
        return memo[idx][cnt];
    }
};
