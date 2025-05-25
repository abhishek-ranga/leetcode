class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA; ListNode* temp2 = headB;
        int sizeA=0, sizeB=0;
        while(temp1!=NULL){
            sizeA++;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            sizeB++;
            temp2 = temp2->next;
        }
        int difference = abs(sizeA-sizeB);
        temp1 = headA; temp2 = headB;
        if(sizeA>sizeB){
            for(int i=0; i<difference; i++) temp1 = temp1->next;
        }
        else for(int i=0; i<difference; i++) temp2 = temp2->next;
        for(int i=0; i<min(sizeA,sizeB); i++){
            if(temp1==temp2) return temp1;
            else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA; ListNode* temp2;
        while(temp1!=NULL){
            temp2 = headB;
            while(temp2!=NULL){
                if(temp1==temp2) return temp1;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return nullptr;
    }
};