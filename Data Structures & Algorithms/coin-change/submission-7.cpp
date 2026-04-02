class Solution {
public:
    unordered_map<int, int> memo;
    int coinChange(vector<int>& coins, int amount) {
        int mn =  dfs(coins, amount);
        return ((mn >= 1e9) ? -1 : mn);
    }
    int dfs(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if(memo.find(amount) != memo.end()) return memo[amount];
        int res = 1e9;
        for(int x : coins) 
        {
            if(amount - x >= 0){
                int result = dfs(coins, amount - x);
                if(result != 1e9) res = min(res, 1+result);
            }
        }
        memo[amount] = res;
        return res;
    }
};
