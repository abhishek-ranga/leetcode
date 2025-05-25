class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> answer(score.size());
        unordered_map<int,int> m; priority_queue<int> pq;
        for(int i=0; i<score.size(); i++){
            m[score[i]] = i;
            pq.push(score[i]);
        }
        int i=0;
        while(!pq.empty()){
            i++;
            if(i==1){
                answer[m[pq.top()]] = "Gold Medal";
            }
            else if(i==2){
                answer[m[pq.top()]] = "Silver Medal";
            }
            else if(i==3){
                answer[m[pq.top()]] = "Bronze Medal";
            }
            else{
                answer[m[pq.top()]] = to_string(i);
            }
            pq.pop();
        }
        return answer;
    }
};