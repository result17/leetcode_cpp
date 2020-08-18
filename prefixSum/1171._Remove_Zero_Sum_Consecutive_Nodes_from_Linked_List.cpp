class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* root =new ListNode(0);
        root->next=head;
        unordered_map<int,ListNode*>um;
        um[0]=root;
        int ac=0;
        
        while(head!=NULL){
            ac+=head->val;
            
            //found value
            if(um.find(ac)!=um.end()){
                ListNode* prev= um[ac];
                ListNode* start= prev;
                
                //delete bad references
                int aux = ac;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)um.erase(aux);
                }
                
                start->next = head->next;
            }else{
                um[ac]= head;
            }
            
            head=head->next;
        }
        
        return root->next;
    }
};

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
    ListNode* removeZeroSumSublists(ListNode* head) {
    
        if(!head) return head;
        
        int sum = 0;
        ListNode *p = head;
        
        while(p) {
            sum += p->val;
            if (sum == 0) break;
            p = p->next; 
        }
        
        if (sum == 0) head = removeZeroSumSublists(p->next);
        else head->next = removeZeroSumSublists(head->next);

        return head;
    }
};

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* tail = &dummy;
        int sum = 0;
        unordered_map<int, ListNode*> m;
        m[0] = tail;
        while (head) {
            sum += head->val;
            m[sum] = head;
            head = head->next;
        }
        head = tail;
        sum = 0;
        while (head) {
            sum += head->val;
            head->next = m[sum]->next;
            head = head->next;
        }
        return dummy.next;
    }
};

