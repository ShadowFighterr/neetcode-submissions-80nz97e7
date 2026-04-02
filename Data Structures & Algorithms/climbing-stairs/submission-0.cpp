class Solution {
public:
    int res = 0;
    int climbStairs(int n) {
        dfs(n);
        return res;
    }

    void dfs(int n){
        if(n < 0) return;
        if(n == 0) {
            res++; 
            return;
        }
        dfs(n-1);
        dfs(n-2);
    }
};
