class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head; ListNode* slow = head; ListNode* t = head;
        bool flag = false; // no cycle
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                flag = true;
                break;
            }
        }
        if(flag==false) return nullptr;
        while(t!=slow){
            slow = slow->next;
            t = t->next;
        }
        return t;
    }
};