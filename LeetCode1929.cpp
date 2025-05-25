class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size());
        for(int i=0; i<ans.size(); i++){
            ans[i] = i<nums.size() ? nums[i] : nums[i-nums.size()];
        }
        return ans;
    }
};