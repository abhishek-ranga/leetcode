class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]==target) return true;
            if(nums[lo]==nums[mid] && nums[hi]==nums[mid]) {lo++; hi--;}
            else if(nums[lo]<=nums[mid]){
                if(target>=nums[lo]&&target<nums[mid]) hi = mid-1;
                else lo = mid+1;
            }
            else{
                if(target<=nums[hi]&&target>nums[mid]) lo = mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(auto ele : nums) if(ele==target) return true;
        return false;
    }
};