class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low=0, same=0, high;
        for(auto n : nums){
            if(n<pivot) low++;
            if(n==pivot) same++;
        }
        high = low+same;
        same = low; low = 0;
        vector<int> res(nums.size());
        for(auto n : nums){
            if(n<pivot) res[low++] = n;
            else if(n==pivot) res[same++] = n;
            else res[high++] = n;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size()); int lo=0, hi=nums.size()-1, n = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<pivot) ans[lo++] = nums[i];
            if(nums[n-i-1]>pivot) ans[hi--] = nums[n-i-1];
        }
        while(lo<=hi) ans[lo++] = ans[hi--] = pivot;
        return ans;
    }
};