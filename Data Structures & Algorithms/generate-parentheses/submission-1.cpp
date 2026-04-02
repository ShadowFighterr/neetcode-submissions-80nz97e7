class Solution {
public:

    void backtrackk(int a, int b, int n, vector<string>& v, string& s)
    {
        if(a == b &&  a == n)
        {
            v.push_back(s);
            return;
        }

        if(a < n)
        {
            s+='(';
            backtrackk(a+1, b, n, v, s);
            s.pop_back();
        }
        if(a > b)
        {
            s+=')';
            backtrackk(a, b+1, n, v, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string s;
        backtrackk(0, 0, n, v, s);
        return v;
    
    }
};
