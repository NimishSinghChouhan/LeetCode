class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode* cur = head;
        int len = 1;
        
        //find tail
        while(cur->next){
            ++len;
            cur = cur->next;
        }
        //now cur is the last node of original list
        
        //connect tail and head
        cur->next = head;
        
        //find the tail of new list
        for(int i = 0; i < len - (k%len); ++i){
            cur = cur->next;
        }
        
        //head of new list is the next node of tail of new list
        head = cur->next;
        cur->next = nullptr;
        
        return head;
    }
};