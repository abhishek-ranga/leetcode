// nlogn
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0; i<t.length(); i++){
            if(t[i]!=s[i]) return t[i];
        }
        return ' ';
    }
};
// n
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sSum = 0;
        int tSum = 0;
        for(int i=0; i<s.length(); i++){
            sSum+=s[i];
        }
        for(int i=0; i<t.length(); i++){
            tSum+=t[i];
        }
        return tSum-sSum;
    }
};