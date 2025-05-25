class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long count=0; int n=nums.size(), turn=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1; i>=0; i--){
            if(turn==k) break;
            int num = nums[i]-turn;
            if(num>0){
                count+=num;
            }
            turn++;
        }
        return count;
    }
};

class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        long long count=0, n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<k; i++){
            count+=nums[n-i-1];
            for(int j=0; j<n-i-1; j++){
                if(nums[j]>0) nums[j]--;
                else nums[j]=0;
            }
        }
        return count;
    }
};