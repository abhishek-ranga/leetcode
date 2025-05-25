// https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/3169890/best-c-2-solution-two-pointers-optimized-solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        int i = 0;
        int j = 1;
        for(int ele : nums){
            if(ele>0){
                res[i]=ele;
                i+=2;
            }
            else{
                res[j]=ele;
                j+=2;
            }
        }
        return res;
    }
};