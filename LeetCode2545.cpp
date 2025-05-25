class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        bool flag = false;
        while(!flag){
            flag = true;
            for(int i=0; i<score.size()-1; i++){
                if(score[i][k]<score[i+1][k]){
                    swap(score[i],score[i+1]);
                    flag = false;
                }
            }
        }
        return score;
    }
};