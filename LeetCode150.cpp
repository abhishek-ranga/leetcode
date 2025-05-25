class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        for(int i=0; i<t.size(); i++){
            if(t[i]!="+"&&t[i]!="-"&&t[i]!="*"&&t[i]!="/") st.push(stoi(t[i]));
            else{
                if(t[i]=="+"){
                    int n = st.top(); st.pop();
                    int m = st.top(); st.pop();
                    st.push(m+n);
                }
                if(t[i]=="-"){
                    int n = st.top(); st.pop();
                    int m = st.top(); st.pop();
                    st.push(m-n);
                }if(t[i]=="*"){
                    int n = st.top(); st.pop();
                    int m = st.top(); st.pop();
                    st.push(m*n);
                }if(t[i]=="/"){
                    int n = st.top(); st.pop();
                    int m = st.top(); st.pop();
                    st.push(m/n);
                }
            }
        }
        return st.top();
    }
};