class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size;
    struct LN {
        int val;
        LN* next;
        LN(int val=0, LN* next=NULL)
            :val(val), next(next){}
    };
    LN *head;
    MyLinkedList() {
        size = 0;
        head = new LN();
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        LN *cur = head->next;
        for (int i = 0; i < index; ++i)
            cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        LN *node = new LN(val);
        LN *prev = head;
        LN *cur = head->next;
        for (int i = 0; i < index; ++i) {
            prev = cur;
            cur = cur->next;    
        }
        prev->next = node;
        node->next = cur;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        LN *prev = head;
        LN *cur = head->next;
        for (int i = 0; i < index; ++i) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
//         delete cur
        delete cur;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */