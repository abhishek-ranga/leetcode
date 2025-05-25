class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(); ListNode* even = new ListNode();
        ListNode* tempOdd = odd; ListNode* tempEven = even;
        ListNode* temp = head; int index=1;
        while(temp!=NULL){
            if(index%2!=0){
                tempOdd->next = temp;
                tempOdd = tempOdd->next;
            }
            else{
                tempEven->next = temp;
                tempEven = tempEven->next;
            }
            temp = temp->next;
            index++;
        }
        tempOdd->next=even->next;
        tempEven->next=NULL;
        return odd->next;
    }
};