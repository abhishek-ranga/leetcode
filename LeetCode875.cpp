class Solution {
public:
    bool check(int speed, vector<int>& piles, int h){
        long long count = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            if(count>h) return false;
            if(speed>=piles[i]) count++;
            else if(piles[i]%speed==0) count+=(piles[i]/speed); // piles[i]>speed. piles[i] is strictly greater than speed.
            else count+=((piles[i]/speed)+1); // piles[i]>speed but not perfectly divisible by speed.
        }
        if(count>h) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx = -1;
        for(int i=0;i<n;i++){
            mx = max(mx,piles[i]);
        }
        int low = 1;
        int high = mx;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};