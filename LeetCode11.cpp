class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int water = -1;
        while(i<j){
            int current = min(height[i],height[j])*(j-i);
            if(current>water) water = current;
            if(height[i]<height[j]) i++;
            else j--;
        }
        return water;
    }
};