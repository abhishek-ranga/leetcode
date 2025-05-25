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
};

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
    int size(ListNode* head){
        int count=0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right-left+1==size(head)) return reverseList(head);
        if(left==right) return head;
        ListNode* a = new ListNode(); ListNode* temp = head; ListNode* rev = a;
        left; right; int i;
        for(i=0; i<left-1; i++){
            temp = temp->next;
        }
        while(i!=right){
            a->next = temp;
            temp = temp->next;
            a = a->next;
            i++;
        }
        ListNode* connect = a->next;
        a->next = NULL;
        ListNode* list = reverseList(rev->next);
        head->next = list;
        ListNode* tempList = list;
        while(tempList->next!=NULL) tempList = tempList->next;
        tempList->next = connect;
        return head;
    }
};