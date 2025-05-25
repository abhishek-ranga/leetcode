class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end()); int count=0;
        for(int k=nums.size()-1; k>=2; k--){
            int i=0, j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=j-i;
                    j--;
                }
                else i++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end()); int count=0;
        for(int i=0; i<nums.size()-2; i++){
            for(int j=i+1; j<nums.size()-1; j++){
                for(int k=j+1; k<nums.size(); k++){
                    if(nums[i]+nums[j]>nums[k]) count++;
                }
            }
        }
        return count;
    }
};