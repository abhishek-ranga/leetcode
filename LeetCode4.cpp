class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            } 
        }
        if(i==m && j<n){
            while(j<n){
                merged.push_back(nums2[j]);
                j++;
            }
        }
        if(j==n && i<m){
            while(i<m){
                merged.push_back(nums1[i]);
                i++;
            }
        }
        int N = merged.size()-1;
        if(N%2==0) return merged[N/2];
        return (merged[N/2]+merged[(N+1)/2])/2.0;
    }
};