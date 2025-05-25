class Solution {
public:
    bool isPowerOfFour(int n) {
        int lo = 0;
        int hi = n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(pow(4,mid)==n) return true;
            else if(pow(4,mid)<n) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};