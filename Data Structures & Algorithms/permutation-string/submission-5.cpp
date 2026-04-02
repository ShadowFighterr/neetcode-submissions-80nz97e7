class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        int l = 0;
        for(char c : s1) mp[c]++;
        s2+=s2[s2.size()-1];
        for(int r = 0; r < s2.size(); r++)
        {
            if(mp[s2[r]])
            {
                l = r;
                unordered_map<char, int> tmp;
                while(r < s2.size())
                {
                    tmp[s2[r]]++;
                    if(tmp[s2[r]] > mp[s2[r]]) break;
                    if(r-l+1 == s1.size()) return true;   
                    ++r;
                }
                r = l;
            }
        }
        return false;
    }
};
