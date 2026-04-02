class Solution {
public:
    int m;
    int climbStairs(int n) {
        m = n;
        return dfs(0);
    }

    int dfs(int i){
        if(i >= m) {return i == m;}
        return dfs(i+1) + dfs(i+2);
    }
};
