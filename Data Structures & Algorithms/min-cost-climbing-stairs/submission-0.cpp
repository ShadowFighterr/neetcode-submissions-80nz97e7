class Solution {
public:
    int res = INT_MAX;
    int minCostClimbingStairs(vector<int>& cost) {
        dfs(cost, 0, cost[0]);
        dfs(cost, 1, cost[1]);
        return res;
    }

    void dfs(vector<int>& cost, int idx, int cur){
        if(idx >= cost.size()){
            res = min(res, cur);
            return;
        }
        int tmp = cur;
        if(idx+1 < cost.size()) tmp = cur, cur+=cost[idx+1];
        dfs(cost, idx+1, cur);
        cur = tmp;
        int tmp1 = cur;
        if(idx+2 < cost.size()) tmp1 = cur, cur+=cost[idx+2];
        dfs(cost, idx+2, cur);
        cur = tmp1;
    }
};
/* 1 2 3
    1
   2 3

*/