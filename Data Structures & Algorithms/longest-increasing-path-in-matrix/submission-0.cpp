class Solution {
public:
    int n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
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
        int tmp = matrix[i][j];
        matrix[i][j] = -1;
        int res = 0;
        res = max(res, dfs(matrix, i+1, j, tmp));
        res = max(res, dfs(matrix, i-1, j, tmp));
        res = max(res, dfs(matrix, i, j+1, tmp));
        res = max(res, dfs(matrix, i, j-1, tmp));
        matrix[i][j] = tmp;
        return 1+res;
    }
};
