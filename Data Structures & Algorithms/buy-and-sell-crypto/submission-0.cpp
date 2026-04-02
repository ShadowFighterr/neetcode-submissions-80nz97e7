class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int j = 0, mx = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < prices[j]) j = i;
            mx = max(mx, prices[i]-prices[j]);
        }
        return mx;
    }
};
