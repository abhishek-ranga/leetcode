class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head; ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int size=0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        int idx = size/2;
        temp = head;
        int index=0;
        while(index!=idx){
            temp = temp->next;
            index++;
        }
        return temp;
    }
};