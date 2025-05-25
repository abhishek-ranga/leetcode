class Solution {
public:
    bool isPowerOfTwo(int n) {
        int lo = 0;
        int hi = n;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(pow(2,mid)==n) return true;
            else if(pow(2,mid)<n) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};