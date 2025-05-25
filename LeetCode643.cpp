class Solution {
public:
    double findMaxAverage(vector<int>& nums, float k) {
        int n = nums.size();
        double sum=0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        double maxAverage = sum/k;
        int i=1, j=k;
        while(j<n){
            sum = sum + nums[j] - nums[i-1];
            double currAverage = sum/k;
            maxAverage=max(maxAverage,currAverage);
            i++; j++;
        }
        return maxAverage;
    }
};