class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lowercase(26), uppercase(26);
        for(int i=0; i<s.length(); i++){
            if(s[i]>=65 && s[i]<=90) uppercase[s[i]-65]++;
            if(s[i]>=97 && s[i]<=122) lowercase[s[i]-97]++;
        }
        int count=0, singleOccurence=0;
        for(int i=0; i<26; i++){
            if(lowercase[i]%2==0) count+=lowercase[i];
            else {count+=lowercase[i]-1; singleOccurence=1;}
            if(uppercase[i]%2==0) count+=uppercase[i];
            else {count+=uppercase[i]-1; singleOccurence=1;}
        }
        return singleOccurence==1 ? count+singleOccurence : count;
    }
};