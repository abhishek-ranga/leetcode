class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), res(n);
        int product = 1;
        for(int i=0; i<nums.size(); i++){
            product*=nums[i];
            pre[i]=product;
        }
        product = 1;
        for(int i=nums.size()-1; i>=0; i--){
            product*=nums[i];
            suf[i]=product;
        }
        product=1;
        for(int i=0; i<nums.size(); i++){
            if(i==0) res[i]=product*suf[i+1];
            else if(i==nums.size()-1) res[i]=pre[i-1]*product;
            else res[i]=pre[i-1]*suf[i+1];
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int> &nums){
//         int n = nums.size();
//         vector<int> pre(n);
//         pre[0] = 1;
//         for(int i=1; i<n; i++){
//             pre[i] = pre[i-1] * nums[i-1];
//         }
//         vector<int> suf(n);
//         suf[n-1] = 1;
//         for(int i=n-2; i>=0; i--){
//             suf[i] = suf[i+1] * nums[i+1];
//         }
//         vector<int> res(n);
//         for(int i=0; i<n; i++){
//             res[i] = pre[i] * suf[i];
//         }
//         return res;
//     }
// };


// #include<bits/stdc++.h>
// using namespace std;
// void printVec(vector<int> &v){
//     for(auto ele : v){
//         cout<<ele<<" ";
//     }
//     cout<<endl;
// }
// vector<int> productExceptSelf(vector<int> &nums){
//     int n = nums.size();
//     vector<int> pre(n);
//     pre[0] = 1;
//     for(int i=1; i<n; i++){
//         pre[i] = pre[i-1] * nums[i-1];
//     }
//     vector<int> suf(n);
//     suf[n-1] = 1;
//     for(int i=n-2; i>=0; i--){
//         suf[i] = suf[i+1] * nums[i+1];
//     }
//     vector<int> res(n);
//     for(int i=0; i<n; i++){
//         res[i] = pre[i] * suf[i];
//     }
//     return res;
// }
// int main(){
//     vector<int> nums = {1,2,3,4};
//     vector<int> res  = productExceptSelf(nums);
//     printVec(res);
//     return 0;
// }