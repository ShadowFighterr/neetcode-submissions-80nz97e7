#include <cstring>

class Solution {
public:
    int dp[5001][101];
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return dfs(coins, amount, 0);
    }
    int dfs(vector<int>& coins, int cnt, int i){
        if(cnt < 0 || i == coins.size()) return 0;
        if(cnt == 0) return 1;
        
        if(dp[cnt][i] != -1) return dp[cnt][i];
        int take = dfs(coins, cnt-coins[i], i);
        int skip = dfs(coins, cnt, i+1);
        return dp[cnt][i] = take+skip; 
    }
};
