class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return NULL;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while(even && even->next){
            //this loop stops when even->next is meaningless
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};