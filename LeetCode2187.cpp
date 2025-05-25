class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips){
        long long trips = 0;
        long long n = time.size();
        // example
        // 1 2 3 midhours = 2
        for(int i=0;i<n;i++){
            trips += (mid/time[i]);
        }
        if(trips<totalTrips) return false;
        else return true;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n = time.size();
        int mx = -1;
        for(int i=0;i<n;i++){
            mx = max(mx,time[i]);
        }
        long long low = 1;
        long long high = (long long)mx*(long long)totalTrips;
        long long ans = -1;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(mid,time,totalTrips)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};