class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1, m;
        int x;
        while(l <= r)
        {
            m = (l+r)/2;
            if(x == m) break;
            if(nums[m] > nums[r]) l = m;
            else r = m;
            // int x, y;
            // x = abs(nums[r]-nums[m]);
            // y = abs(nums[l]-nums[m]);
            // if(x < y) l = m;
            // else r = m;
            cout << l << ' ' << r << '\n';
            x = m;
        }
        int y = 1e9;
        for(int i = l; i <= r; i++) y = min(y, nums[i]);
        return y;
    }
};
