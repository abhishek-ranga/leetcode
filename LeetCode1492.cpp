class Solution {
public:
    int kthFactor(int n, int k) {
        int factors=0; vector<int> fact(k,-1);
        for(int i=1; i<=n; i++){
            if(n%i==0) fact[factors++] = i;
            if(factors==k) break;
        }
        return fact[k-1];
    }
};