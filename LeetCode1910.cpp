class Solution {
public:
    string removeOccurrences(string s, string part) {
        string t = s; int n = s.length(); int m = part.length(); int j=0;
        for(int i=0; i<n; i++){
            t[j++] = s[i];
            if(j>=m && t.substr(j-m,m)==part) j-=m;
        }
        return t.substr(0,j);
    }
};

class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            st.push(s[i]);
            if(st.size()>=part.length() && st.top()==part.back()){
                string temp = "";
                for(int j=0; j<part.length(); j++){
                    temp = st.top()+temp;
                    st.pop();
                }
                if(temp!=part){
                    for(int k=0; k<temp.length(); k++){
                        st.push(temp[k]);
                    }
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};