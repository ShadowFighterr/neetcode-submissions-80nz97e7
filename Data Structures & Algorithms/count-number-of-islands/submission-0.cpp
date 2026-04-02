class Solution {
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 
        || c >= grid[0].size() || grid[r][c] == '0') return;

        grid[r][c] = '0';
        for(int k = 0; k < 4; k++){
            dfs(grid, r+d[k][0], c+d[k][1]);
        }
    }
};
