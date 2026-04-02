class Solution {
public:
    vector<int> state;
    vector<vector<int>> adj;
    bool ok = true;
    bool validTree(int n, vector<vector<int>>& edges) {
        state.resize(n, 0);
        adj.resize(n);
        if(n-1 != edges.size()) return false;
        for(auto& v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(0, -1);
        if(!ok) return false;
        for(int i = 0; i < n; i++){
            if(state[i] == 0) return false;
        }
        return true;
    }

    void dfs(int v, int parent){
        state[v] = 1;
        for(int u : adj[v]){
            if(u == parent) continue;
            if(state[u] == 1) {ok = false; return;}
            if(state[u] == 0) dfs(u, v);
        }
        state[v] = 2;
    }
};
