class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
        if(nums.size()==1) return nums[0];
        if(nums[lo]<nums[hi]) return nums[lo];
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(lo==hi) return nums[lo];
            else if(nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(nums[mid]<nums[mid-1]) return nums[mid];
            else{
                if(nums[mid]>nums[lo]&&nums[mid]>nums[hi]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return 0;
    }
};