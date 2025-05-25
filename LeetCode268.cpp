class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int actualsum = 0;
        for(int i=0;i<nums.size();i++){
            actualsum+=nums[i];
        }
        return sum-actualsum;
    }
};

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int i;
//         for(i=0;i<nums.size();i++){
//             if(nums[i]!=i) return i;
//         }
//         if(i==nums.size()) return i;
//         else return -1;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<nums.size()){
            int correctIdx = nums[i];
            if(correctIdx==i || nums[i]==n) i++;
            else swap(nums[i],nums[correctIdx]); 
        }
        for(int i=0; i<nums.size(); i++) if(nums[i]!=i) return i;
        return n;
    }
};