class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = head;
        while(cur!=NULL){
            ListNode* next = cur->next;
            if(cur==head){
                cur->next = NULL;
            }else{
                cur->next = prev;
            }
            prev = cur;
            cur = next;
        }
        return prev;
    }
};