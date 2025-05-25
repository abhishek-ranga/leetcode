class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size(), mx = nums[0];
        vector<long long> conver(n);
        for(int i=0; i<n; i++){
            if(nums[i]>mx) mx=nums[i];
            conver[i]=nums[i]+mx;
            if(i>=1) conver[i]+=conver[i-1];
        }
        return conver;
    }
};