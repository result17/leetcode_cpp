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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> nodeCount;
        vector<double> nodeAvg;
        dfs(root, nodeCount, nodeAvg, 0);
        vector<int> ans;
        for (int i = 0; i < nodeCount.size(); ++i) {
            nodeAvg[i] /= nodeCount[i];
        }
        return nodeAvg;
    }
private:
    void dfs(TreeNode* root, vector<int> &nodeCount, vector<double> &nodeAvg, int depth) {
        if (!root) return;
        if (depth == nodeCount.size()) {
            nodeCount.emplace_back();
            nodeAvg.emplace_back();
        }
        nodeCount[depth]++;
        nodeAvg[depth] += root->val;
        dfs(root->left, nodeCount, nodeAvg, depth + 1);
        dfs(root->right, nodeCount, nodeAvg, depth + 1);
    }
};