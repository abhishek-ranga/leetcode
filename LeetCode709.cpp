class Solution {
public:
    string toLowerCase(string s) {
        for(char& ch : s){
            if(ch>='A'&&ch<='Z') ch+=32;
        }
        return s;
    }
};

class Solution {
public:
    string toLowerCase(string s) {
        for(int i=0; i<s.length(); i++){
            if(int(s[i])>=65 && int(s[i])<=90) s[i] = int(s[i])+32;
        }
        return s;
    }
};

class Solution {
public:
    string toLowerCase(string str) {
        for(char& c: str)
            if('A'<=c && c<='Z') c = c-'A'+'a';
        return str;
    }
};