class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> vec;
        dfs(vec, s, 0);
        return res;
    }

    void dfs(vector<string>& vec, string &s, int idx){
        if(idx == s.size()) {res.push_back(vec); return;}

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                vec.push_back(s.substr(idx, i-idx+1));
                dfs(vec, s, i+1);
                vec.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};
