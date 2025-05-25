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
    bool isPalindrome(ListNode* head) {
        ListNode *list1 = head, *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *list2 = reverseList(slow->next);
        slow->next = NULL;
        while(list1!=NULL&&list2!=NULL){
            if(list1->val!=list2->val) return false;
            list1 = list1->next;
            list2 = list2->next;
        }
        return true;
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
    bool isPalindrome(ListNode* head) {
        ListNode* c = new ListNode();
        ListNode* temp = head; ListNode* tempC = c;
        while(temp){
            ListNode* node = new ListNode(temp->val);
            tempC->next = node;
            tempC = tempC->next;
            temp = temp->next;
        }
        c = reverseList(c->next);
        ListNode *a = head, *b = c;
        while(a){
            if(a->val!=b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
};

class Solution {
public:
    ListNode* getNodeAt(ListNode* head, int idx){
        ListNode* p = head;
        for(int i=0; i<idx; i++) p = p->next;
        return p;
    }
    bool isPalindrome(ListNode* head) {
        int n=0; ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        int i=0, j=n-1;
        while(i<j){
            ListNode* a = getNodeAt(head,i);
            ListNode* b = getNodeAt(head,j);
            if(a->val!=b->val) return false;
            i++; j--;
        }
        return true;
    }
};