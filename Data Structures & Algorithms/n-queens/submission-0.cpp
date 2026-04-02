class Solution {
public:
    vector<vector<string>> res;
    int m;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> vec(n, vector<char>(n, '.'));
        m = n;
        res.reserve(1);
        dfs(vec, 0);
        return res;
    }

    void dfs(vector<vector<char>>& vec, int idx){
        if(!isValid(vec)) return;
        if(idx == m) {
            vector<string> s;
            for(int i = 0; i < m; i++) s.emplace_back(vec[i].begin(), vec[i].end());
            res.push_back(s);
            return;
        }

        for(int x = 0; x < m; x++){
            vec[idx][x] = 'Q';
            dfs(vec, idx+1);
            vec[idx][x] = '.';
        }
    }
// .Q..
// ...Q
// ..Q.
// Q...
    bool isValid(vector<vector<char>>& vec){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(vec[i][j] == 'Q'){
                int x, y;
                x = i, y = j;
                while(x >= 0){
                    --x;
                    if(x < 0) break;
                    if(vec[x][y] == 'Q') return false; 
                }
                x = i;
                while(x >= 0 && y >= 0){
                    --x, --y;
                    if(x < 0 || y < 0) break;
                    if(vec[x][y] == 'Q') return false;
                }
                x = i, y = j;
                while(x >= 0 && y < m){
                    --x, ++y;
                    if(x < 0 || y == m) break;
                    if(vec[x][y] == 'Q') return false;
                } }        
            }
        }
        return true;
    }
};
