class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        set<int> s;
        map<int, int> mp;
        for(int a : nums)
        {
            s.insert(a);
            mp[a]++;
        }
        for(int a : s) v.push_back({mp[a], a});
        sort(v.rbegin(), v.rend());
        vector<int> vec;
        for(int i = 0; i < k; i++) vec.push_back(v[i].second);
        return vec;
    }
};
