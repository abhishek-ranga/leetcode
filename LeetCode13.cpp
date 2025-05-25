class Solution {
public:
    int value(char symbol){
        if(symbol=='I') return 1;
        if(symbol=='V') return 5;
        if(symbol=='X') return 10;
        if(symbol=='L') return 50;
        if(symbol=='C') return 100;
        if(symbol=='D') return 500;
        if(symbol=='M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        s[s.length()] = '0';
        for(int i=0; i<s.length(); i++){
            if(value(s[i])>=value(s[i+1])) ans+=value(s[i]);
            else{
                // ans+=value(s[i+1]);
                ans-=value(s[i]);
                // i++;
            }
        }
        return ans;
    }
};