class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        string a = "";
        for(int i=0; i<k; i++){
            a+=s[i];
        }
        int n = stoi(a), count=0;
        if(n!=0 && num%n==0) count++;
        int j=k;
        while(j<s.length()){
            a = a.substr(1) + s[j];
            n = stoi(a);
            if(n!=0 && num%n==0) count++;
            j++;
        }
        return count;
    }
};