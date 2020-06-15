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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int l, int r) {
        vector<TreeNode*> ans;
        if (l > r) {
            ans.push_back(NULL);
            return ans;
        }
        
        vector<TreeNode*> l_ans;
        vector<TreeNode*> r_ans;
        for (int i = l; i <= r; ++i) {
            l_ans = helper(l, i - 1);
            r_ans = helper(i + 1, r);
            for (auto la : l_ans) {
                for (auto ra : r_ans) {
                    TreeNode* t = new TreeNode(i);
                    t->left = la;
                    t->right = ra;
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};