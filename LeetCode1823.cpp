class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++) q.push(i);
        while(q.size()>1){
            for(int i=1; i<k; i++){
                q.push(q.front());
                q.pop();
            } 
            q.pop();
        }
        return q.front();
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> q(n);
        for(int i=1; i<=n; i++) q[i-1] = i;
        int i=0;
        while(true){
            if(q.size()==1) return q.back();
            i = (i+k-1)%q.size();
            q.erase(q.begin()+i);
        }
        return q[0];
    }
};