class Solution {
public:

    bool equal(const int* a, const int* b)
    {
        for(int i = 0; i < 52; i++) 
        {
            if(a[i] == -1) continue;
            else if(b[i] < a[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int pref[52] = {}, pref1[52] = {};
        for (int i = 0; i < t.size(); i++) {
            if(t[i] < 'a') pref[(tolower(t[i]) - 'a')+26]++;
            else pref[t[i] - 'a']++;
        }
        for(int i = 0; i < 52; i++) if(pref[i] == 0) pref[i] = -1;
        int j = 0, mn = s.size();
        string res = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(equal(pref, pref1))
            {
                // cout << i << ' ';
                while(equal(pref, pref1))
                {
                    if(s[j] < 'a') pref1[(tolower(s[j]) - 'a')+26]--;
                    else pref1[s[j] - 'a']--;
                    ++j;
                }
                if(i-j+1 <= mn)
                {
                    res = s.substr(j-1, i-j+1);
                    mn = i-j+1;
                }
            }
            if(s[i] < 'a') pref1[(tolower(s[i])-'a')+26]++;
            else pref1[tolower(s[i])-'a']++;
        }
        if(equal(pref, pref1))
        {
            while(equal(pref, pref1))
                {
                    if(s[j] < 'a') pref1[(tolower(s[j]) - 'a')+26]--;
                    else pref1[s[j] - 'a']--;
                    ++j;
                }
                int x = s.size();
                if(x-j+1 <= mn)
                {
                    res = s.substr(j-1, x-j+1);
                    mn = x-j+1;
                }
        }
        return res;
    }
};
/*s="ab"
t="A"*/