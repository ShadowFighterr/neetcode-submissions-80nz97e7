class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        dfs(candidates, {}, 0, target);
        sort(res.begin(), res.end());
        set<vector<int>> s;
        for(int i = 0; i < res.size(); i++){
            sort(res[i].begin(), res[i].end());
            s.insert(res[i]);
        }
        res.clear();
        for(auto i : s) res.push_back(i);
        return res;
    }

    void dfs(auto& candidates, vector<int> cur, int idx, int target){
        if(target < 0) return;
        if(target == 0) {res.push_back(cur); return;}

        for(int i = idx; i < candidates.size(); i++){
            if(candidates[i] == -1) continue;
            int x = candidates[i];
            cur.push_back(candidates[i]);
            candidates[i] = -1;
            dfs(candidates, cur, i, target-x);
            cur.pop_back();
            candidates[i] = x;
        }
    }
};
