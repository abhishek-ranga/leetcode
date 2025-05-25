class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int start=0, end=nums.size()-1;
        for(int i=n-1; i>=0; i--){
            if(abs(nums[start])>=abs(nums[end])) res[i] = nums[start]*nums[start++];
            else res[i] = nums[end]*nums[end--];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            res.push_back(nums[i]*nums[i]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};