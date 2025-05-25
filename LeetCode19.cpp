class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head; ListNode* fast = head;
        // traverse fast to (n+1) steps
        for(int i=0; i<=n; i++){
            if(fast==NULL) return head->next;
            fast = fast->next;
        }
        // move slow and fast at same pace
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        // now the slow pointer is exactly at left of the nth node from end
        slow->next = slow->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head; int size=0;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        if(n==size){
            head = head->next;
            return head;
        }
        int m = size-n+1;
        int idx = m-1;
        temp = head; int index=0;
        while(index!=idx-1){
            temp = temp->next;
            index++;
        }
        temp->next = temp->next->next;
        return head;
    }
};