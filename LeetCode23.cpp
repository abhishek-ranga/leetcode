class cmp{
    public:
    bool operator()(const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i=0; i<lists.size(); i++) if(lists[i])pq.push(lists[i]);
        ListNode* dummy = new ListNode(); ListNode* ptr = dummy;
        while(!pq.empty()){
            ListNode* curr = pq.top(); pq.pop();
            if(curr->next) pq.push(curr->next);
            ptr->next = curr; ptr = ptr->next;
        }
        return dummy->next;
    }
};

class Solution { // O(nklogk)
public:
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        if(temp1==NULL) return temp2; if(temp2==NULL) return temp1;
        ListNode* temp = new ListNode(); ListNode* Head = temp;
        if(temp1->val<temp2->val){
            temp->val = temp1->val;
            temp1 = temp1->next;
        }
        else{
            temp->val = temp2->val;
            temp2 = temp2->next;
        }
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->val<temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1==NULL) temp->next = temp2;
        else temp->next = temp1;
        return Head;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return nullptr;
        while(arr.size()>1){
            ListNode* a = arr[0];
            arr.erase(arr.begin());
            ListNode* b = arr[0];
            arr.erase(arr.begin());
            ListNode* c = mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};

class Solution { // O(n.k^2)
public:
    ListNode* mergeTwoLists(ListNode* temp1, ListNode* temp2) {
        if(temp1==NULL) return temp2; if(temp2==NULL) return temp1;
        ListNode* temp = new ListNode(); ListNode* Head = temp;
        if(temp1->val<temp2->val){
            temp->val = temp1->val;
            temp1 = temp1->next;
        }
        else{
            temp->val = temp2->val;
            temp2 = temp2->next;
        }
        while(temp1!=NULL&&temp2!=NULL){
            if(temp1->val<temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1==NULL) temp->next = temp2;
        else temp->next = temp1;
        return Head;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return nullptr;
        while(arr.size()>1){
            ListNode* a = arr[arr.size()-1];
            arr.pop_back();
            ListNode* b = arr[arr.size()-1];
            arr.pop_back();
            ListNode* c = mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};