class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int> (m, -1));
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix, i, j, -1));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, int prev){
        if(i < 0 || j < 0 || i == n  || j == m || matrix[i][j] == -1 || matrix[i][j] <= prev) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int tmp = matrix[i][j];
        matrix[i][j] = -1;
        int res = 1;
        res = max(res, 1+dfs(matrix, i+1, j, tmp));
        res = max(res, 1+dfs(matrix, i-1, j, tmp));
        res = max(res, 1+dfs(matrix, i, j+1, tmp));
        res = max(res, 1+dfs(matrix, i, j-1, tmp));
        matrix[i][j] = tmp;
        dp[i][j] = res;
        return res;
    }
};
