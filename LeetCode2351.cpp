class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> ch(26);
        for(int i=0; i<s.length(); i++){
            if(ch[s[i]-97]==0) ch[s[i]-97] = 1;
            else if(ch[s[i]-97]==1){
                ch[s[i]-97] = 2;
                return s[i];
            }
        }
        return ' ';
    }
};