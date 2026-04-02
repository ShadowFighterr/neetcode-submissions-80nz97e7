class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m;
        while(l < r)
        {
            m = (l+r)/2;
            if(nums[m] > nums[r]) l = m+1;
            else r = m;
            cout << l << ' ' << r << '\n';
        }
        int x = lower_bound(nums.begin(), nums.begin()+l, target) - nums.begin();
        int y = lower_bound(nums.begin()+l, nums.begin()+nums.size()-1, target) - nums.begin();
        if(nums[x] == target) return x;
        else if(nums[y] == target) return y;
        else return -1;
    }
};
