class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            n++;
        }
        vector<ListNode*> ans;
        int size = n/k; int remainder = n%k; // size = partLength
        temp = head;
        while(temp){
            ListNode* c = new ListNode();
            ListNode* tempC = c;
            int s = size;
            if(remainder>0) {s++; remainder--;}
            for(int i=0; i<s; i++){
                tempC->next = temp;
                temp = temp->next;
                tempC = tempC->next;
            }
            tempC->next = NULL;
            ans.push_back(c->next);
        }
        if(ans.size()<k){
            while(ans.size()!=k){
                ListNode* n;
                ans.push_back(n);
            }
        }
        return ans;
    }
};