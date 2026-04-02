class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums)
        {
            mp[x]++;
            if(mp[x] > 1) return x;
        }
    }
};
