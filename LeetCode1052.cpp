class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int maxLoss = INT_MIN, idx = 0, loss = 0, n = customers.size();
        for(int i=0; i<k; i++){
            if(grumpy[i]==1) loss+=customers[i];
        }
        maxLoss = loss;
        int start = 1, end = k;
        while(end<n){
            if(grumpy[end]==1) loss += customers[end];
            if(grumpy[start-1]==1)loss -= customers[start-1];
            if(maxLoss<loss){
                maxLoss = loss;
                idx = start;
            }
            start++; end++;
        }
        for(int i=idx; i<idx+k; i++){
            grumpy[i]=0;
        }
        int ans = 0;
        for(int i=0; i<grumpy.size(); i++){
            if(grumpy[i]==0) ans+=customers[i];
        }
        return ans;
    }
};