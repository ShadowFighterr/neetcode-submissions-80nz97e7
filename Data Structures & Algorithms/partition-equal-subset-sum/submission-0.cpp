class Solution {
public:
    int sum;
    bool res = false;
    bool canPartition(vector<int>& nums) {
        sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(n == 1 || (sum&1)) return false;
        dfs(nums, 0, 0);
        return res;
    }
    void dfs(vector<int>& nums, int idx, int cnt){
        if(cnt == sum/2) {res = true; return;}
        if(idx == nums.size()) return;
        for(int i = idx; i < nums.size(); i++){
            dfs(nums, i+1, cnt+nums[i]);
        }
    }
};
