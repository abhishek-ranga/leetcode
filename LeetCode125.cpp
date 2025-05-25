class Solution {
public:
    bool isPalindrome(string s) {
        string helper = "";
        for(int i=0; i<s.length(); i++){
            if(int(s[i])>=97 && int(s[i])<=122) helper.push_back(s[i]);
            if(int(s[i])>=48 && int(s[i])<=57) helper.push_back(s[i]);
            if(int(s[i])>=65 && int(s[i])<=90) helper.push_back(char(int(s[i])+32));
        }
        int i=0;
        int j = helper.length()-1;
        while(i<=j){
            if(helper[i]!=helper[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};