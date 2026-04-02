class Solution {
public:
    const int INF = INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int r, c;
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int row = r+directions[i][0];
                int col = c+directions[i][1];
                if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] != INF)
                    continue;
                grid[row][col] = grid[r][c]+1;
                q.push({row, col});    
            }
        }
    }

};
