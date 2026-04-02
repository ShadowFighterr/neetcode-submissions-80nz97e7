class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            bool r[10], c[10];
            for(int x = 0; x < 10; x++) r[x] = false, c[x] = false;
            // memset(r, false, sizeof(r));
            // memset(c, false, sizeof(c));
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j]!='.' && r[(board[i][j]-'0')]) return false;
                else if(board[i][j]!='.') r[(board[i][j]-'0')] = true;
                if(board[j][i]!='.' && c[(board[j][i]-'0')]) return false;
                else if(board[j][i]!='.') c[(board[j][i]-'0')] = true;
            }
        }
        for(int i = 0; i < 9; i+=3)
        {
            for(int j = 0; j < 9; j+=3)
            {
                bool s[10];
                for(int x = 0; x < 10; x++) s[x] = false;
                // memset(s, false, sizeof(s));
                for(int u = j; u < j+3; u++)
                {
                    for(int v = i; v < i+3; v++)
                    {
                        if(board[u][v] != '.' && s[(board[u][v] -'0')]) return false;
                        else if(board[u][v] != '.') s[(board[u][v] -'0')] = true;
                    }
                }
            }
        }
        return true;
    }
};
