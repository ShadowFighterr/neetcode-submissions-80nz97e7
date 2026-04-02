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
        for(int i = 0; i < nums.size()-2; i++)
        {
            int j = nums.size()-1;
            int k = i+1;
            int t = (-nums[i]);
            while(k < j)
            {
                cout << k << ' ' << j << '\n';
                if(nums[k]+nums[j] > t) --j;
                else if(nums[j]+nums[k] == t) 
                    {s.insert({nums[i], nums[k], nums[j]}); ++k;}
                else ++k;
            }
            // -4 -1 -1 0 1 2 
        }
        for(auto a : s) v.push_back(a);
        return v;
    }
};