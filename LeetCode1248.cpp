class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size(), ans=0;
        int odd=0, count=0;
        while(j<n){
            if(nums[j]%2!=0){
                count=0;
                odd++;
            }
            while(i<=j && odd==k){
                count++;
                if(nums[i++]%2!=0) odd--;
            }
            ans+=count;
            j++;
        }
        return ans;
    }
};