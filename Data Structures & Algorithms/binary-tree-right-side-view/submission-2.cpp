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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            int sz = dq.size();
            v.push_back(dq.back()->val);
            while(sz--){
                TreeNode* node = dq.front();
                dq.pop_front();
                if(node->left) dq.push_back(node->left);
                if(node->right) dq.push_back(node->right);
            }
        }
        return v;
    }
};
