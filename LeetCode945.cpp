class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1; i>0; i--){
            if(nums[i]==nums[i-1]){
                nums[i]++;
                count++;
                j = i+1;
                while(j!=nums.size() && nums[i]==nums[j]){
                    nums[i]++;
                    count++;
                    j++;
                }
                sort(nums.begin(),nums.end());
            }
        }
        return count;
    }
};

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                ans += nums[i-1]-nums[i]+1;
                nums[i]= nums[i-1]+1;
            }
        }
        return ans;
    }
};