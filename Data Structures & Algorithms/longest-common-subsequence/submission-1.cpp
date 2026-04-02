class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.assign(text1.size(), vector<int> (text2.size(), -1));
        return dfs(text1, text2, 0, 0);
    }

    int dfs(string &s, string &t, int i, int j){
        if(i == s.size() || j == t.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]) dp[i][j] =  1 + dfs(s, t, i+1, j+1);
        else dp[i][j] =  max(dfs(s, t, i, j+1), dfs(s, t, i+1, j));
        return dp[i][j];
    }
};
