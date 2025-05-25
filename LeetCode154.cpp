class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for (int val : nums)
        {
            if (min > val)
            {
                min = val;
            }
        }
        return min;
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        if(nums[lo]<nums[hi]) return nums[lo];
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid]>nums[hi]) lo = mid+1;
            else if(nums[mid]<nums[hi]) hi = mid;
            else hi--;
        }
        return nums[lo];
    }
};