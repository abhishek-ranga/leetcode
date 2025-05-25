// prefix sum
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), windowLength = 2*k+1;
        vector<int> ans(n,-1);
        if(n<windowLength) return ans;
        vector<long> prefix(n+1);
        for(int i=0; i<n; i++) prefix[i+1]=prefix[i]+nums[i];
        for(int i=k; i+k<n; i++) ans[i] = (prefix[i+k+1]-prefix[i-k])/windowLength;
        return ans;
    }
};
// sliding window
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), windowLength = (2*k)+1;
        vector<int> ans(n,-1);
        if(n<windowLength) return ans;
        long sum=0;
        for(int i=0; i<2*k+1; i++){
            sum+=nums[i];
        }
        int pos=k;
        ans[pos++]=sum/windowLength;
        int i=1,j=windowLength;
        while(j<n){
            sum+=nums[j]-nums[i-1];
            ans[pos++]=sum/windowLength;
            i++; j++;
        }
        return ans;
    }
};