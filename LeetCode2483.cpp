class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n+1); // no. of N before Kth hour
        vector<int> suf(n+1); // no. of Y after and including Kth hour
        pre[0]=0;
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i] + ((customers[i]=='N') ? 1 : 0);
        }
        suf[n]=0;
        for(int i=n-1; i>=0; i--){
            suf[i] = suf[i+1] + ((customers[i]=='Y') ? 1 : 0);
        }
        int minPenalty = INT_MAX;
        for(int i=0; i<=n; i++){
            pre[i]+=suf[i];
            int penalty = pre[i];
            minPenalty = min(minPenalty,penalty);
        }
        for(int i=0; i<=n; i++){
            int penalty = pre[i];
            if(penalty==minPenalty) return i;
        }
        return n;
    }
};

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n+1),suf(n+1);
        int preNpenalty=0;
        pre[0]=0;
        for(int i=1; i<=n; i++){
            pre[i]=preNpenalty;
            if(customers[i]=='N') preNpenalty++;
        }
        int postYpenalty = 0;
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y') postYpenalty++;
            suf[i]=postYpenalty;
        }
        suf[n]=0;
        // final ans at each hour = preNpenalty + postYpenalty
        for(int i=0; i<n; i++){
            pre[i]+=suf[i];
        }
        int mn=INT_MAX;
        int idx = -1;
        int k;
        for(k=0; k<=n; k++){
            if(pre[k]<mn){
                mn=pre[k];
                idx=k;
            }
        }
        return idx;
    }
};

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n+1),suf(n+1);
        int preNpenalty=0;
        pre[0]=0;
        for(int i=1; i<=n; i++){
            pre[i]=preNpenalty;
            if(customers[i]=='N') preNpenalty++;
        }
        int postYpenalty = 0;
        for(int i=n-1; i>=0; i--){
            if(customers[i]=='Y') postYpenalty++;
            suf[i]=postYpenalty;
        }
        suf[n]=0;
        // final ans at each hour = preNpenalty + postYpenalty
        for(int i=0; i<n; i++){
            pre[i]+=suf[i];
        }
        int mn=INT_MAX;
        int idx = -1;
        int k;
        for(k=0; k<n; k++){
            if(pre[k]<mn){
                mn=pre[k];
                idx=k;
            }
        }
        if(idx==n-1&&mn>=1) return n;
        return idx;
    }
};