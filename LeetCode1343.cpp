class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int t) {
        int sum=0, count=0, n=nums.size();
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        if(sum/k>=t) count++;
        int i=1,j=k;
        while(j<n){
            sum+=nums[j]; sum-=nums[i-1];
            if(sum/k>=t) count++;
            i++; j++;
        }
        return count;
    }
};

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        for(int i=0; i<=arr.size()-k; i++){
            int sum = 0;
            for(int j=i; j<i+k; j++){
                sum+=arr[j];
            }
            if((sum/k)>=threshold) count++;
        }
        return count;
    }
};