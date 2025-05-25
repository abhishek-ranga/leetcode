class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; int size=0; 
        while(temp){
            temp=temp->next;
            size++;
        }
        if(!head || size<k) return head;
        ListNode* dummy = new ListNode(); dummy->next = head;
        ListNode *prev=dummy, *curr=dummy, *next=dummy;
        while(size>=k){
            curr = prev->next;
            next = curr->next;
            for(int i=1; i<k; i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev=curr;
            size-=k;
        }
        return dummy->next;
    }
};

class Solution {
public:
    int length(ListNode*head){
        int count=0;
        ListNode*temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode*reverse(ListNode*head,int k){
        ListNode*prev=NULL;
        ListNode*curr=head;
        int count=0;
        while (curr && count < k){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            count++;
        }
        head->next = curr;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        int l=length(head);
        if(l<k) return temp;
        for(int i=0;i<k;i++){
            if(!temp)return head;
            temp=temp->next;
        }
        ListNode* new_head = reverse(head, k);
        head->next = reverseKGroup(temp, k);
        return new_head;
    }
};