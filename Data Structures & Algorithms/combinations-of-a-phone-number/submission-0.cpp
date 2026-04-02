class Solution {
public:
    map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string s = "";
        dfs(digits, s, 0);
        return res;
    }

    void dfs(string& digits, string& s, int idx){
        if(idx == digits.size()) {
            res.push_back(s);
            return;
        }
        string t = mp[digits[idx]];
        for(char c : t){
            string tmp = s;
            s.push_back(c);
            dfs(digits, s, idx+1);
            s.pop_back();
        }
    }
};
