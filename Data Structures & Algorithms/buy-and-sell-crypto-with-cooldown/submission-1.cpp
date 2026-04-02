class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        return dfs(prices, 0, true);
    }
    
    int dfs(vector<int>& prices, int i, bool ok){
        if(i >= prices.size()) return 0;
        int cooldown = dfs(prices, i+1, ok);
        if(ok){
            int buy = dfs(prices, i+1, false) - prices[i];
            return max(buy, cooldown);
        }
        else{
            int sell = dfs(prices, i+2, true) + prices[i];
            return max(sell, cooldown);
        }
    }
};
