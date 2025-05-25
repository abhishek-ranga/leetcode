class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* curr = head; ListNode* next = NULL;
        while(curr){
            next = curr->next;
            temp = dummy;
            while(temp->next && temp->next->val<curr->val) temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
            curr = next;
        }
        return dummy->next;
    }
};