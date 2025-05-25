class Solution {
public:
    bool isValid(string s) {
        if(s.length()<2) return false;
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if((s[i]==')'||s[i]=='}'||s[i]==']') && st.size()==0) return false;
            if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);
            else if(s[i]==')'||s[i]=='}'||s[i]==']'){
                char ch = st.top();
                if(s[i]==')' && ch!='(') return false;
                if(s[i]=='}' && ch!='{') return false;
                if(s[i]==']' && ch!='[') return false;
                st.pop();
            }
        }
        return (st.size())==0 ? true : false;
    }
};

class Solution {
public:
    bool isValid(string s) {
        if(s.length()<2) return false;
        vector<char> stack;
        for(int i=0; i<s.length(); i++){
            if((s[i]==')'||s[i]=='}'||s[i]==']') && stack.size()==0) return false;
            if(s[i]=='('||s[i]=='{'||s[i]=='[') stack.push_back(s[i]);
            else if(s[i]==')'||s[i]=='}'||s[i]==']'){
                char ch = stack.back();
                if(s[i]==')' && ch!='(') return false;
                if(s[i]=='}' && ch!='{') return false;
                if(s[i]==']' && ch!='[') return false;
                stack.pop_back();
            }
        }
        return (stack.size())==0 ? true : false;
    }
};