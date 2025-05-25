class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==k){
                if(mid==0) return 0;
                else if(nums[mid]==nums[mid-1]) hi = mid-1;
                else return mid;
            }
            else if(nums[mid]<k) lo = mid+1;
            else hi = mid-1;
        }
        return lo;
    }
};