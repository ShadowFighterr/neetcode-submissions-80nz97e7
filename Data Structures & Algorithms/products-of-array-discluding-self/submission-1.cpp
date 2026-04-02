class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int x = nums.size();
        int pref[x], suff[x];
        pref[0] = 1;
        suff[x-1] = 1;
        for(int i = 1; i < x; i++) pref[i] = nums[i-1]*pref[i-1];
        for(int i = x-2; i >= 0; i--) suff[i] = suff[i+1]*nums[i+1];
        vector<int> vec;
        for(int i = 0; i < x; i++) vec.push_back(pref[i]*suff[i]);
        return vec;
    }
};
