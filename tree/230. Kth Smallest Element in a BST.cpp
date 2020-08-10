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
    int kthSmallest(TreeNode* root, int k) {
        travse(root, k);
        return ans;
    }
private:
    int ans;
    // 重点是指针k
    void travse(TreeNode* root, int &k) {
        if (!root) return;
        travse(root->left, k);
        if (--k == 0) {
            ans = root->val;
            return;
        }
        travse(root->right, k);
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        travse(root, s, k);
        return ans;
    }
private:
    int ans;
    void travse(TreeNode* root, stack<TreeNode*> s, int k) {
        while (s.size() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode* node = s.top();
                s.pop();
                if (--k == 0) {
                    ans = node->val;
                    return;
                }
                root = node->right;
            }
        }
    }
};