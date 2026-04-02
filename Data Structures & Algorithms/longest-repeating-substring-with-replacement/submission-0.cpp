class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp;
        int l = 0, mx = 0;
        for(int r = 0; r < s.size(); r++)
        {
            mp[s[r]]++;
            int n = (int)s.size();
            int tmp = 0;
            for(int i = 0; i < 26; i++) tmp = max(tmp, mp['A'+i]);
            if((r-l+1)-tmp > k)
            {
                while((r-l+1)-tmp > k) 
                {
                    cout << tmp << ' ';
                    mp[s[l]]--, ++l;
                    int tmp1 = 0;
                    for(int i = 0; i < 26; i++) tmp1 = max(tmp1, mp['A'+i]);
                    tmp = tmp1;
                }
            }
            mx = max(mx, r-l+1);
        }
        return mx;
    }
};
