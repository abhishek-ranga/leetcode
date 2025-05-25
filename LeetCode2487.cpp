class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st; ListNode* temp = head;
        while(temp){
            if(st.size()==0 || temp->val<=st.top()->val) st.push(temp);
            else{
                while(st.size()!=0 && st.top()->val<temp->val) st.pop();
                st.push(temp);
            }
            temp = temp->next;
        }
        ListNode* newHead = st.top();
        st.pop();
        while(st.size()!=0){
            st.top()->next = newHead;
            newHead = st.top();
            st.pop();
        }
        return newHead;
    }
};