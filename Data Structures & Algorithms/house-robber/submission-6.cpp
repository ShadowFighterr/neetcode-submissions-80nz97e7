class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int x = nums[0];
        int y = max(nums[0], nums[1]);
        int res = y;
        for(int i = 2; i < nums.size(); i++){
            res = max(y, nums[i]+x);
            x = y, y = res;
        }
        return res;
    }
};
