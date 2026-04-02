class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> v;
        for(int i = 1; i <= n; i++) s+="(";
        for(int i = 1; i <= n; i++) s+=")";
        do
        {
            // cout << s << '\n';
            stack<char> st;
            bool ok = true;
            for(char c : s)
            {
                if(c == '(') st.push(c);
                else 
                {
                    if(st.empty()) {ok = false; break;}
                    st.pop();
                }
            }
            if(ok) v.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        return v;
    }
};
