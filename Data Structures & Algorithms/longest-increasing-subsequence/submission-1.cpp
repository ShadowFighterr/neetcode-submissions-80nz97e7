class Solution {
public:
    unordered_map<int, bool> mp;
    int res = 1;
    int lengthOfLIS(vector<int>& nums) {
        dfs(nums, 0, -1001, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int idx, int prev, int cnt){
        if(idx == nums.size()){res = max(res, cnt); return;}
        cout << prev << ' ';
        res = max(res, cnt);
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] > prev) dfs(nums, i+1, nums[i], cnt+1);
            // dfs(nums, idx+2, nums[i+1], cnt+1);
            // if(nums[i] <= prev) return;
        }
        cout << '\n';
    }
};
