class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                i--;
            } 
        }
        if(nums.size()==2){
            if(nums[0]==nums[1]){
                nums.erase(nums.begin());
            }
        }
        return nums.size();
    }
};