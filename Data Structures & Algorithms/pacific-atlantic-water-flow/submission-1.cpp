class Solution {
public:
    set<vector<int>> s;
    int n, m;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>> v(n, vector<bool> (m, false));
        vector<vector<bool>> v1(n, vector<bool> (m, false));
        vector<vector<int>> vec;
        
        for(int i = 0; i < n; i++) dfs(heights, i, 0, -1, v);
        for(int i = 0; i < m; i++) dfs(heights, 0, i, -1, v);
        
        for(int i = 0; i < n; i++) dfs(heights, i, m-1, -1, v1);
        for(int i = 0; i < m; i++) dfs(heights, n-1, i, -1, v1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << v[i][j] << " \n"[j+1 == m];
            }
        }
        
        cout << '\n';

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << v1[i][j] << " \n"[j+1 == m];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] && v1[i][j]) vec.push_back({i, j});
            }
        }
        return vec;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<bool>>& visited){
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] < prev) return;
        visited[i][j] = true;
        dfs(grid, i+1, j, grid[i][j], visited);
        dfs(grid, i-1, j, grid[i][j], visited);
        dfs(grid, i, j+1, grid[i][j], visited);
        dfs(grid, i, j-1, grid[i][j], visited);
    }
};