class Solution {
public:
    int pivotInteger(int n) {
        int nsum = n*(n+1)/2;
        for(int x=n/2; x<=n; x++){
            int xsum = x*(x+1)/2;
            int remainingsum = nsum-xsum+x;
            if(remainingsum==xsum) return x;
        }
        return -1;
    }
};