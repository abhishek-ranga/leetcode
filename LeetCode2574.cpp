class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum;
        int runningsum = 0;
        for(int i=0;i<nums.size();i++){
            leftsum.push_back(runningsum);
            runningsum+=nums[i];
        }
        // totalsum = running sum after this loop ends.
        vector<int> rightsum;
        for(int i=0;i<nums.size();i++){
            runningsum-=nums[i];
            rightsum.push_back(runningsum);
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(leftsum[i]-rightsum[i]));
        }
        return ans;
    }
};