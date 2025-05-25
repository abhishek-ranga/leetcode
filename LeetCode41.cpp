class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1,0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<=n)check[nums[i]] = 1;
        }
        int k;
        for(k=1; k<=n; k++){
            if(check[k]==0) return k;
        }
        return k;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i]<0) i++;
            else if(nums[i]<=0 || nums[i]>n || nums[i]==nums[nums[i]-1]) i++;
            else swap(nums[nums[i]-1],nums[i]);
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};