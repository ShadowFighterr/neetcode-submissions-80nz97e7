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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root) return vec;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> l;
            int s = q.size();
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    l.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            
            if(!l.empty()) vec.push_back(l);
        }
        return vec;
    }
};
