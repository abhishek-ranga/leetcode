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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = reverseList(head); vector<int> ans;
        stack<int> st;
        while(temp){
            while(st.size()!=0 && st.top()<=temp->val) st.pop();
            if(st.size()==0) ans.push_back(0);
            else ans.push_back(st.top());
            st.push(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};