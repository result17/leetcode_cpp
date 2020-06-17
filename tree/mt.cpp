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