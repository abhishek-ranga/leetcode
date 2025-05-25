class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo = new ListNode(); ListNode* hi = new ListNode();
        ListNode* tempLo = lo; ListNode* tempHi = hi;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val<x){
                tempLo->next = temp;
                tempLo = tempLo->next;
            }
            else{ // temp->val>=x
                tempHi->next = temp;
                tempHi = tempHi->next;
            }
            temp = temp->next;
        }
        tempLo->next=hi->next;
        tempHi->next=NULL;
        return lo->next;
    }
};

// wrong method
        // ListNode* a = new ListNode(); ListNode* temp = head; ListNode* ans = a;
        // while(temp!=NULL){
        //     if(temp->val<x){
        //         a->next = temp;
        //         a = a->next;
        //     } 
        //     temp = temp->next;
        // }
        // ListNode* end = temp;
        // temp=head;
        // while(temp!=end){
        //     if(temp->val>=x){
        //         a->next = temp;
        //         a = a->next;
        //     } 
        //     temp = temp->next;
        // }
        // return ans->next;