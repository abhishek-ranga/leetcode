class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, sum=0, len=0, minLen=INT_MAX, n=nums.size();
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len = j-i+1;
                minLen = min(minLen,len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX) return 0;
        return minLen;
    } 
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // brute force
        int minLen = n+1;
        for(int i=0; i<n; i++){
            int currSum = 0;
            for(int j=i; j<n; j++){
                currSum += nums[j];
                if(currSum>=target){
                    minLen = min(minLen,j-i+1);
                    break;
                } 
            }
            
        }
        if(minLen==n+1) return 0;
        return minLen;
    } 
};