class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;        
        vector<vector<bool>> vis(n, vector<bool> (n, 0));
        pq.push({grid[0][0], 0, 0});
        
        vector<int> dx, dy;
        dx = {1, -1, 0, 0};
        dy = {0, 0, 1, -1};

        while(!pq.empty()){
            auto [l, x, y] = pq.top();
            pq.pop();
            
            if(vis[x][y]) continue;
            vis[x][y] = true;

            if(x == n-1 && y == n-1) return l;

            for(int i = 0; i < 4; i++){
                int nx, ny;
                nx = x+dx[i], ny = y+dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]){
                    pq.push({max(l, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1;
    }

};