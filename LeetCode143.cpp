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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL;
        ListNode* c = new ListNode();
        ListNode *tempC = c, *tempA = a, *tempB = b;
        while(tempA!=NULL && tempB!=NULL){
            tempC->next = tempA;
            tempC = tempC->next;
            tempA = tempA->next;
            tempC->next = tempB;
            tempC = tempC->next;
            tempB = tempB->next;
        }
        tempC->next = NULL;
        head =  c->next;
        return;
    }
};