class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i]==nums[i+1]) i+=2;
            else{
                res.push_back(nums[i++]);
                if(res.size()==2) return res;
            }
        }
        res.push_back(nums[nums.size()-1]);
        return res;
    }
};