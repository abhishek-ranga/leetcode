class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(), n = accounts[0].size();
        int result = INT_MIN;
        for(int i=0; i<m; i++){
            int current = 0;
            for(int j=0; j<n; j++){
                current+=accounts[i][j];
            }
            if(current>result){
                result = current;
            }
        }
        return result;
    }
};