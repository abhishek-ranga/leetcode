class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums[nums.size()-1];
        vector<int> v(n);
        for(int i=0; i<n; i++) v[i]=i+1;
        v.push_back(n);
        if(nums.size()!=v.size()) return false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=v[i]) return false;
        }
        return true;
    }
};