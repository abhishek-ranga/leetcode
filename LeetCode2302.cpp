class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0, j=0, n=nums.size();
        long long sum=0, ans=0;
        while(j<n){
            sum+=nums[j];
            long long score = sum*(j-i+1);
            while(score>=k){
                sum-=nums[i++];
                score = sum*(j-i+1);
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};