class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<bool> uppercase(26), lowercase(26);
        int count=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]>=65 && s[i]<=90) uppercase[s[i]-65]=1;
            if(s[i]>=97 && s[i]<=122) lowercase[s[i]-97]=1;
        }
        for(int i=0; i<26; i++) if(lowercase[i]==1 && uppercase[i]==1) count++;
        return count;
    }
};