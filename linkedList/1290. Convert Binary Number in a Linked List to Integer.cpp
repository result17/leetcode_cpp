/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        return helper(head, 0);
    }
private: 
    int helper(ListNode* node, int val) {
        if (!node) return 0;
        val = val * 2 + node->val;
        if (!node->next) return val;
        return helper(node->next, val);
    }
};