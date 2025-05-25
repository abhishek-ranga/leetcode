class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target&&target<nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else{
                if(nums[mid]<target&&target<=nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        if(n==2){
            if(target==nums[0]) return 0;
            else if(target==nums[1]) return 1;
            else return -1;
        }
        // finding pivot index 
        int pivot = -1; // smallest element;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(mid==0) low = mid+1;
            else if(mid==1) high = mid-1;
            if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1]){
                pivot = mid;
                break;
            }
            else if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                pivot = mid+1;
                break;
            }
            else if(nums[mid]>nums[high]) low = mid+1; // mid ke peechhe wala part discard kar denge
            else high = mid-1; // nums[mid]<nums[high] // mid ke aage wala part discard kar denge
        }
        if(pivot==-1){ // if pivot index was never found that means array was already sorted.
            low = 0;
            high = n-1;
            // normal binary search
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high = mid-1;
                else low = mid+1;
            }
            return -1;
        }
        if(target>nums[0]&&target<nums[pivot]){ // starting se lekar greatest element tak binary search.
            low = 0;
            high = pivot -1;
            // normal binary search
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high = mid-1;
                else low = mid+1;
            }
        }
        else{
            low = pivot;
            high = n-1;
            // normal binary search
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high = mid-1;
                else low = mid+1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(nums[m] == target) return m;
            if(nums[m] >= nums[l]){
                if(target >= nums[l] && target < nums[m] ){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            else{
                if(target >= nums[m] && target <= nums[r] ){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }

            }
            return -1;
    }
};