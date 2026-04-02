class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> path;
        map<string, vector<string>> graph;
        for(auto &v : tickets){
            graph[v[0]].push_back(v[1]);
            sort(graph[v[0]].begin(), graph[v[0]].end());
        }

        dfs("JFK", path, graph);
        reverse(path.begin(), path.end());
        return path;
    }

    void dfs(string u, vector<string>& path, map<string, vector<string>>& graph){
        while(!graph[u].empty()){
            string v = graph[u][0];
            graph[u].erase(graph[u].begin());
            dfs(v, path, graph);
        }
        path.push_back(u);
    }
};
