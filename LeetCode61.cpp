class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0 || head->next==NULL) return head;
        ListNode* temp1 = head; ListNode* temp2 = head;
        int size = 0;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
            size++;
        }
        size++;
        k = k%size;
        if(k==0) return head;
        int idx = size-k-1, index=0;
        while(index!=idx){
            temp1 = temp1->next;
            index++;
        }
        ListNode* Head = temp1->next;
        temp2->next = head;
        temp1->next = NULL;
        return Head;
    }
};