class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto ele : nums){
            int idx = abs(ele);
            if(nums[idx]<0) return idx;
            else nums[idx] = -nums[idx];
        }
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i];
            if(nums[correctIdx]==nums[i]) return nums[i];
            else swap(nums[correctIdx],nums[i]);
        }
        return 0;
    }
};