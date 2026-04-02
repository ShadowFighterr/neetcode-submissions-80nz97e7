class Solution {
public:
    int numDistinct(string s, string t) {
        return dfs(s, t, 0, 0);
    }

    int dfs(string& s, string& t, int i, int j){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        int use, skip;
        skip = dfs(s, t, i+1, j);
        if(s[i] == t[j]){
            use = dfs(s, t, i+1, j+1);
        }
        return use+skip;
    }
};
