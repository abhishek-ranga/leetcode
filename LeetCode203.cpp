class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        while(head!=NULL && head->val==val) head = head->next;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->next->val==val){
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return head;
    }
};