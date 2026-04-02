class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int mn, mx;
        mn = mx = 1;
        for(int x : nums){
            int tmp = mx * x;
            mx = max(max(x*mx, x*mn), x);
            mn = min(min(tmp, x*mn), x);
            ans = max(ans, mx);
        }
        return ans;
    }
};
