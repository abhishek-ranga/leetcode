class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int n=nums.size(), flips=0, i=0, j=0, maxLen=INT_MIN, len=INT_MIN;
        while(j<n){
            if(nums[j]==1) j++;
            else{
                if(flips<k){
                    flips++;
                    j++;
                }
                else{
                    len = j-i;
                    maxLen=max(maxLen,len);
                    while(nums[i]!=0)i++;
                    i++;
                    j++;
                }
            }
        }
        len = j-i;
        maxLen=max(maxLen,len);
        return maxLen-1;
    }
};