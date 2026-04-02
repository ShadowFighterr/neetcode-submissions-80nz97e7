class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool endOfWord;

        TrieNode() : endOfWord(false) {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode *root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * cur = root;
        for(char c : word){
            int i = c - 'a';
            if(cur->children[i] == nullptr) cur->children[i] = new TrieNode(); 
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool check(){

    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int idx, TrieNode* node){
        if(!node) return false;

        if(idx == word.size()) return node->endOfWord;

        char c = word[idx];
        if(c == '.'){
            for(int i = 0; i < 26; i++){
                if(dfs(word, idx+1, node->children[i])) return true;
            }
            return false;
        }
        else{
            int i = c-'a';
            return dfs(word, idx+1, node->children[i]);
        }
    }
};
