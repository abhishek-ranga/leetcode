class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head; ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* a = head;
        ListNode* b = reverseList(slow->next);
        slow->next = NULL;
        int mx = INT_MIN;
        while(a){
            mx = max(mx,a->val+b->val);
            a = a->next;
            b = b->next;
        }
        return mx;
    }
};