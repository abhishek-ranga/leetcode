class Solution {
public:
    bool check(vector<int>& nums) {
        int pivotcheck = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]) continue;
            else pivotcheck++;
        }
        
        if(pivotcheck==0) return true;
        if(pivotcheck==1){
            if(nums[nums.size()-1]<=nums[0]) return true;
        }
        return false;
    }
};