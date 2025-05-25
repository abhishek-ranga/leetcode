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
    int getDecimalValue(ListNode* head) {
        int ans=0, power=0;
        head = reverseList(head);
        while(head){
            ans+=(head->val)*pow(2,power);
            head = head->next; power++;
        }
        return ans;
    }
};