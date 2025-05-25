class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); ListNode* temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int digit1 = (l1!=NULL) ? l1->val : 0;
            int digit2 = (l2!=NULL) ? l2->val : 0;
            int sum = digit1 + digit2 + carry;
            int toPut = sum%10;
            carry = sum/10;
            ListNode* put = new ListNode(toPut);
            temp->next = put;
            temp = temp->next;
            l1 = (l1!=NULL) ? l1->next : nullptr;
            l2 = (l2!=NULL) ? l2->next : nullptr;
        }
        return dummy->next;
    }
};