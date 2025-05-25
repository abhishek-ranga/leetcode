class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i]-1;
            if(nums[i]>0){
                if(nums[i]==nums[correctIdx]){
                    if(i==correctIdx) i++;
                    else{
                        ans.push_back(nums[i]);
                        nums[i++] = 0;
                    }
                }
                else swap(nums[i],nums[correctIdx]);
            }
            else i++;
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) ans.push_back(i+1);
        }
        return ans;
    }
};