class Solution {
public:
    int ans = INT_MAX;
    int jump(vector<int>& nums) {
        dfs(nums, 0, 0);
        return ans;
    }

    void dfs(vector<int>& nums, int idx, int cnt){
        if(idx == nums.size()-1) {ans = min(ans, cnt); return;}
        if(idx >= nums.size()) return;

        for(int i = 1; i <= nums[idx]; i++){
            dfs(nums, idx+i, cnt+1);
        }
    }
};
