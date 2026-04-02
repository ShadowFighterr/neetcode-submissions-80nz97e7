class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> cur = nums;
        int mx = INT_MIN;
        dp[0] = cur[0];
        dp[1] = max(cur[0], cur[1]);
        for(int x = 0; x < 4; x++){
            for(int i = 2; i < cur.size()-1; i++){
                dp[i] = max(dp[i-1], dp[i-2]+cur[i]);
            }
            for(int y : dp) cout << y << ' ';
            cout << '\n';
            mx = max(mx, dp[nums.size()-2]);
            rotate(cur.begin(), cur.begin() + 1, cur.end());
            dp.clear();
            dp.resize(cur.size());
            dp[0] = cur[0];
            dp[1] = max(cur[0], cur[1]);
        }
        return mx;
    }
};