class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int INF = INT_MAX;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) grid[i][j] = -1;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) grid[i][j] = INF;
                if(grid[i][j] == 2) grid[i][j] = 0;
            }
        }

        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            int row, col;
            row = q.front().first;
            col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int r, c;
                r = row+dirs[i][0];
                c = col+dirs[i][1];
                if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != INF) continue;
                grid[r][c] = grid[row][col]+1;
                q.push({r, c});
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == -1) continue;
                if(grid[i][j] == INF) return -1;
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};