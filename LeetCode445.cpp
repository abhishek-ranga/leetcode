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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverseList(l1); ListNode* temp2 = reverseList(l2);
        ListNode* dummy = new ListNode(0); ListNode* temp = dummy;
        int carry = 0;
        while(temp1!=NULL || temp2!=NULL || carry!=0){
            int digit1 = (temp1!=NULL) ? temp1->val : 0;
            int digit2 = (temp2!=NULL) ? temp2->val : 0;
            int sum = digit1 + digit2 + carry;
            int toPut = sum%10;
            carry = sum/10;
            ListNode* put = new ListNode(toPut);
            temp->next = put;
            temp = temp->next;
            temp1 = (temp1!=NULL) ? temp1->next : nullptr;
            temp2 = (temp2!=NULL) ? temp2->next : nullptr;
        }
        ListNode* ans = reverseList(dummy->next);
        return ans;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1; ListNode*temp2=l2;
        stack<int>st1; stack<int>st2;
        while(temp1){
            st1.push(temp1->val);
            temp1=temp1->next;
        }
        while(temp2){
            st2.push(temp2->val);
            temp2=temp2->next;
        }
        int carry=0;
        ListNode*new_head=nullptr;
        while(!st1.empty() || !st2.empty() || carry!=0){
            int sum=carry;
            if(!st1.empty()){
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
            }
            carry=sum/10;
            sum%=10;
            ListNode*newnode=new ListNode(sum);
            newnode->next=new_head;
            new_head=newnode;
        }
        return new_head;
    }
};