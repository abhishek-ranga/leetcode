class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0); ListNode* temp = dummy;
        while(head){
            if(head->next && head->val==head->next->val){
                int value = head->val;
                while(head && head->val==value) head = head->next;
            }
            else{
                temp->next = head;
                temp = temp->next;
                head = head->next;
                temp->next = NULL;
            }
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val) 
                    head = head->next;
                temp->next = head->next;
            }
            else temp = temp->next;
            head = head->next;
        }
        return dummy->next;
    }
};