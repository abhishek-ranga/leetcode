class Solution {
public:
    void firstoccurence(vector<int>& nums, int target, vector<int>& res){
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                if(mid==0 || nums[mid-1]!=nums[mid]){
                    res[0] = mid;
                    break;
                } 
                else high = mid-1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1; // nums[mid]>target
        }
        return;
    }
    void lastoccurence(vector<int>& nums, int target, vector<int>& res){
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                if(mid==nums.size()-1 || nums[mid+1]!=nums[mid]){
                    res[1] = mid;
                    break;
                } 
                else low = mid+1;
            }
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1; // nums[mid]>target
        }
        return;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        // if(nums.size()==1 && nums[0]==target) return {0,0};
        // else if(nums.size()==1 && nums[0]!=target) return res;
        firstoccurence(nums,target,res);
        lastoccurence(nums,target,res);
        return res;
    }
};