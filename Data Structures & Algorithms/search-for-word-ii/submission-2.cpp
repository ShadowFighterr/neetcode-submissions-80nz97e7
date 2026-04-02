class TrieNode{
public:
    TrieNode* children[26];
    int idx;
    int refs;

    TrieNode(){
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        idx = -1;
        refs = 0;
    }

    void addWord(const string& word, int i){
        TrieNode* cur = this;
        cur->refs++;
        for(char c : word){
            int index = c - 'a';
            if(!cur->children[index]){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
            cur->refs++;
        }
        cur->idx = i;
    }
};

class Solution {
public:
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode * root = new TrieNode();
        for(int i = 0; i < words.size(); i++) root->addWord(words[i], i);

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++) 
                dfs(board, root, i, j, words);

        return res;
    }

    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j, vector<string>& words){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() 
        || board[i][j] == '*' || !node->children[board[i][j] - 'a']) return;

        char temp = board[i][j];
        board[i][j] = '*';
        TrieNode* prev = node;
        node = node->children[temp - 'a'];

        if(node->idx != -1){
            res.push_back(words[node->idx]);
            node->idx = -1;  
            node->refs--;
            if(node->refs == 0){
                prev->children[temp - 'a'] = nullptr; 
            }
        }

        dfs(board, node, i + 1, j, words);
        dfs(board, node, i - 1, j, words);
        dfs(board, node, i, j + 1, words);
        dfs(board, node, i, j - 1, words);

        board[i][j] = temp;  
    }
};
