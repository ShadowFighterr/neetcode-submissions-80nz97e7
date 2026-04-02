class Solution {
public:
    vector<vector<int>> adj;
    vector<int> state;
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        state.resize(n, 0);
        for(auto &v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(state[i] == 0) {
                ++res;
                dfs(i);
            }
        }
        return res;
    }

    void dfs(int v){
        if(state[v] == 1) return;
        state[v] = 1;
        for(int u : adj[v]){
            if(state[u] == 0) dfs(u);
        }
        state[v] = 2;
    }
};
