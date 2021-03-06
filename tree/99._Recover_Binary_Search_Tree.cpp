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
    void recoverTree(TreeNode* root) {
        if (!root) return;
        vector<int> v;
        inorderTraverse(root, v);
        int x = -1, y = -1;
        findSwappedNums(v, x, y);
        updateTree(root, x, y);
    }
private:
    void inorderTraverse(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorderTraverse(root->left, v);
        v.push_back(root->val);
        inorderTraverse(root->right, v);
    }
    void updateTree(TreeNode*& root, int x, int y) {
        if (!root) return;
        if (root->val == x) {
            root->val = y;
        } else if (root->val == y) {
            root->val = x;
        }
        updateTree(root->left, x, y);
        updateTree(root->right, x, y);
    }
//     改变的两数可能相邻也可能不相邻
    void findSwappedNums(vector<int> v, int& x, int& y) {
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v[i] > v[i + 1]) {
                y = v[i + 1];
                if (x == -1) {
                    x = v[i];
                } else {
                    break;
                }
            }
        }
    }
};


class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        
        findSwapTreeNodePointers(root, prev, first, second);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
private:
//     root指针不改变
    void findSwapTreeNodePointers(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if (!root) return;
        findSwapTreeNodePointers(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            second = root;
            if (!first) first = prev;
        }
        prev = root;
        findSwapTreeNodePointers(root->right, prev, first, second);
    }
};

// (第一个网站有误，prev不应等于cur.left)
// https://www.cnblogs.com/anniekim/archive/2013/06/15/morristraversal.html 
// https://zhuanlan.zhihu.com/p/102285533

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
    void recoverTree(TreeNode* root) {
        if (!root) return; 
        TreeNode *first = nullptr, *second = nullptr;
        inorderMorrisTraverse(root, first, second);
        
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
private:
    void inorderMorrisTraverse(TreeNode* root, TreeNode* &first, TreeNode* &second) {
        TreeNode *cur = root;
        TreeNode *prev = nullptr;

        while (cur) {
            auto morrisRight = cur->left;
            if (morrisRight) {
                while(morrisRight->right && morrisRight->right != cur)
                    morrisRight = morrisRight->right;
                if (!(morrisRight->right)) {
                    morrisRight->right = cur;
                    cur = cur->left;
                    // jump out
                    continue;
                }
                // remove brige
                morrisRight->right = nullptr;
            }

            // doSometingInorderTraverse()
            if (prev && prev->val > cur->val) {
                second = cur;
                if (!first) first = prev;
            }
            prev = cur;
            cur = cur->right;
        }
    }
};