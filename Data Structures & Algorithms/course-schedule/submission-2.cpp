class Solution {
public:
    vector<int> state;
    vector<vector<int>> vec;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vec.assign(numCourses, {});
        state.assign(numCourses, 0);
        for(vector<int>& v : prerequisites){
            vec[v[0]].push_back(v[1]);
        }
        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0){
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
    bool dfs(int v){
        if(state[v] == 1) return false;
        if(state[v] == 2) return true;
        state[v] = 1;
        for (int u : vec[v]) {
            if (!dfs(u)) return false;
        }
        state[v] = 2;
        return true; 
    }
};