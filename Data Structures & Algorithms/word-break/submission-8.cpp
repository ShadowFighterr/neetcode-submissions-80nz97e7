class Solution {
public:
    unordered_map<string, bool> memo;

    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end(),
         [](const string& a, const string& b) {
             return a.size() < b.size();
         });
        return dfs(s, wordDict);
    }

    bool dfs(string s, vector<string>& dict) {
        if (s.empty()) return true;
        if (memo.count(s)) return memo[s];

        for (const string& w : dict) {
            if (w.size() > s.size()) break;
            if (s.compare(0, w.size(), w) == 0) {
                if (dfs(s.substr(w.size()), dict))
                    return memo[s] = true;
            }
        }
        return memo[s] = false;
    }
};
