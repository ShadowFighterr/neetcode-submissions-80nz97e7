class Solution {
public:
    int minDistance(string word1, string word2) {
        return dfs(word1, word2, 0, 0);
    }
    int dfs(string& word1, string& word2, int i, int j){
        if(i == word1.size()) return word2.size()-j;
        if(j == word2.size()) return word1.length()-i;
        int res = 0;
        if(word1[i] == word2[j]) res = dfs(word1, word2, i+1, j+1);
        else{
            res = 1+min(dfs(word1, word2, i, j+1), min(dfs(word1, word2, i+1, j),
          dfs(word1, word2, i+1, j+1)));
        }
        return res;
    }
};
