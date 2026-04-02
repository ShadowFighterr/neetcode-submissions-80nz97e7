/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "n";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if (node) {
                s += to_string(node->val) + ',';
                q.push(node->left);
                q.push(node->right);
            } 
            else s += 'n';
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        cout << s;
        if(s == "n") return nullptr;
        int i = 0;
        while(s[i] != ',' && s[i] != 'n' && i < s.size()) ++i;
        TreeNode* root = new TreeNode(stoi(s.substr(0, i)));
        ++i;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            if(s[i] == ',') ++i;
            if(s[i] != 'n'){
                int j = i;
                while(s[j] != ',' && s[j] != 'n' && j < s.size()) ++j;
                TreeNode* l = new TreeNode(stoi(s.substr(i, j-i)));
                i = j;
                node->left = l;
                q.push(node->left);
            }
            else node->left = nullptr, ++i;
            if(s[i] == ',') ++i;
            if(s[i] != 'n'){
                int j = i;
                while(s[j] != ',' && s[j] != 'n' && j < s.size()) ++j;
                TreeNode* r = new TreeNode(stoi(s.substr(i, j-i)));
                i = j;
                node->right = r;
                q.push(node->right);
            }
            else node->right = nullptr, ++i;
            
        }
        return root;
    }
};
