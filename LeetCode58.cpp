class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.length()-1;
        int ans = 0;
        while(j>=0 && s[j]==' '){
            j--;
        } 
        while(j>=0 && s[j]!=' '){
            ans++;
            j--;
        }
        return ans;
    }
};