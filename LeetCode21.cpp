class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(); ListNode* temp = c;
        while(a!=NULL&&b!=NULL){
            if(a->val<=b->val){
                temp->next = a;
                a = a->next;
            }
            else{
                temp->next = b;
                b = b->next;
            }
            temp = temp->next;
        }
        if(a==NULL) temp->next = b;
        else temp->next = a;
        return c->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        if(temp1==NULL) return temp2; if(temp2==NULL) return temp1;
        ListNode* temp = new ListNode(); ListNode* Head = temp;
        if(temp1->val<temp2->val){
            temp->val = temp1->val;
            temp1 = temp1->next;
        }
        else{
            temp->val = temp2->val;
            temp2 = temp2->next;
        }
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->val<temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1==NULL) temp->next = temp2;
        else temp->next = temp1;
        return Head;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        ListNode* temp1=head1; ListNode* temp2=head2; ListNode* ptr;
        if( temp1->val<temp2->val ){
            ptr=temp1;
            temp1=temp1->next;
        }
        else{
            ptr=temp2;
            temp2=temp2->next;
        }
        ListNode*new_head=ptr;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                ptr->next=temp1;
                temp1=temp1->next;
            }
            else{
                ptr->next=temp2;
                temp2=temp2->next;
            }
            ptr=ptr->next;
        }
        if(temp1!=NULL) ptr->next=temp1;
        else ptr->next=temp2;
        return new_head;
    }
};