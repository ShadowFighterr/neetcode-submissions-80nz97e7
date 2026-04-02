class Solution {
public:

    bool check(char c)
    {
        c = tolower(c);
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            bool x, y;
            x = check(s[i]);
            y = check(s[j]);
            if(x && y) 
            {
                // cout << s[i] << s[j] << '\n';
                if(tolower(s[i]) != tolower(s[j])) return false;
                i++, j--;
            }
            if(!x) ++i;
            if(!y) --j;
        } 
        return true;
    }
};
