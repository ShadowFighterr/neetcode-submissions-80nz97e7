class Solution {
public:
    int maxCoins(vector<int>& nums) {
        return dfs(nums);
    }
    int dfs(vector<int>& nums){
        if(nums.empty()) return 0;
        
        int maxCoins = 0;
        for(int i = 0; i < nums.size(); i++){
            int x, y;
            x = y = 1; 
            if(i-1 >= 0) x = nums[i-1];
            if(i+1 < nums.size()) y = nums[i+1];
            int coins = x*y*nums[i];
            vector<int> tmp = nums;
            tmp.erase(tmp.begin()+i);
            coins += dfs(tmp);
            maxCoins = max(maxCoins, coins);
        }
        return maxCoins;
    }
};
