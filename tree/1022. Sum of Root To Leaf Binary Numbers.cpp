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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* root, int val) {
        // 非叶节点舍去
        if (!root) return 0;
        val = 2 * val + root->val;
        if (!root->left && !root->right) return val;
        return dfs(root->left, val) + dfs(root->right, val);
    }
};