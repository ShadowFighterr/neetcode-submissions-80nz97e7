class Solution {
public:
    string longestPalindrome(string s) {
        int mx = INT_MIN;
        string t;
        for(int i = 0; i < s.size(); i++){
            if(i+1 < s.size() && s[i] == s[i+1]){
                int l = i, r = i+1;
                while(l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r;
                if(r-l-1 > mx) mx = r-l-1, t = s.substr(l+1, r-l-1);
            }
            int l = i-1, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) --l, ++r;
            if(r-l-1 > mx) mx = r-l-1, t = s.substr(l+1, r-l-1);
        }
        return t;
    }
};
