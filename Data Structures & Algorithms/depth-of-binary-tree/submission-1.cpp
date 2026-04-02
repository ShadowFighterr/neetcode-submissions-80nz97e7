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
    int ans = 0;
    void dfs(TreeNode* root, int x)
    {
        if(!root) return;

        ans = max(ans, x);
        dfs(root->left, x+1);
        dfs(root->right, x+1);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return ans+1;
    }
};
