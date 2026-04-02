class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int tmp = 0;
        for(int num : nums){
            tmp = max(num, num+tmp);
            res = max(res, tmp);
        }
        return res;
    }
};
