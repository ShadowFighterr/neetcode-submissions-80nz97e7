class Solution {
public:
    vector<vector<int>> g;
    vector<int> state;
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        state.resize(numCourses, 0);
        for(vector<int> v : prerequisites){
            g[v[1]].push_back(v[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0 && dfs(i)){
                return {};
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int v){
        if(state[v] == 1) {return true;}
        if(state[v] == 2) {return false;}
        state[v] = 1;
        for(int u : g[v]){
            if(dfs(u)) return true;
        }
        state[v] = 2;
        res.push_back(v);
        return false;
    }
};
