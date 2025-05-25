class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            int j = i+1;
            int k = nums.size()-1;
            int targetsum = -nums[i];
            while(j<k){
                int currentsum = nums[j]+nums[k];
                if(currentsum>targetsum) k--;
                else if(currentsum<targetsum) j++;
                else{
                    vector<int> myVector = {nums[i],nums[j],nums[k]};
                    res.push_back(myVector);
                    while(nums[j]==myVector[1] && j<k) j++;
                    while(nums[k]==myVector[2] && j<k) k--;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};