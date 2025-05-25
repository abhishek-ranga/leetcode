class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, cr = 0;
        for(int i=0; i<nums.size(); i++){
            cr = max(nums[i], cr+nums[i]);
            mx = max(mx,cr);
        }
        return mx;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int maxSum= nums[0];
        int sum=0;
        for(int i=0; i<n; i++){
            sum +=nums[i];
            maxSum = max(maxSum,sum);
            if(sum<0) sum=0;
        }
        return maxSum;
    }
};