class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0, j=nums.size()-1, mx = 0;
        while(i<j){
            int diff = max(nums[i+1]-nums[i],nums[j]-nums[j-1]);
            mx = max(mx,diff);
            i++; j--;
        }
        return mx;
    }
};