// https://www.bilibili.com/video/BV1z4411r7Db?from=search&seid=15579366976256975950
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        int d = 0;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()) {
            ans.emplace_back();
            while(!st1.empty()) {
                TreeNode* t = st1.top();
                st1.pop();
                ans[d].push_back(t->val);
                if (d % 2) {
                    if (t->right) st2.push(t->right);
                    if (t->left) st2.push(t->left);
                } else {
                    if (t->left) st2.push(t->left);
                    if (t->right) st2.push(t->right);
                }
            }
            d++;
            swap(st1, st2);
        }
        return ans;
    }
};