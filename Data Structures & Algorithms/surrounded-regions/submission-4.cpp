class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            if(board[i][0] == 'O')dfs(board, i, 0);
            if(board[i][board[0].size()-1] == 'O')dfs(board, i, board[0].size()-1);
        }
        for(int i = 0; i < board[0].size(); i++){
            if(board[0][i] == 'O')dfs(board, 0, i);
            if(board[board.size()-1][i] == 'O')dfs(board, board.size()-1, i);
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }

    vector<vector<int>> dirs = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 'O') return;
        grid[i][j] = 'S';
        for(int k = 0; k < 4; k++){
            int r, c;
            r = i+dirs[k][0];
            c = j+dirs[k][1];
            dfs(grid, r, c);
        }
    }
};
