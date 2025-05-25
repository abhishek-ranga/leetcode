class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int i=0, j=0, product=1, count=0, n=nums.size();
        while(j<n){
            product*=nums[j];
            while(product>=k){
                count+=(j-i);
                product/=nums[i];
                i++;
            }
            j++;
        }
        while(i<n){
            count+=(j-i);
            product/=nums[i];
            i++;
        }
        return count;
    }
};