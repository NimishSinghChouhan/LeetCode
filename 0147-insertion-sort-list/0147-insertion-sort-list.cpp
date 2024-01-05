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
    void swapValue(ListNode* a, ListNode* b){
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    };
    
    void insert(ListNode* list, ListNode* node){
        ListNode *cur = list, *prev, *tail;
        
        //find in list a node that just larger than node
        while(cur && cur->val <= node->val){
            prev = cur;
            cur = cur->next;
        }
        
        tail = list;
        while(tail->next){
            tail = tail->next;
        }
        
        // tail->next = node->next;
        prev->next = node;
        node->next = cur;
    };
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = new ListNode(INT_MIN);
        ListNode *node, *remaining = head;
        
        while(remaining){
            node = remaining;
            remaining = remaining->next;
            node->next = nullptr;
            insert(newHead, node);
        }
        
        return newHead->next;
    }
};