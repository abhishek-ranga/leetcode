class Solution {
public:
    void deleteAtTail(ListNode* head){
        ListNode* temp = head;
        while(temp->next->next!=NULL) temp = temp->next;
        temp->next = NULL;
        return;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head;
        if(fast->next==NULL){
            head = head->next;
            return head;
        }
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow->next==NULL) deleteAtTail(head);
        else{
            slow->val = slow->next->val;
            slow->next = slow->next->next;
        }
        return head;
    }
};