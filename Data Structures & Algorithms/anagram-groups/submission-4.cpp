class Solution {
public:

    long long hashv(string s)
    {
        if(s.empty()) return 0;
        sort(s.begin(), s.end());
        long long cnt = 0, p = 1;
        const long long MOD = 1e9+7;
        for(int i = s.size()-1; i >= 0; i--)
        {
            cnt = ((cnt%MOD) + (int(s[i])*p)%MOD)%MOD;
            p = (p*31)%MOD;
        }
        return cnt;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> vec(1001);
        for(int i = 0; i < strs.size(); i++)
        {
            long long x = hashv(strs[i]);
            //cout << x <<" ";
            vec[x%1001].push_back(strs[i]);
        }
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i].empty()) vec.erase(vec.begin()+i), --i;
        }
        return vec;
    }
};
