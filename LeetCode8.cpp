class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        double ans = 0;
        int i = 0;
        while(s[i]==' ') i++;
        bool flag = true;
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='+') flag = true;
            if(s[i]=='-') flag = false;
            i++;
        }
        while(s[i]>=48 && s[i]<=57 && i<n){
            ans*=10;
            ans+=(int)s[i]-48;
            i++;
        }
        if(flag==false) ans*=(-1);
        if(ans>INT_MAX) ans = INT_MAX;
        if(ans<INT_MIN) ans = INT_MIN;
        return (int)ans;
    }
};