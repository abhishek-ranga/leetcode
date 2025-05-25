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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode *a=NULL, *b=NULL, *c=NULL, *d=NULL, *temp=head;
        int n=1;
        while(temp!=NULL){
            if(n==left-1) a = temp;
            if(n==left) b = temp;
            if(n==right) c = temp;
            if(n==right+1) d = temp;
            temp = temp->next;
            n++;
        }
        if(a!=NULL) a->next = NULL; c->next = NULL;
        c = reverseList(b);
        if(a!=NULL) a->next = c; b->next = d;
        return a!=NULL ? head : c;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head; int gap=1;
        while(temp && temp->next){
            int remainingLength = 0;
            ListNode* t = temp->next;
            for(int i=0; t!=NULL && i<=gap; i++){
                t = t->next;
                remainingLength++;
            }
            if(remainingLength<gap+1) gap = remainingLength-1;
            if(gap%2!=0)reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=0; temp!=NULL && i<gap; i++) if(temp) temp=temp->next;
        }
        return head;
    }
};