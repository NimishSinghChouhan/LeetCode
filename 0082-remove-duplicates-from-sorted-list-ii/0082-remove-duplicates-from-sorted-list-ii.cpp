class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        
        dummy->next = head;
        
        ListNode *slow = dummy, *fast = head;
        
        while(fast){
            while(fast && fast->next && fast->val == fast->next->val){
                fast = fast->next;
            }
            
            if(slow->next == fast){
                //fast points to non-duplicate value
                //accept it and move forward
                slow = slow->next;
            }else{
                //fast points to duplicate value
                //so discard it and temporarily connect slow and fast->next
                slow->next = fast->next;
                //move fast forward
                //in next iteration, we still need to check whether fast points to duplicate value
                fast = fast->next;
            }
        }
        
        
        return dummy->next;
    }
};