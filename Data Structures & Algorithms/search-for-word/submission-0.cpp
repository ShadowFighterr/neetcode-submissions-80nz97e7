class Solution {
public:
    bool ok = false;

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, word, "");
            }
        }
        return ok;
    }

    void dfs(auto& board, int i, int j, auto& word, string cur){
        if(cur == word) {ok = true; return;}
        if(i < 0 || i >= board.size() || j < 0 
        || j >= board[0].size() || board[i][j] == '*') return;
        char tmp = board[i][j];
        cur+=board[i][j];
        board[i][j] = '*';
        dfs(board, i+1, j, word, cur);
        dfs(board, i-1, j, word, cur);
        dfs(board, i, j+1, word, cur);
        dfs(board, i, j-1, word, cur);
        board[i][j] = tmp;
    }
};
