class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int sum = 0;
        int m = mat.size();
        int n = mat[0].size();
        while(sum<m+n-1){
            if(sum%2==0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(i+j==sum)res.push_back(mat[j][i]);
                    }
                }
            }
            if(sum%2!=0){
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(i+j==sum)res.push_back(mat[i][j]);
                    }
                }
            }
            sum++;
        }
        return res;
    }
};