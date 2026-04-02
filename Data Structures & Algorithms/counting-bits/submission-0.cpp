class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> vec;
        for(int i = 0; i <= n; i++) vec.push_back(__builtin_popcount(i));
        return vec;
    }
};
