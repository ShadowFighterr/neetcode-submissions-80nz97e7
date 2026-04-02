class Solution {
public:
    int numDecodings(string s) {
        return dfs(s, 0);
        // int dp[n];
        // dp[0] = 1;
        // for(int i = 1; i < n; i++){
        //     dp[i] = dp[i-1] + 
        // }
    }

    int dfs(string& s, int idx){
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        int val;
        if(idx+1 != s.size()) val = ((s[idx]-'0')*10) + (s[idx+1]-'0');
        else return dfs(s, idx+1);
        if(val >= 10 && val <= 26) return dfs(s, idx+1) + dfs(s, idx+2);
        else return dfs(s, idx+1);
    }
};
