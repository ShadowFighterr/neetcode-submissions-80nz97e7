class Solution {
public:

    vector<int> sorted(vector<int> vec)
    {
        sort(vec.begin(), vec.end());
        return vec;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> v;
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = nums.size()-1; j > i; j--)
            {
                int x = -(nums[i]+nums[j]);
                int y = (x==nums[i]) + (x==nums[j]);
                if(mp[x] != 0 && mp[x] > y) s.insert(sorted({nums[i], x, nums[j]}));
            }
        }
        for(auto a : s) v.push_back(a);
        return v;
    }
};