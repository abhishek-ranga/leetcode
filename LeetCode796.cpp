class Solution {
public:
    bool helper(string s, string goal, int n){
        if(s==goal) return true;
        else if(n==s.length()) return false;
        else return helper(s.substr(1)+s[0],goal,n+1);
    }
    bool rotateString(string s, string goal) {
        return helper(s,goal,0);
    }
};