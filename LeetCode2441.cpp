class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(nums[i]*(-1)==nums[j]) return nums[j];
            else if(nums[i]*(-1)>nums[j]) i++;
            else j--;
        }
        return -1;
    }
};

int findMaxK(vector<int>& nums) {
    int arr[2001] = {}, res = -1;
    for (int n : nums) {
        if (arr[-n + 1000])
            res = max(res, abs(n));
        ++arr[n + 1000];        
    }
    return res;
}

class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int low=0, high=nums.size()-1;
        
        while(low < high)
        {
            if((nums[low] + nums[high]) == 0)
            {
                return  nums[high];
            }
            
            else if((nums[low] + nums[high]) < 0)
                low++;
            
            else high--;
        }
        return -1;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            if(abs(nums[i])==nums[j]) return nums[j];
            else if(abs(nums[i])>nums[j]) i++;
            else j--;
        }
        return -1;
    }
};