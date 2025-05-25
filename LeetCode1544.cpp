class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]>=97&&s[i]<=122){
                if(!st.empty() && st.top()-65+97==s[i]) st.pop();
                else st.push(s[i]);
            }
            if(s[i]>=65&&s[i]<=90){
                if(!st.empty() && st.top()-97+65==s[i]) st.pop();
                else st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};