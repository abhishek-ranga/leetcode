class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n+1);
        vector<int> ans(n);
        int common=0;
        for(int i=0; i<n; i++){
            count[A[i]]++;
            if(count[A[i]]==2) common++;
            count[B[i]]++;
            if(count[B[i]]==2) common++;
            ans[i]=common;
        }
        return ans;
    }
};