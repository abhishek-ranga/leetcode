class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=']') st.push(s[i]);
            else{
                string t = "";
                while(st.top()!='['){
                    t = st.top()+t;
                    st.pop();
                }
                st.pop();
                string x = "";
                while(!st.empty() && st.top()>=48 && st.top()<=57){
                    x = st.top()+x;
                    st.pop();
                }
                for(int i=0; i<stoi(x); i++){
                    for(int j=0; j<t.length(); j++){
                        st.push(t[j]);
                    }
                }
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