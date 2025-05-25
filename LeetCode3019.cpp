class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        for(int i=0; i<s.length()-1; i++){
            if(abs(s[i]-s[i+1])==32 || abs(s[i]-s[i+1])==0 ) continue;
            else count++;
        }
        return count;
    }
};