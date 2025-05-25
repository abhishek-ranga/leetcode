class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head; int size=0; 
        while(temp){
            temp=temp->next;
            size++;
        }
        if(!head || size<2) return head;
        ListNode* dummy = new ListNode(); dummy->next = head;
        ListNode *prev=dummy, *curr=dummy, *next=dummy;
        while(size>=2){
            curr = prev->next;
            next = curr->next;
            for(int i=1; i<2; i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev=curr;
            size-=2;
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
    ListNode*rever(ListNode*head,int k){
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
    ListNode* swapPairs(ListNode* head) {
        ListNode*temp=head;
        int l=length(head);
        if(l<2) return temp;
        for(int i=0;i<2;i++){
            if(!temp)return head;
            temp=temp->next;
        }
        ListNode* new_head = rever(head, 2);
        head->next = swapPairs(temp);
        return new_head;
    }
};