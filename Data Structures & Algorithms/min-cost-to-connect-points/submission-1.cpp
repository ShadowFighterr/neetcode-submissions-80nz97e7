class DSU{
    public:
        vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({d, i, j});
            }
        }
        
        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int res, count;
        res = count = 0;
        
        for(auto &edge : edges){
            if(dsu.unite(edge[1], edge[2])){
                res+=edge[0];
                count++;
                if(count == n-1) break;
            }
        }
        return res;
    }
};
