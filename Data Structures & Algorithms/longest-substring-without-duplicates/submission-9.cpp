class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        for(char c : s) mp[c] = -1;
        int j = 0, mx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] != -1)
            {
                mx = max(mx, i-j);
                int x = mp[s[i]];
                for(int k = j; k <= mp[s[i]]; k++) mp[s[k]] = -1;
                j = x+1;
                mp[s[i]] = i;
                
            }
            else mp[s[i]] = i;
        }
        mx = max(mx, (int)s.size()-j);
        return mx;
    }
};
