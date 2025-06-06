class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,mx=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                mx = max(mx,j-i);
                j++;
            }
            else i++;
        }
        return mx;
    }
};