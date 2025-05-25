class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0; stack<int> st;
        while(i<pushed.size() && j<popped.size()){
            st.push(pushed[i]);
            while(!st.empty()&&st.top()==popped[j]){
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};