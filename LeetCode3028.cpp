class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int count=0;
        for(int i=1; i<nums.size(); i++){
            nums[i]+=nums[i-1];
            if(nums[i]==0) count++;
        } 
        return count;
    }
};

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++) nums[i]+=nums[i-1];
        int count=0;
        for(int i=0; i<nums.size(); i++) if(nums[i]==0) count++;
        return count;
    }
};