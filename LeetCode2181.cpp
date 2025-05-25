class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next; ListNode* ans = new ListNode();
        ListNode* res = ans; int count=0;
        while(temp){
            if(temp->val==0){
                ListNode* add = new ListNode(count);
                ans->next = add;
                ans = ans->next;
                count = 0;
            }
            else count+=temp->val;
            temp = temp->next;
        }
        return res->next;
    }
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode*left=head;
        ListNode*movable=head;
        while(movable->next!=NULL){
            if(movable->val==0){
                left=movable;
            }
            else{
                left->val+=movable->val;
                left->next=movable->next;
            }
            movable=movable->next;
        }
        left->next=NULL;
        return head; 
    }
};