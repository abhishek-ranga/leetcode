// https://leetcode.com/problems/can-place-flowers/solutions/3317843/java-c-simple-solution-easy-to-understand
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0)){
                flowerbed[i]=1;
                n--;
            }
            if(n==0) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int count = 0;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                // Check if the current position is suitable for placing a flower
                bool canPlace = true;
                
                if (i > 0 && nums[i - 1] == 1) {  
                    canPlace = false;
                }
                if (i < size - 1 && nums[i + 1] == 1) {  
                    canPlace = false;
                }
                
                if (canPlace) {
                    nums[i] = 1;
                    count++;  
                }
            }
            
            // if (count == n) {
            //     return true;  
            // }
        }
        
        return count >= n;
    }
};