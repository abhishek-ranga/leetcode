// brute force/ all testcases cleared but unaccepted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i=0; i<numbers.size()-1; i++){
            for(int j=i+1; j<numbers.size(); j++){
                if((numbers[i]+numbers[j])==target){
                    res.push_back(i+1);
                    res.push_back(j+1);
                    return res;
                }
            }
        }
        return res;
    }
};
// optimised/ accepted
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int lo = 0, hi = nums.size()-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]==target){
                res.push_back(lo+1);
                res.push_back(hi+1);
                return res;
            }
            if(nums[lo]+nums[hi]<target) lo++;
            if(nums[lo]+nums[hi]>target) hi--;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int lo = 0, hi = nums.size()-1;
        while(lo<hi){
            if(nums[lo]+nums[hi]==target){
                res.push_back(lo+1);
                res.push_back(hi+1);
                return res;
            }
            else if(nums[lo]+nums[hi]<target) lo++;
            else hi--;
        }
        return res;
    }
};