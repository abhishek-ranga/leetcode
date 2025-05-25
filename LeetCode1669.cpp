class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1, *temp1, *temp2; int index=0;
        while(temp!=NULL){
            if(index==a-1) temp1 = temp;
            if(index==b+1) temp2 = temp;
            temp = temp->next;
            index++;
        }
        temp1->next = list2;
        temp = list2;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = temp2;
        return list1;
    }
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*left=list1;
        int lcount=0;
        while(lcount<a-1){
            left=left->next;
            lcount++;
        }
        ListNode*right=list1;
        int rcount=0;
        while(rcount<b+1){
            right=right->next;
            rcount++;
        }
        ListNode*temp=list2;
        while(temp->next){
            temp=temp->next;
        }
        left->next=list2;
        temp->next=right;
        return list1;
    }
};