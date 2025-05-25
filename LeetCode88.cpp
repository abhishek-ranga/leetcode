class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = nums1.size()-1;
        if(i==-1){ // there were no initial elements in nums1
            while(j>=0){
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            return;
        }
        if(j==-1){ // there were no initial elements in nums2
            return;
        }
        while(i>=0 && j>=0){ // ideal case
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else{ // nums2[j] > nums1[i];
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            // for remaining elements.
            if(i==-1){ // elements remain in nums2
                while(j>=0){
                    nums1[k] = nums2[j];
                    j--;
                    k--;
                }
            }
            if(j==-1){ // elements remain in nums1
                while(i>=0){
                    nums1[k] = nums1[i];
                    i--;
                    k--;
                }
            }
        }
        return;
    }
};


