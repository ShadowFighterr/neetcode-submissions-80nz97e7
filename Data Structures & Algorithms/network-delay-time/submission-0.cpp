class Solution {
public:
    const long INF = 1e11;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        long res = 0;
        vector<vector<pair<int, int>>> graph(n+1);
        vector<long> dist(n+1, INF);
        dist[k] = 0;
        
        for(auto &vec : times){
            graph[vec[0]].push_back({vec[1], vec[2]});
        }
        
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;

        pq.push({0, k});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto &[v, w] : graph[u]){
                if(dist[v] > dist[u] + w) dist[v] = dist[u] + w, pq.push({dist[v], v});
            }
        }
        for(int i = 1; i <= n; i++){
            if(dist[i] == INF) return -1;
            res = max(res, dist[i]);
        }

        return res;
    }
};
