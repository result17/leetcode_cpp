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
        vector<vector<int>> ans;
        if (!root) return ans;
        dfs(root, ans, 0);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<vector<int>> &ans, int depth) {
        if (!root) return;
        if (depth == ans.size()) ans.emplace_back();
        ans[depth].push_back(root->val);
        dfs(root->left, ans, depth + 1);
        dfs(root->right, ans, depth + 1);
    }
};