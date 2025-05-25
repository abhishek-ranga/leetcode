class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
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
};

class Solution {
public:
    ListNode* getNodeAt(ListNode* head, int idx){
        ListNode* p = head;
        for(int i=0; i<idx; i++) p = p->next;
        return p;
    }
    ListNode* reverseList(ListNode* head) {
        int n=0; ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        int i=0, j=n-1;
        while(i<j){
            ListNode* a = getNodeAt(head,i);
            ListNode* b = getNodeAt(head,j);
            int t = a->val;
            a->val = b->val;
            b->val = t;
            i++; j--;
        }
        return head;
    }
};