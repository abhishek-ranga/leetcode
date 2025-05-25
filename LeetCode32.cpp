class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        if(st.empty()) return s.length();
        int end = s.length(); int maxSubStr = 0;
        while(!st.empty()){
            int start = st.top(); st.pop();
            maxSubStr = max(maxSubStr,end-start-1);
            end = start;
        }
        maxSubStr = max(maxSubStr,end);
        return maxSubStr;
    }
};