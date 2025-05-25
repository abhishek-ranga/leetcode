class Solution {
public:
    bool isAVowel(char ch){
        if(ch=='a') return true;
        if(ch=='e') return true;
        if(ch=='i') return true;
        if(ch=='o') return true;
        if(ch=='u') return true;
        if(ch=='A') return true;
        if(ch=='E') return true;
        if(ch=='I') return true;
        if(ch=='O') return true;
        if(ch=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(not(isAVowel(s[i]))) i++;
            if(not(isAVowel(s[j]))) j--;
            if(isAVowel(s[i])&&isAVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            } 
        }
        return s;
    }
};