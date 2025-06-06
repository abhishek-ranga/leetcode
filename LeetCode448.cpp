class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> check(n+1,0);
        for(int i=0; i<n; i++){
            check[nums[i]] = 1;
        }
        vector<int> res;
        for(int i=1; i<=n; i++){
            if(check[i]==0) res.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            int correctIdx = nums[i]-1;
            if(nums[correctIdx]==nums[i] || correctIdx==i) i++;
            else swap(nums[i],nums[correctIdx]);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};