class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1, max2, max3;
        max1 = max2 = max3 = LLONG_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i]>max2 && nums[i]!=max1){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i]>max3 && nums[i]!=max2 && nums[i]!=max1){
                max3 = nums[i];
            }
        }
        if(max3==LLONG_MIN) return max1;
        return max3;
    }
};