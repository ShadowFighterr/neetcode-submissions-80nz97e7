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
    vector<int> v;

    void dfs(TreeNode *node, bool ok){
        if(!node) return;

        v.push_back(node->val);
        dfs(node->left, false);
        dfs(node->right, false);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, 0);
        sort(v.begin(), v.end());
        return v[k-1]; 
    }
};
