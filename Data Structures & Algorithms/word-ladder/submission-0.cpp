class Solution {
// private:
//     struct TrieNode {
//         TrieNode* children[26];
//         bool endOfWord;

//         TrieNode() : endOfWord(false) {
//             for (int i = 0; i < 26; i++)
//                 children[i] = nullptr;
//         }
//     };

//     TrieNode *root;
public:
    // Solution(){
    //     root = new TrieNode;
    // }
    const int MAXN = 1e9;
    int ans = MAXN;
    unordered_map<string, bool> visited;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        dfs(wordList, beginWord, endWord, 1);
        return ((ans == MAXN) ? 0 : ans);
    }

    void dfs(vector<string>& words, string s, string t, int cnt){
        if(s == t) {ans = min(ans, cnt); return;}
        for(string word : words){
            if(visited[word]) continue;
            int tmp = 0;
            for(int i = 0; i < word.size(); i++){
                if(word[i] != s[i]) ++tmp;
            }
            if(tmp == 1){
                visited[word] = true;
                dfs(words, word, t, cnt+1);
                visited[word] = false;
            }
        }
    }
};
