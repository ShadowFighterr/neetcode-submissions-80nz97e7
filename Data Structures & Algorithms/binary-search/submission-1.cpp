class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), m;
        while(l <= r)
        {
            m = ((l+r)/2);
            if(nums[m] == target) return m;
            ((nums[m] > target) ?  r = m-1 : l = m+1);
        }
        return -1;
    }
};
