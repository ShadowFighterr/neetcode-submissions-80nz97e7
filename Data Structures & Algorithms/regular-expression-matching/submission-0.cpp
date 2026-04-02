class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
    }
    bool dfs(string& s, string& p, int i, int j){
        if(j == p.size()) return i == s.size();

        bool ok = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        if(j+1 < p.size() && p[j+1] == '*'){
            return dfs(s, p, i, j+2) || (ok && dfs(s, p, i+1, j));
        } 
        if(ok){
            return dfs(s, p, i+1, j+1);
        }

        return false;
    }
};
