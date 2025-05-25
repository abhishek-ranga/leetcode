// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1;
        int j=n;
        while(i<=j){
            if(i==j) return i;
            int mid = i + (j-i)/2;
            if(isBadVersion(mid)) j=mid;
            else i = mid+1;
        }
        return 0;
    }
};