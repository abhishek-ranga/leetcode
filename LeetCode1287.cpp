class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans = arr[0], count = 1;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]==ans) count++;
            else count = 1;
            if(count>arr.size()/4) return arr[i];
            ans=arr[i];
        }
        return ans;
    }
};