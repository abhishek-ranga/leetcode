class Solution {
public:
    int secondsToRemoveOccurrences(string nums) {
        int count=0, n=nums.size();
        bool flag = true;
        while(flag){
            int swaps=0;
            for(int i=0; i<n-1; i++){
                if(nums[i]=='0' && nums[i+1]=='1'){
                    swap(nums[i],nums[i+1]);
                    swaps++;
                    i++;
                } 
            }
            if(swaps==0) flag=false;
            else count++;
        }
        return count;
    }
};