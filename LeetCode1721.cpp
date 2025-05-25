class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fast=head, *slow=head, *first=head, *second=head;
        for(int i=0; i<k-1; i++) fast = fast->next;
        first = fast;
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        second = slow;
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return head;
    }
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int size = 0;
        ListNode *temp = head, *temp1 = head, *temp2 = head;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        int idx1 = k-1, idx2 = size-k, index=0;
        temp = head;
        while(temp!=NULL){
            if(index==idx1) temp1 = temp;
            if(index==idx2) temp2 = temp;
            temp = temp->next;
            index++;
        }
        int t = temp1->val;
        temp1->val = temp2->val;
        temp2->val = t;
        return head;
    }
};