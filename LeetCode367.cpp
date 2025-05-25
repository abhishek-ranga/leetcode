class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1) return true;
        int lo = 0;
        int hi = num/2;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(mid*mid==num) return true;
            else if(mid*mid<num) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};