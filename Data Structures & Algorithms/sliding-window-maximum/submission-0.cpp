class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<int> s;
        map<int, int> mp;
        vector<int> v;
        for(int i = 0; i < k; i++) s.insert(nums[i]), mp[nums[i]]++;
        v.emplace_back(*s.rbegin());
        for(int i = k; i < nums.size(); i++)
        {
            mp[nums[i-k]]--, mp[nums[i]]++, s.insert(nums[i]);
            if(mp[nums[i-k]] <= 0) s.erase(nums[i-k]);
            v.emplace_back(*s.rbegin());
            for(int x : s) cout << x << ' ';
            cout << '\n';
        }
        return v;
    }
};
