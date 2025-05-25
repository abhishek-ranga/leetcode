class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto num : stones) pq.push(num);
        while(!pq.empty()){
            if(pq.size()==1) return pq.top();
            int mx1 = pq.top(); pq.pop();
            int mx2 = pq.top(); pq.pop();
            if(mx1!=mx2) pq.push(mx1-mx2);
        }
        return 0;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int i=stones.size()-1;
        while(stones.size()!=1 && i>=1){
            if(stones[i]==stones[i-1]){stones.pop_back(),stones.pop_back();}
            else {
                stones[i-1]=stones[i]-stones[i-1];
                stones.pop_back();
                sort(stones.begin(),stones.end());
            }
            i=stones.size()-1;
        }
        if(stones.size()==0) stones.push_back(0);
        return stones[0];
    }
};