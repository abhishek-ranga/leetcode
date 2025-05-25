class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool flag = true;
        int check = -1;
        for(int i=0; i<s.length(); i++){
            bool found = false;
            for(int j=0; j<t.length(); j++){
                if(t[j]==s[i] && j>check){
                    check = j;
                    found = true;
                    break;
                } 
            }
            if(found==false) return false;
        }
        return flag;
    }
};