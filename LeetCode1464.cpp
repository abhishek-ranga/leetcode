class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=INT_MIN,scndmx=INT_MIN;
        for(int num : nums){
            if(num>mx){
                scndmx = mx;
                mx = num;
            }
            else if(num>scndmx) scndmx = num;
        }
        return (mx-1)*(scndmx-1);
    }
};