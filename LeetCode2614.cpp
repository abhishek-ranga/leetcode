class Solution {
public:
    int isPrime(int n){
        if(n<=1) return 0;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0) return 0;
        }
        return 1;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int mx = INT_MIN, n=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(isPrime(nums[i][i])) mx = max(mx,nums[i][i]);
            if(isPrime(nums[i][n-i-1])) mx = max(mx,nums[i][n-i-1]);
        }
        return mx == INT_MIN ? 0 : mx;
    }
};