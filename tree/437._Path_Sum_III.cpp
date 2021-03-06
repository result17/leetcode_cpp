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
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        m[0]++;
        travse(root, 0, sum);
        return ans;
    }
private:
    int ans;
    unordered_map<int, int> m;
    void travse(TreeNode* root, int ps, int sum) {
        if (!root) return;
        ps += root->val;
        if (m.count(ps - sum) != 0) {
            ans += m[ps - sum];
        }
        m[ps]++;
        travse(root->left, ps, sum);
        travse(root->right, ps, sum);
        // 除了左右子树及其后代节点访问不了此节点
        m[ps]--;
    }
};