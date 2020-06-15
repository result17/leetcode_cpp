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
    int minDepth(TreeNode* root) {
        return minDepthHelp(root);
    }
private:
    int minDepthHelp(TreeNode* root) {
        if(!root) return 0;
        if (!(root->left)) return minDepthHelp(root->right) + 1;
        if (!(root->right)) return minDepthHelp(root->left) + 1;
        return min(minDepthHelp(root->left), minDepthHelp(root->right)) + 1;
    }
};