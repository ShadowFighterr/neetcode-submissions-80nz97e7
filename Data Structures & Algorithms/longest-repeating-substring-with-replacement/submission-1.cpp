class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int l = 0, mx = 0, res = 0;
        for(int r = 0; r < s.size(); r++)
        {
            mp[s[r]]++;
            mx = max(mx, mp[s[r]]);
            while((r-l+1)-mx > k)
            {
                mp[s[l]]--;
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
